@ctype mat4  HMM_Mat4
@ctype vec4  HMM_Vec4
@ctype vec3  HMM_Vec3
@ctype vec2  HMM_Vec2

@vs sky_vs
layout(binding=0) uniform sky_vs_params {
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

@fs sky_fs
layout(binding=0) uniform texture2D sky_tex;
layout(binding=0) uniform sampler sky_smp;
layout(binding=1) uniform sky_ps_params {
    float timer;
};

in vec2 fragment_uv;
out vec4 fragColor;

void main() {
    vec2 uv = vec2(timer.x, fragment_uv.t);
    fragColor = texture(sampler2D(sky_tex, sky_smp), uv);
}
@end

@program sky sky_vs sky_fs
