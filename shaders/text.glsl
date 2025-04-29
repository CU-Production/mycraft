@ctype mat4 HMM_Mat4
@ctype vec4 HMM_Vec4
@ctype vec3 HMM_Vec3
@ctype vec2 HMM_Vec2

@vs text_vs
layout(binding=0) uniform text_vs_params {
    mat4 matrix;
};

layout (location = 0) in vec4 position;
layout (location = 1) in vec2 uv;

out vec2 fragment_uv;

void main() {
    gl_Position = matrix * position;
    fragment_uv = uv;
}
@end

@fs text_fs
layout(binding=0) uniform texture2D text_tex;
layout(binding=0) uniform sampler text_smp;
layout(binding=1) uniform text_ps_params {
    int is_sign;
};

in vec2 fragment_uv;
out vec4 fragColor;

void main() {
    vec4 color = texture(sampler2D(text_tex, text_smp), fragment_uv);
    if (is_sign > 0) {
        if (color == vec4(1.0)) {
            discard;
        }
    }
    else {
        color.a = max(color.a, 0.4);
    }
    fragColor = color;
}
@end

@program text text_vs text_fs
