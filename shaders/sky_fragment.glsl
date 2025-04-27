#version 330 core

uniform sampler2D sampler;
uniform float timer;

in vec2 fragment_uv;
out vec4 fragColor;

void main() {
    vec2 uv = vec2(timer, fragment_uv.t);
    fragColor = texture2D(sampler, uv);
}
