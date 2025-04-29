#ifndef _util_h_
#define _util_h_

#include "sokol_gfx.h"
#include "config.h"
#include "HandmadeMath.h"

#define PI 3.14159265359
#define DEGREES(radians) ((radians) * 180 / PI)
#define RADIANS(degrees) ((degrees) * PI / 180)
#define ABS(x) ((x) < 0 ? (-(x)) : (x))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SIGN(x) (((x) > 0) - ((x) < 0))

#if DEBUG
    #define LOG(...) printf(__VA_ARGS__)
#else
    #define LOG(...)
#endif

typedef struct {
    unsigned int fps;
    unsigned int frames;
    double since;
} FPS;

int rand_int(int n);
double rand_double();
void update_fps(FPS *fps);

uint32_t gen_buffer(size_t size, float *data);
void del_buffer(uint32_t buffer);
float *malloc_faces(int components, int faces);
uint32_t gen_faces(int components, int faces, float *data);
void flip_image_vertical(unsigned char *data, unsigned int width, unsigned int height);
void load_png_texture_memory_sokol(const char *file_name, sg_image *image, sg_sampler *sampler, const unsigned char* in, size_t insize);
char *tokenize(char *str, const char *delim, char **key);
int char_width(char input);
int string_width(const char *input);
int wrap(const char *input, int max_width, char *output, int max_length);
HMM_Mat4 float16_to_mat4(const float* value);

#endif
