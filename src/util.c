#include <GLFW/glfw3.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "lodepng.h"
#include "matrix.h"
#include "sokol_gfx.h"
#include "util.h"

int rand_int(int n) {
    int result;
    while (n <= (result = rand() / (RAND_MAX / n)));
    return result;
}

double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}

void update_fps(FPS *fps) {
    fps->frames++;
    double now = glfwGetTime();
    double elapsed = now - fps->since;
    if (elapsed >= 1) {
        fps->fps = round(fps->frames / elapsed);
        fps->frames = 0;
        fps->since = now;
    }
}

char *load_file(const char *path) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        fprintf(stderr, "fopen %s failed: %d %s\n", path, errno, strerror(errno));
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int length = ftell(file);
    rewind(file);
    char *data = calloc(length + 1, sizeof(char));
    fread(data, 1, length, file);
    fclose(file);
    return data;
}

uint32_t gen_buffer(size_t size, float *data) {
    if (size == 0) {
        return 0;
    }
    sg_buffer buffer = sg_make_buffer(&(sg_buffer_desc){
        .data = {data, size},
    });;
    if (sg_query_buffer_state(buffer) == SG_RESOURCESTATE_INVALID) {
        // buffer pool is exhausted
        int a = 0;
        a += 1;
    }
    return buffer.id;
}

void del_buffer(uint32_t buffer) {
    if (buffer == 0) return;
    sg_buffer _buffer = {.id = buffer};
    sg_destroy_buffer(_buffer);
}

float *malloc_faces(int components, int faces) {
    return malloc(sizeof(float) * 6 * components * faces);
}

uint32_t gen_faces(int components, int faces, float *data) {
    uint32_t buffer = gen_buffer(
        sizeof(float) * 6 * components * faces, data);
    free(data);
    return buffer;
}

void flip_image_vertical(
    unsigned char *data, unsigned int width, unsigned int height)
{
    unsigned int size = width * height * 4;
    unsigned int stride = sizeof(char) * width * 4;
    unsigned char *new_data = malloc(sizeof(unsigned char) * size);
    for (unsigned int i = 0; i < height; i++) {
        unsigned int j = height - i - 1;
        memcpy(new_data + j * stride, data + i * stride, stride);
    }
    memcpy(data, new_data, size);
    free(new_data);
}

void load_png_texture_memory_sokol(const char *file_name, sg_image *image, sg_sampler *sampler, const unsigned char* in, size_t insize) {
    unsigned int error;
    unsigned char *data;
    unsigned int width, height;
    error = lodepng_decode32(&data, &width, &height, in, insize);
    if (error) {
        fprintf(stderr, "load_png_texture_from_memory %s failed, error %u: %s\n", file_name, error, lodepng_error_text(error));
        exit(1);
    }
    flip_image_vertical(data, width, height);

    sg_image _image = sg_make_image(&(sg_image_desc){
        .width = width,
        .height = height,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .data.subimage[0][0] = {data, width * height * 4},
        .label = file_name
    });

    sg_sampler _sampler = sg_make_sampler(&(sg_sampler_desc){
        .min_filter = SG_FILTER_NEAREST,
        .mag_filter = SG_FILTER_NEAREST,
    });

    image->id = _image.id;
    sampler->id = _sampler.id;

    free(data);
}

char *tokenize(char *str, const char *delim, char **key) {
    char *result;
    if (str == NULL) {
        str = *key;
    }
    str += strspn(str, delim);
    if (*str == '\0') {
        return NULL;
    }
    result = str;
    str += strcspn(str, delim);
    if (*str) {
        *str++ = '\0';
    }
    *key = str;
    return result;
}

int char_width(char input) {
    static const int lookup[128] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        4, 2, 4, 7, 6, 9, 7, 2, 3, 3, 4, 6, 3, 5, 2, 7,
        6, 3, 6, 6, 6, 6, 6, 6, 6, 6, 2, 3, 5, 6, 5, 7,
        8, 6, 6, 6, 6, 6, 6, 6, 6, 4, 6, 6, 5, 8, 8, 6,
        6, 7, 6, 6, 6, 6, 8,10, 8, 6, 6, 3, 6, 3, 6, 6,
        4, 7, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 2, 9, 6, 6,
        6, 6, 6, 6, 5, 6, 6, 6, 6, 6, 6, 4, 2, 5, 7, 0
    };
    return lookup[input];
}

int string_width(const char *input) {
    int result = 0;
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        result += char_width(input[i]);
    }
    return result;
}

int wrap(const char *input, int max_width, char *output, int max_length) {
    *output = '\0';
    char *text = malloc(sizeof(char) * (strlen(input) + 1));
    strcpy(text, input);
    int space_width = char_width(' ');
    int line_number = 0;
    char *key1, *key2;
    char *line = tokenize(text, "\r\n", &key1);
    while (line) {
        int line_width = 0;
        char *token = tokenize(line, " ", &key2);
        while (token) {
            int token_width = string_width(token);
            if (line_width) {
                if (line_width + token_width > max_width) {
                    line_width = 0;
                    line_number++;
                    strncat(output, "\n", max_length - strlen(output) - 1);
                }
                else {
                    strncat(output, " ", max_length - strlen(output) - 1);
                }
            }
            strncat(output, token, max_length - strlen(output) - 1);
            line_width += token_width + space_width;
            token = tokenize(NULL, " ", &key2);
        }
        line_number++;
        strncat(output, "\n", max_length - strlen(output) - 1);
        line = tokenize(NULL, "\r\n", &key1);
    }
    free(text);
    return line_number;
}

HMM_Mat4 float16_to_mat4(const float* value) {
    HMM_Mat4 result = {0};
    float* result_addr = (float*)&result;
    for (int i = 0; i < 16; i++) {
        result_addr[i] = value[i];
    }
    return result;
}
