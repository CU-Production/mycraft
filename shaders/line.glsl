@ctype mat4  HMM_Mat4
@ctype vec4  HMM_Vec4
@ctype vec3  HMM_Vec3
@ctype vec2  HMM_Vec2

@vs line_vs
layout(binding=0) uniform line_vs_params {
    mat4 matrix;
};

layout (location = 0) in vec4 position;

void main() {
    gl_Position = matrix * position;
}
@end

@fs line_fs
out vec4 fragColor;

void main() {
    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
}
@end

@program line line_vs line_fs
