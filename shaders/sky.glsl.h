#pragma once
/*
    #version:1# (machine generated, don't edit!)

    Generated by sokol-shdc (https://github.com/floooh/sokol-tools)

    Cmdline:
        sokol-shdc --input sky.glsl --output sky.glsl.h --slang glsl410:hlsl5:metal_macos:wgsl

    Overview:
    =========
    Shader program: 'sky':
        Get shader desc: sky_shader_desc(sg_query_backend());
        Vertex Shader: sky_vs
        Fragment Shader: sky_fs
        Attributes:
            ATTR_sky_position => 0
            ATTR_sky_uv => 1
    Bindings:
        Uniform block 'sky_vs_params':
            C struct: sky_vs_params_t
            Bind slot: UB_sky_vs_params => 0
        Uniform block 'sky_ps_params':
            C struct: sky_ps_params_t
            Bind slot: UB_sky_ps_params => 1
        Image 'sky_tex':
            Image type: SG_IMAGETYPE_2D
            Sample type: SG_IMAGESAMPLETYPE_FLOAT
            Multisampled: false
            Bind slot: IMG_sky_tex => 0
        Sampler 'sky_smp':
            Type: SG_SAMPLERTYPE_FILTERING
            Bind slot: SMP_sky_smp => 0
*/
#if !defined(SOKOL_GFX_INCLUDED)
#error "Please include sokol_gfx.h before sky.glsl.h"
#endif
#if !defined(SOKOL_SHDC_ALIGN)
#if defined(_MSC_VER)
#define SOKOL_SHDC_ALIGN(a) __declspec(align(a))
#else
#define SOKOL_SHDC_ALIGN(a) __attribute__((aligned(a)))
#endif
#endif
#define ATTR_sky_position (0)
#define ATTR_sky_uv (1)
#define UB_sky_vs_params (0)
#define UB_sky_ps_params (1)
#define IMG_sky_tex (0)
#define SMP_sky_smp (0)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct sky_vs_params_t {
    HMM_Mat4 matrix;
} sky_vs_params_t;
#pragma pack(pop)
#pragma pack(push,1)
SOKOL_SHDC_ALIGN(16) typedef struct sky_ps_params_t {
    float timer;
    uint8_t _pad_4[12];
} sky_ps_params_t;
#pragma pack(pop)
/*
    #version 410

    uniform vec4 sky_vs_params[4];
    layout(location = 0) in vec4 position;
    layout(location = 0) out vec2 fragment_uv;
    layout(location = 1) in vec2 uv;

    void main()
    {
        gl_Position = mat4(sky_vs_params[0], sky_vs_params[1], sky_vs_params[2], sky_vs_params[3]) * position;
        fragment_uv = uv;
    }

*/
static const uint8_t sky_vs_source_glsl410[308] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x34,0x31,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x73,0x6b,0x79,0x5f,0x76,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x34,0x5d,0x3b,0x0a,0x6c,0x61,0x79,
    0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,
    0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x34,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,
    0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,0x6f,0x75,0x74,0x20,0x76,0x65,0x63,
    0x32,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x3b,0x0a,0x6c,
    0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,
    0x20,0x31,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x75,0x76,0x3b,0x0a,
    0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,
    0x20,0x6d,0x61,0x74,0x34,0x28,0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,
    0x61,0x6d,0x73,0x5b,0x30,0x5d,0x2c,0x20,0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x2c,0x20,0x73,0x6b,0x79,0x5f,0x76,0x73,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x32,0x5d,0x2c,0x20,0x73,0x6b,0x79,0x5f,
    0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x33,0x5d,0x29,0x20,0x2a,0x20,
    0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,
    0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,0x75,0x76,0x3b,0x0a,
    0x7d,0x0a,0x0a,0x00,
};
/*
    #version 410

    uniform vec4 sky_ps_params[1];
    uniform sampler2D sky_tex_sky_smp;

    layout(location = 0) in vec2 fragment_uv;
    layout(location = 0) out vec4 fragColor;

    void main()
    {
        fragColor = texture(sky_tex_sky_smp, vec2(sky_ps_params[0].x, fragment_uv.y));
    }

*/
static const uint8_t sky_fs_source_glsl410[266] = {
    0x23,0x76,0x65,0x72,0x73,0x69,0x6f,0x6e,0x20,0x34,0x31,0x30,0x0a,0x0a,0x75,0x6e,
    0x69,0x66,0x6f,0x72,0x6d,0x20,0x76,0x65,0x63,0x34,0x20,0x73,0x6b,0x79,0x5f,0x70,
    0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x31,0x5d,0x3b,0x0a,0x75,0x6e,0x69,
    0x66,0x6f,0x72,0x6d,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x32,0x44,0x20,0x73,
    0x6b,0x79,0x5f,0x74,0x65,0x78,0x5f,0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x3b,0x0a,
    0x0a,0x6c,0x61,0x79,0x6f,0x75,0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,
    0x20,0x3d,0x20,0x30,0x29,0x20,0x69,0x6e,0x20,0x76,0x65,0x63,0x32,0x20,0x66,0x72,
    0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x3b,0x0a,0x6c,0x61,0x79,0x6f,0x75,
    0x74,0x28,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x30,0x29,0x20,
    0x6f,0x75,0x74,0x20,0x76,0x65,0x63,0x34,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,
    0x6f,0x72,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x6d,0x61,0x69,0x6e,0x28,0x29,
    0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,
    0x20,0x3d,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x73,0x6b,0x79,0x5f,0x74,
    0x65,0x78,0x5f,0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x2c,0x20,0x76,0x65,0x63,0x32,
    0x28,0x73,0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x5b,0x30,
    0x5d,0x2e,0x78,0x2c,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,
    0x2e,0x79,0x29,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    cbuffer sky_vs_params : register(b0)
    {
        row_major float4x4 _19_matrix : packoffset(c0);
    };


    static float4 gl_Position;
    static float4 position;
    static float2 fragment_uv;
    static float2 uv;

    struct SPIRV_Cross_Input
    {
        float4 position : TEXCOORD0;
        float2 uv : TEXCOORD1;
    };

    struct SPIRV_Cross_Output
    {
        float2 fragment_uv : TEXCOORD0;
        float4 gl_Position : SV_Position;
    };

    void vert_main()
    {
        gl_Position = mul(position, _19_matrix);
        fragment_uv = uv;
    }

    SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
    {
        position = stage_input.position;
        uv = stage_input.uv;
        vert_main();
        SPIRV_Cross_Output stage_output;
        stage_output.gl_Position = gl_Position;
        stage_output.fragment_uv = fragment_uv;
        return stage_output;
    }
*/
static const uint8_t sky_vs_source_hlsl5[768] = {
    0x63,0x62,0x75,0x66,0x66,0x65,0x72,0x20,0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x20,0x3a,0x20,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,
    0x28,0x62,0x30,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x72,0x6f,0x77,0x5f,0x6d,
    0x61,0x6a,0x6f,0x72,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x78,0x34,0x20,0x5f,0x31,
    0x39,0x5f,0x6d,0x61,0x74,0x72,0x69,0x78,0x20,0x3a,0x20,0x70,0x61,0x63,0x6b,0x6f,
    0x66,0x66,0x73,0x65,0x74,0x28,0x63,0x30,0x29,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x0a,
    0x73,0x74,0x61,0x74,0x69,0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x67,0x6c,
    0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x73,0x74,0x61,0x74,0x69,
    0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x3b,0x0a,0x73,0x74,0x61,0x74,0x69,0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,
    0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x3b,0x0a,0x73,0x74,
    0x61,0x74,0x69,0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x75,0x76,0x3b,0x0a,
    0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,
    0x6f,0x73,0x73,0x5f,0x49,0x6e,0x70,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,
    0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,
    0x3a,0x20,0x54,0x45,0x58,0x43,0x4f,0x4f,0x52,0x44,0x30,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x75,0x76,0x20,0x3a,0x20,0x54,0x45,0x58,
    0x43,0x4f,0x4f,0x52,0x44,0x31,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,
    0x63,0x74,0x20,0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x4f,
    0x75,0x74,0x70,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,
    0x74,0x32,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3a,
    0x20,0x54,0x45,0x58,0x43,0x4f,0x4f,0x52,0x44,0x30,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,
    0x6f,0x6e,0x20,0x3a,0x20,0x53,0x56,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,
    0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,0x20,0x76,0x65,0x72,0x74,0x5f,
    0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x67,0x6c,0x5f,
    0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x6d,0x75,0x6c,0x28,0x70,
    0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x5f,0x31,0x39,0x5f,0x6d,0x61,0x74,
    0x72,0x69,0x78,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,
    0x6e,0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,0x75,0x76,0x3b,0x0a,0x7d,0x0a,0x0a,0x53,
    0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x4f,0x75,0x74,0x70,0x75,
    0x74,0x20,0x6d,0x61,0x69,0x6e,0x28,0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,
    0x73,0x73,0x5f,0x49,0x6e,0x70,0x75,0x74,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,
    0x6e,0x70,0x75,0x74,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x70,0x6f,0x73,0x69,
    0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x70,
    0x75,0x74,0x2e,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x75,0x76,0x20,0x3d,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x70,0x75,
    0x74,0x2e,0x75,0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x76,0x65,0x72,0x74,0x5f,0x6d,
    0x61,0x69,0x6e,0x28,0x29,0x3b,0x0a,0x20,0x20,0x20,0x20,0x53,0x50,0x49,0x52,0x56,
    0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x4f,0x75,0x74,0x70,0x75,0x74,0x20,0x73,0x74,
    0x61,0x67,0x65,0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x3b,0x0a,0x20,0x20,0x20,0x20,
    0x73,0x74,0x61,0x67,0x65,0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x2e,0x67,0x6c,0x5f,
    0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3d,0x20,0x67,0x6c,0x5f,0x50,0x6f,
    0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x20,0x20,0x20,0x20,0x73,0x74,0x61,0x67,
    0x65,0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,
    0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,
    0x75,0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x73,
    0x74,0x61,0x67,0x65,0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x00,

};
/*
    cbuffer sky_ps_params : register(b0)
    {
        float _12_timer : packoffset(c0);
    };

    Texture2D<float4> sky_tex : register(t0);
    SamplerState sky_smp : register(s0);

    static float2 fragment_uv;
    static float4 fragColor;

    struct SPIRV_Cross_Input
    {
        float2 fragment_uv : TEXCOORD0;
    };

    struct SPIRV_Cross_Output
    {
        float4 fragColor : SV_Target0;
    };

    void frag_main()
    {
        fragColor = sky_tex.Sample(sky_smp, float2(_12_timer, fragment_uv.y));
    }

    SPIRV_Cross_Output main(SPIRV_Cross_Input stage_input)
    {
        fragment_uv = stage_input.fragment_uv;
        frag_main();
        SPIRV_Cross_Output stage_output;
        stage_output.fragColor = fragColor;
        return stage_output;
    }
*/
static const uint8_t sky_fs_source_hlsl5[667] = {
    0x63,0x62,0x75,0x66,0x66,0x65,0x72,0x20,0x73,0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x20,0x3a,0x20,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,
    0x28,0x62,0x30,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x20,0x5f,0x31,0x32,0x5f,0x74,0x69,0x6d,0x65,0x72,0x20,0x3a,0x20,0x70,0x61,0x63,
    0x6b,0x6f,0x66,0x66,0x73,0x65,0x74,0x28,0x63,0x30,0x29,0x3b,0x0a,0x7d,0x3b,0x0a,
    0x0a,0x54,0x65,0x78,0x74,0x75,0x72,0x65,0x32,0x44,0x3c,0x66,0x6c,0x6f,0x61,0x74,
    0x34,0x3e,0x20,0x73,0x6b,0x79,0x5f,0x74,0x65,0x78,0x20,0x3a,0x20,0x72,0x65,0x67,
    0x69,0x73,0x74,0x65,0x72,0x28,0x74,0x30,0x29,0x3b,0x0a,0x53,0x61,0x6d,0x70,0x6c,
    0x65,0x72,0x53,0x74,0x61,0x74,0x65,0x20,0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x20,
    0x3a,0x20,0x72,0x65,0x67,0x69,0x73,0x74,0x65,0x72,0x28,0x73,0x30,0x29,0x3b,0x0a,
    0x0a,0x73,0x74,0x61,0x74,0x69,0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x66,
    0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x3b,0x0a,0x73,0x74,0x61,0x74,
    0x69,0x63,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,
    0x6c,0x6f,0x72,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x53,0x50,0x49,
    0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x49,0x6e,0x70,0x75,0x74,0x0a,0x7b,
    0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x66,0x72,0x61,0x67,
    0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3a,0x20,0x54,0x45,0x58,0x43,0x4f,0x4f,
    0x52,0x44,0x30,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,
    0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x4f,0x75,0x74,0x70,
    0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,
    0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x20,0x3a,0x20,0x53,0x56,0x5f,0x54,
    0x61,0x72,0x67,0x65,0x74,0x30,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x76,0x6f,0x69,0x64,
    0x20,0x66,0x72,0x61,0x67,0x5f,0x6d,0x61,0x69,0x6e,0x28,0x29,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x20,0x3d,0x20,0x73,
    0x6b,0x79,0x5f,0x74,0x65,0x78,0x2e,0x53,0x61,0x6d,0x70,0x6c,0x65,0x28,0x73,0x6b,
    0x79,0x5f,0x73,0x6d,0x70,0x2c,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,0x5f,0x31,
    0x32,0x5f,0x74,0x69,0x6d,0x65,0x72,0x2c,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,
    0x74,0x5f,0x75,0x76,0x2e,0x79,0x29,0x29,0x3b,0x0a,0x7d,0x0a,0x0a,0x53,0x50,0x49,
    0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,0x5f,0x4f,0x75,0x74,0x70,0x75,0x74,0x20,
    0x6d,0x61,0x69,0x6e,0x28,0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,0x73,
    0x5f,0x49,0x6e,0x70,0x75,0x74,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x70,
    0x75,0x74,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,
    0x6e,0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,
    0x70,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x3b,
    0x0a,0x20,0x20,0x20,0x20,0x66,0x72,0x61,0x67,0x5f,0x6d,0x61,0x69,0x6e,0x28,0x29,
    0x3b,0x0a,0x20,0x20,0x20,0x20,0x53,0x50,0x49,0x52,0x56,0x5f,0x43,0x72,0x6f,0x73,
    0x73,0x5f,0x4f,0x75,0x74,0x70,0x75,0x74,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,0x6f,
    0x75,0x74,0x70,0x75,0x74,0x3b,0x0a,0x20,0x20,0x20,0x20,0x73,0x74,0x61,0x67,0x65,
    0x5f,0x6f,0x75,0x74,0x70,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,
    0x72,0x20,0x3d,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x73,0x74,0x61,0x67,0x65,0x5f,
    0x6f,0x75,0x74,0x70,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x00,
};
/*
    #include <metal_stdlib>
    #include <simd/simd.h>

    using namespace metal;

    struct sky_vs_params
    {
        float4x4 matrix;
    };

    struct main0_out
    {
        float2 fragment_uv [[user(locn0)]];
        float4 gl_Position [[position]];
    };

    struct main0_in
    {
        float4 position [[attribute(0)]];
        float2 uv [[attribute(1)]];
    };

    vertex main0_out main0(main0_in in [[stage_in]], constant sky_vs_params& _19 [[buffer(0)]])
    {
        main0_out out = {};
        out.gl_Position = _19.matrix * in.position;
        out.fragment_uv = in.uv;
        return out;
    }

*/
static const uint8_t sky_vs_source_metal_macos[527] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x73,
    0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x78,0x34,0x20,0x6d,0x61,0x74,0x72,
    0x69,0x78,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,
    0x6c,0x6f,0x61,0x74,0x32,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,
    0x76,0x20,0x5b,0x5b,0x75,0x73,0x65,0x72,0x28,0x6c,0x6f,0x63,0x6e,0x30,0x29,0x5d,
    0x5d,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x67,0x6c,
    0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x5b,0x5b,0x70,0x6f,0x73,0x69,
    0x74,0x69,0x6f,0x6e,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,
    0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x0a,0x7b,0x0a,0x20,0x20,
    0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x34,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x20,0x5b,0x5b,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x28,0x30,0x29,
    0x5d,0x5d,0x3b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x75,
    0x76,0x20,0x5b,0x5b,0x61,0x74,0x74,0x72,0x69,0x62,0x75,0x74,0x65,0x28,0x31,0x29,
    0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x76,0x65,0x72,0x74,0x65,0x78,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x28,0x6d,
    0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x20,0x69,0x6e,0x20,0x5b,0x5b,0x73,0x74,0x61,
    0x67,0x65,0x5f,0x69,0x6e,0x5d,0x5d,0x2c,0x20,0x63,0x6f,0x6e,0x73,0x74,0x61,0x6e,
    0x74,0x20,0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x26,
    0x20,0x5f,0x31,0x39,0x20,0x5b,0x5b,0x62,0x75,0x66,0x66,0x65,0x72,0x28,0x30,0x29,
    0x5d,0x5d,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,
    0x6f,0x75,0x74,0x20,0x6f,0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x6f,0x75,0x74,0x2e,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x20,0x3d,0x20,0x5f,0x31,0x39,0x2e,0x6d,0x61,0x74,0x72,0x69,0x78,0x20,0x2a,
    0x20,0x69,0x6e,0x2e,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x3b,0x0a,0x20,0x20,
    0x20,0x20,0x6f,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,
    0x76,0x20,0x3d,0x20,0x69,0x6e,0x2e,0x75,0x76,0x3b,0x0a,0x20,0x20,0x20,0x20,0x72,
    0x65,0x74,0x75,0x72,0x6e,0x20,0x6f,0x75,0x74,0x3b,0x0a,0x7d,0x0a,0x0a,0x00,
};
/*
    #include <metal_stdlib>
    #include <simd/simd.h>

    using namespace metal;

    struct sky_ps_params
    {
        float timer;
    };

    struct main0_out
    {
        float4 fragColor [[color(0)]];
    };

    struct main0_in
    {
        float2 fragment_uv [[user(locn0)]];
    };

    fragment main0_out main0(main0_in in [[stage_in]], constant sky_ps_params& _12 [[buffer(0)]], texture2d<float> sky_tex [[texture(0)]], sampler sky_smp [[sampler(0)]])
    {
        main0_out out = {};
        out.fragColor = sky_tex.sample(sky_smp, float2(_12.timer, in.fragment_uv.y));
        return out;
    }

*/
static const uint8_t sky_fs_source_metal_macos[531] = {
    0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,0x20,0x3c,0x6d,0x65,0x74,0x61,0x6c,0x5f,
    0x73,0x74,0x64,0x6c,0x69,0x62,0x3e,0x0a,0x23,0x69,0x6e,0x63,0x6c,0x75,0x64,0x65,
    0x20,0x3c,0x73,0x69,0x6d,0x64,0x2f,0x73,0x69,0x6d,0x64,0x2e,0x68,0x3e,0x0a,0x0a,
    0x75,0x73,0x69,0x6e,0x67,0x20,0x6e,0x61,0x6d,0x65,0x73,0x70,0x61,0x63,0x65,0x20,
    0x6d,0x65,0x74,0x61,0x6c,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x73,
    0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x0a,0x7b,0x0a,0x20,
    0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x20,0x74,0x69,0x6d,0x65,0x72,0x3b,0x0a,
    0x7d,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,
    0x5f,0x6f,0x75,0x74,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,
    0x34,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x20,0x5b,0x5b,0x63,0x6f,
    0x6c,0x6f,0x72,0x28,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x73,0x74,
    0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x0a,0x7b,0x0a,
    0x20,0x20,0x20,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x20,0x66,0x72,0x61,0x67,0x6d,
    0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x5b,0x5b,0x75,0x73,0x65,0x72,0x28,0x6c,0x6f,
    0x63,0x6e,0x30,0x29,0x5d,0x5d,0x3b,0x0a,0x7d,0x3b,0x0a,0x0a,0x66,0x72,0x61,0x67,
    0x6d,0x65,0x6e,0x74,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,0x75,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x30,0x28,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x69,0x6e,0x20,0x69,0x6e,
    0x20,0x5b,0x5b,0x73,0x74,0x61,0x67,0x65,0x5f,0x69,0x6e,0x5d,0x5d,0x2c,0x20,0x63,
    0x6f,0x6e,0x73,0x74,0x61,0x6e,0x74,0x20,0x73,0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,
    0x61,0x72,0x61,0x6d,0x73,0x26,0x20,0x5f,0x31,0x32,0x20,0x5b,0x5b,0x62,0x75,0x66,
    0x66,0x65,0x72,0x28,0x30,0x29,0x5d,0x5d,0x2c,0x20,0x74,0x65,0x78,0x74,0x75,0x72,
    0x65,0x32,0x64,0x3c,0x66,0x6c,0x6f,0x61,0x74,0x3e,0x20,0x73,0x6b,0x79,0x5f,0x74,
    0x65,0x78,0x20,0x5b,0x5b,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x28,0x30,0x29,0x5d,
    0x5d,0x2c,0x20,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x20,0x73,0x6b,0x79,0x5f,0x73,
    0x6d,0x70,0x20,0x5b,0x5b,0x73,0x61,0x6d,0x70,0x6c,0x65,0x72,0x28,0x30,0x29,0x5d,
    0x5d,0x29,0x0a,0x7b,0x0a,0x20,0x20,0x20,0x20,0x6d,0x61,0x69,0x6e,0x30,0x5f,0x6f,
    0x75,0x74,0x20,0x6f,0x75,0x74,0x20,0x3d,0x20,0x7b,0x7d,0x3b,0x0a,0x20,0x20,0x20,
    0x20,0x6f,0x75,0x74,0x2e,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x20,0x3d,
    0x20,0x73,0x6b,0x79,0x5f,0x74,0x65,0x78,0x2e,0x73,0x61,0x6d,0x70,0x6c,0x65,0x28,
    0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x2c,0x20,0x66,0x6c,0x6f,0x61,0x74,0x32,0x28,
    0x5f,0x31,0x32,0x2e,0x74,0x69,0x6d,0x65,0x72,0x2c,0x20,0x69,0x6e,0x2e,0x66,0x72,
    0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x2e,0x79,0x29,0x29,0x3b,0x0a,0x20,
    0x20,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x20,0x6f,0x75,0x74,0x3b,0x0a,0x7d,
    0x0a,0x0a,0x00,
};
/*
    diagnostic(off, derivative_uniformity);

    struct sky_vs_params {
      /_ @offset(0) _/
      matrix : mat4x4f,
    }

    @binding(0) @group(0) var<uniform> x_19 : sky_vs_params;

    var<private> position_1 : vec4f;

    var<private> fragment_uv : vec2f;

    var<private> uv : vec2f;

    var<private> gl_Position : vec4f;

    fn main_1() {
      gl_Position = (x_19.matrix * position_1);
      fragment_uv = uv;
      return;
    }

    struct main_out {
      @builtin(position)
      gl_Position : vec4f,
      @location(0)
      fragment_uv_1 : vec2f,
    }

    @vertex
    fn main(@location(0) position_1_param : vec4f, @location(1) uv_param : vec2f) -> main_out {
      position_1 = position_1_param;
      uv = uv_param;
      main_1();
      return main_out(gl_Position, fragment_uv);
    }
*/
static const uint8_t sky_vs_source_wgsl[700] = {
    0x64,0x69,0x61,0x67,0x6e,0x6f,0x73,0x74,0x69,0x63,0x28,0x6f,0x66,0x66,0x2c,0x20,
    0x64,0x65,0x72,0x69,0x76,0x61,0x74,0x69,0x76,0x65,0x5f,0x75,0x6e,0x69,0x66,0x6f,
    0x72,0x6d,0x69,0x74,0x79,0x29,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,
    0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x20,0x7b,0x0a,
    0x20,0x20,0x2f,0x2a,0x20,0x40,0x6f,0x66,0x66,0x73,0x65,0x74,0x28,0x30,0x29,0x20,
    0x2a,0x2f,0x0a,0x20,0x20,0x6d,0x61,0x74,0x72,0x69,0x78,0x20,0x3a,0x20,0x6d,0x61,
    0x74,0x34,0x78,0x34,0x66,0x2c,0x0a,0x7d,0x0a,0x0a,0x40,0x62,0x69,0x6e,0x64,0x69,
    0x6e,0x67,0x28,0x30,0x29,0x20,0x40,0x67,0x72,0x6f,0x75,0x70,0x28,0x30,0x29,0x20,
    0x76,0x61,0x72,0x3c,0x75,0x6e,0x69,0x66,0x6f,0x72,0x6d,0x3e,0x20,0x78,0x5f,0x31,
    0x39,0x20,0x3a,0x20,0x73,0x6b,0x79,0x5f,0x76,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,
    0x73,0x3b,0x0a,0x0a,0x76,0x61,0x72,0x3c,0x70,0x72,0x69,0x76,0x61,0x74,0x65,0x3e,
    0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5f,0x31,0x20,0x3a,0x20,0x76,0x65,
    0x63,0x34,0x66,0x3b,0x0a,0x0a,0x76,0x61,0x72,0x3c,0x70,0x72,0x69,0x76,0x61,0x74,
    0x65,0x3e,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3a,
    0x20,0x76,0x65,0x63,0x32,0x66,0x3b,0x0a,0x0a,0x76,0x61,0x72,0x3c,0x70,0x72,0x69,
    0x76,0x61,0x74,0x65,0x3e,0x20,0x75,0x76,0x20,0x3a,0x20,0x76,0x65,0x63,0x32,0x66,
    0x3b,0x0a,0x0a,0x76,0x61,0x72,0x3c,0x70,0x72,0x69,0x76,0x61,0x74,0x65,0x3e,0x20,
    0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x20,0x3a,0x20,0x76,0x65,
    0x63,0x34,0x66,0x3b,0x0a,0x0a,0x66,0x6e,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x31,0x28,
    0x29,0x20,0x7b,0x0a,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,
    0x6e,0x20,0x3d,0x20,0x28,0x78,0x5f,0x31,0x39,0x2e,0x6d,0x61,0x74,0x72,0x69,0x78,
    0x20,0x2a,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5f,0x31,0x29,0x3b,0x0a,
    0x20,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,
    0x75,0x76,0x3b,0x0a,0x20,0x20,0x72,0x65,0x74,0x75,0x72,0x6e,0x3b,0x0a,0x7d,0x0a,
    0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,
    0x20,0x7b,0x0a,0x20,0x20,0x40,0x62,0x75,0x69,0x6c,0x74,0x69,0x6e,0x28,0x70,0x6f,
    0x73,0x69,0x74,0x69,0x6f,0x6e,0x29,0x0a,0x20,0x20,0x67,0x6c,0x5f,0x50,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x20,0x3a,0x20,0x76,0x65,0x63,0x34,0x66,0x2c,0x0a,0x20,
    0x20,0x40,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x28,0x30,0x29,0x0a,0x20,0x20,
    0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x5f,0x31,0x20,0x3a,0x20,
    0x76,0x65,0x63,0x32,0x66,0x2c,0x0a,0x7d,0x0a,0x0a,0x40,0x76,0x65,0x72,0x74,0x65,
    0x78,0x0a,0x66,0x6e,0x20,0x6d,0x61,0x69,0x6e,0x28,0x40,0x6c,0x6f,0x63,0x61,0x74,
    0x69,0x6f,0x6e,0x28,0x30,0x29,0x20,0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5f,
    0x31,0x5f,0x70,0x61,0x72,0x61,0x6d,0x20,0x3a,0x20,0x76,0x65,0x63,0x34,0x66,0x2c,
    0x20,0x40,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x28,0x31,0x29,0x20,0x75,0x76,
    0x5f,0x70,0x61,0x72,0x61,0x6d,0x20,0x3a,0x20,0x76,0x65,0x63,0x32,0x66,0x29,0x20,
    0x2d,0x3e,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,0x20,0x7b,0x0a,0x20,0x20,
    0x70,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x5f,0x31,0x20,0x3d,0x20,0x70,0x6f,0x73,
    0x69,0x74,0x69,0x6f,0x6e,0x5f,0x31,0x5f,0x70,0x61,0x72,0x61,0x6d,0x3b,0x0a,0x20,
    0x20,0x75,0x76,0x20,0x3d,0x20,0x75,0x76,0x5f,0x70,0x61,0x72,0x61,0x6d,0x3b,0x0a,
    0x20,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x31,0x28,0x29,0x3b,0x0a,0x20,0x20,0x72,0x65,
    0x74,0x75,0x72,0x6e,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,0x28,0x67,0x6c,
    0x5f,0x50,0x6f,0x73,0x69,0x74,0x69,0x6f,0x6e,0x2c,0x20,0x66,0x72,0x61,0x67,0x6d,
    0x65,0x6e,0x74,0x5f,0x75,0x76,0x29,0x3b,0x0a,0x7d,0x0a,0x00,
};
/*
    diagnostic(off, derivative_uniformity);

    struct sky_ps_params {
      /_ @offset(0) _/
      timer : f32,
    }

    @binding(8) @group(0) var<uniform> x_12 : sky_ps_params;

    var<private> fragment_uv : vec2f;

    var<private> fragColor : vec4f;

    @binding(64) @group(1) var sky_tex : texture_2d<f32>;

    @binding(80) @group(1) var sky_smp : sampler;

    fn main_1() {
      var uv : vec2f;
      uv = vec2f(x_12.timer, fragment_uv.y);
      let x_39 = uv;
      let x_40 = textureSample(sky_tex, sky_smp, x_39);
      fragColor = x_40;
      return;
    }

    struct main_out {
      @location(0)
      fragColor_1 : vec4f,
    }

    @fragment
    fn main(@location(0) fragment_uv_param : vec2f) -> main_out {
      fragment_uv = fragment_uv_param;
      main_1();
      return main_out(fragColor);
    }
*/
static const uint8_t sky_fs_source_wgsl[715] = {
    0x64,0x69,0x61,0x67,0x6e,0x6f,0x73,0x74,0x69,0x63,0x28,0x6f,0x66,0x66,0x2c,0x20,
    0x64,0x65,0x72,0x69,0x76,0x61,0x74,0x69,0x76,0x65,0x5f,0x75,0x6e,0x69,0x66,0x6f,
    0x72,0x6d,0x69,0x74,0x79,0x29,0x3b,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,
    0x73,0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x20,0x7b,0x0a,
    0x20,0x20,0x2f,0x2a,0x20,0x40,0x6f,0x66,0x66,0x73,0x65,0x74,0x28,0x30,0x29,0x20,
    0x2a,0x2f,0x0a,0x20,0x20,0x74,0x69,0x6d,0x65,0x72,0x20,0x3a,0x20,0x66,0x33,0x32,
    0x2c,0x0a,0x7d,0x0a,0x0a,0x40,0x62,0x69,0x6e,0x64,0x69,0x6e,0x67,0x28,0x38,0x29,
    0x20,0x40,0x67,0x72,0x6f,0x75,0x70,0x28,0x30,0x29,0x20,0x76,0x61,0x72,0x3c,0x75,
    0x6e,0x69,0x66,0x6f,0x72,0x6d,0x3e,0x20,0x78,0x5f,0x31,0x32,0x20,0x3a,0x20,0x73,
    0x6b,0x79,0x5f,0x70,0x73,0x5f,0x70,0x61,0x72,0x61,0x6d,0x73,0x3b,0x0a,0x0a,0x76,
    0x61,0x72,0x3c,0x70,0x72,0x69,0x76,0x61,0x74,0x65,0x3e,0x20,0x66,0x72,0x61,0x67,
    0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3a,0x20,0x76,0x65,0x63,0x32,0x66,0x3b,
    0x0a,0x0a,0x76,0x61,0x72,0x3c,0x70,0x72,0x69,0x76,0x61,0x74,0x65,0x3e,0x20,0x66,
    0x72,0x61,0x67,0x43,0x6f,0x6c,0x6f,0x72,0x20,0x3a,0x20,0x76,0x65,0x63,0x34,0x66,
    0x3b,0x0a,0x0a,0x40,0x62,0x69,0x6e,0x64,0x69,0x6e,0x67,0x28,0x36,0x34,0x29,0x20,
    0x40,0x67,0x72,0x6f,0x75,0x70,0x28,0x31,0x29,0x20,0x76,0x61,0x72,0x20,0x73,0x6b,
    0x79,0x5f,0x74,0x65,0x78,0x20,0x3a,0x20,0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x5f,
    0x32,0x64,0x3c,0x66,0x33,0x32,0x3e,0x3b,0x0a,0x0a,0x40,0x62,0x69,0x6e,0x64,0x69,
    0x6e,0x67,0x28,0x38,0x30,0x29,0x20,0x40,0x67,0x72,0x6f,0x75,0x70,0x28,0x31,0x29,
    0x20,0x76,0x61,0x72,0x20,0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x20,0x3a,0x20,0x73,
    0x61,0x6d,0x70,0x6c,0x65,0x72,0x3b,0x0a,0x0a,0x66,0x6e,0x20,0x6d,0x61,0x69,0x6e,
    0x5f,0x31,0x28,0x29,0x20,0x7b,0x0a,0x20,0x20,0x76,0x61,0x72,0x20,0x75,0x76,0x20,
    0x3a,0x20,0x76,0x65,0x63,0x32,0x66,0x3b,0x0a,0x20,0x20,0x75,0x76,0x20,0x3d,0x20,
    0x76,0x65,0x63,0x32,0x66,0x28,0x78,0x5f,0x31,0x32,0x2e,0x74,0x69,0x6d,0x65,0x72,
    0x2c,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x2e,0x79,0x29,
    0x3b,0x0a,0x20,0x20,0x6c,0x65,0x74,0x20,0x78,0x5f,0x33,0x39,0x20,0x3d,0x20,0x75,
    0x76,0x3b,0x0a,0x20,0x20,0x6c,0x65,0x74,0x20,0x78,0x5f,0x34,0x30,0x20,0x3d,0x20,
    0x74,0x65,0x78,0x74,0x75,0x72,0x65,0x53,0x61,0x6d,0x70,0x6c,0x65,0x28,0x73,0x6b,
    0x79,0x5f,0x74,0x65,0x78,0x2c,0x20,0x73,0x6b,0x79,0x5f,0x73,0x6d,0x70,0x2c,0x20,
    0x78,0x5f,0x33,0x39,0x29,0x3b,0x0a,0x20,0x20,0x66,0x72,0x61,0x67,0x43,0x6f,0x6c,
    0x6f,0x72,0x20,0x3d,0x20,0x78,0x5f,0x34,0x30,0x3b,0x0a,0x20,0x20,0x72,0x65,0x74,
    0x75,0x72,0x6e,0x3b,0x0a,0x7d,0x0a,0x0a,0x73,0x74,0x72,0x75,0x63,0x74,0x20,0x6d,
    0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,0x20,0x7b,0x0a,0x20,0x20,0x40,0x6c,0x6f,0x63,
    0x61,0x74,0x69,0x6f,0x6e,0x28,0x30,0x29,0x0a,0x20,0x20,0x66,0x72,0x61,0x67,0x43,
    0x6f,0x6c,0x6f,0x72,0x5f,0x31,0x20,0x3a,0x20,0x76,0x65,0x63,0x34,0x66,0x2c,0x0a,
    0x7d,0x0a,0x0a,0x40,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x0a,0x66,0x6e,0x20,
    0x6d,0x61,0x69,0x6e,0x28,0x40,0x6c,0x6f,0x63,0x61,0x74,0x69,0x6f,0x6e,0x28,0x30,
    0x29,0x20,0x66,0x72,0x61,0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x5f,0x70,0x61,
    0x72,0x61,0x6d,0x20,0x3a,0x20,0x76,0x65,0x63,0x32,0x66,0x29,0x20,0x2d,0x3e,0x20,
    0x6d,0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,0x20,0x7b,0x0a,0x20,0x20,0x66,0x72,0x61,
    0x67,0x6d,0x65,0x6e,0x74,0x5f,0x75,0x76,0x20,0x3d,0x20,0x66,0x72,0x61,0x67,0x6d,
    0x65,0x6e,0x74,0x5f,0x75,0x76,0x5f,0x70,0x61,0x72,0x61,0x6d,0x3b,0x0a,0x20,0x20,
    0x6d,0x61,0x69,0x6e,0x5f,0x31,0x28,0x29,0x3b,0x0a,0x20,0x20,0x72,0x65,0x74,0x75,
    0x72,0x6e,0x20,0x6d,0x61,0x69,0x6e,0x5f,0x6f,0x75,0x74,0x28,0x66,0x72,0x61,0x67,
    0x43,0x6f,0x6c,0x6f,0x72,0x29,0x3b,0x0a,0x7d,0x0a,0x00,
};
static inline const sg_shader_desc* sky_shader_desc(sg_backend backend) {
    if (backend == SG_BACKEND_GLCORE) {
        static sg_shader_desc desc;
        static bool valid;
        if (!valid) {
            valid = true;
            desc.vertex_func.source = (const char*)sky_vs_source_glsl410;
            desc.vertex_func.entry = "main";
            desc.fragment_func.source = (const char*)sky_fs_source_glsl410;
            desc.fragment_func.entry = "main";
            desc.attrs[0].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[0].glsl_name = "position";
            desc.attrs[1].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[1].glsl_name = "uv";
            desc.uniform_blocks[0].stage = SG_SHADERSTAGE_VERTEX;
            desc.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[0].size = 64;
            desc.uniform_blocks[0].glsl_uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
            desc.uniform_blocks[0].glsl_uniforms[0].array_count = 4;
            desc.uniform_blocks[0].glsl_uniforms[0].glsl_name = "sky_vs_params";
            desc.uniform_blocks[1].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.uniform_blocks[1].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[1].size = 16;
            desc.uniform_blocks[1].glsl_uniforms[0].type = SG_UNIFORMTYPE_FLOAT4;
            desc.uniform_blocks[1].glsl_uniforms[0].array_count = 1;
            desc.uniform_blocks[1].glsl_uniforms[0].glsl_name = "sky_ps_params";
            desc.images[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.images[0].image_type = SG_IMAGETYPE_2D;
            desc.images[0].sample_type = SG_IMAGESAMPLETYPE_FLOAT;
            desc.images[0].multisampled = false;
            desc.samplers[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.samplers[0].sampler_type = SG_SAMPLERTYPE_FILTERING;
            desc.image_sampler_pairs[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.image_sampler_pairs[0].image_slot = 0;
            desc.image_sampler_pairs[0].sampler_slot = 0;
            desc.image_sampler_pairs[0].glsl_name = "sky_tex_sky_smp";
            desc.label = "sky_shader";
        }
        return &desc;
    }
    if (backend == SG_BACKEND_D3D11) {
        static sg_shader_desc desc;
        static bool valid;
        if (!valid) {
            valid = true;
            desc.vertex_func.source = (const char*)sky_vs_source_hlsl5;
            desc.vertex_func.d3d11_target = "vs_5_0";
            desc.vertex_func.entry = "main";
            desc.fragment_func.source = (const char*)sky_fs_source_hlsl5;
            desc.fragment_func.d3d11_target = "ps_5_0";
            desc.fragment_func.entry = "main";
            desc.attrs[0].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[0].hlsl_sem_name = "TEXCOORD";
            desc.attrs[0].hlsl_sem_index = 0;
            desc.attrs[1].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[1].hlsl_sem_name = "TEXCOORD";
            desc.attrs[1].hlsl_sem_index = 1;
            desc.uniform_blocks[0].stage = SG_SHADERSTAGE_VERTEX;
            desc.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[0].size = 64;
            desc.uniform_blocks[0].hlsl_register_b_n = 0;
            desc.uniform_blocks[1].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.uniform_blocks[1].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[1].size = 16;
            desc.uniform_blocks[1].hlsl_register_b_n = 0;
            desc.images[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.images[0].image_type = SG_IMAGETYPE_2D;
            desc.images[0].sample_type = SG_IMAGESAMPLETYPE_FLOAT;
            desc.images[0].multisampled = false;
            desc.images[0].hlsl_register_t_n = 0;
            desc.samplers[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.samplers[0].sampler_type = SG_SAMPLERTYPE_FILTERING;
            desc.samplers[0].hlsl_register_s_n = 0;
            desc.image_sampler_pairs[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.image_sampler_pairs[0].image_slot = 0;
            desc.image_sampler_pairs[0].sampler_slot = 0;
            desc.label = "sky_shader";
        }
        return &desc;
    }
    if (backend == SG_BACKEND_METAL_MACOS) {
        static sg_shader_desc desc;
        static bool valid;
        if (!valid) {
            valid = true;
            desc.vertex_func.source = (const char*)sky_vs_source_metal_macos;
            desc.vertex_func.entry = "main0";
            desc.fragment_func.source = (const char*)sky_fs_source_metal_macos;
            desc.fragment_func.entry = "main0";
            desc.attrs[0].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[1].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.uniform_blocks[0].stage = SG_SHADERSTAGE_VERTEX;
            desc.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[0].size = 64;
            desc.uniform_blocks[0].msl_buffer_n = 0;
            desc.uniform_blocks[1].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.uniform_blocks[1].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[1].size = 16;
            desc.uniform_blocks[1].msl_buffer_n = 0;
            desc.images[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.images[0].image_type = SG_IMAGETYPE_2D;
            desc.images[0].sample_type = SG_IMAGESAMPLETYPE_FLOAT;
            desc.images[0].multisampled = false;
            desc.images[0].msl_texture_n = 0;
            desc.samplers[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.samplers[0].sampler_type = SG_SAMPLERTYPE_FILTERING;
            desc.samplers[0].msl_sampler_n = 0;
            desc.image_sampler_pairs[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.image_sampler_pairs[0].image_slot = 0;
            desc.image_sampler_pairs[0].sampler_slot = 0;
            desc.label = "sky_shader";
        }
        return &desc;
    }
    if (backend == SG_BACKEND_WGPU) {
        static sg_shader_desc desc;
        static bool valid;
        if (!valid) {
            valid = true;
            desc.vertex_func.source = (const char*)sky_vs_source_wgsl;
            desc.vertex_func.entry = "main";
            desc.fragment_func.source = (const char*)sky_fs_source_wgsl;
            desc.fragment_func.entry = "main";
            desc.attrs[0].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.attrs[1].base_type = SG_SHADERATTRBASETYPE_FLOAT;
            desc.uniform_blocks[0].stage = SG_SHADERSTAGE_VERTEX;
            desc.uniform_blocks[0].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[0].size = 64;
            desc.uniform_blocks[0].wgsl_group0_binding_n = 0;
            desc.uniform_blocks[1].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.uniform_blocks[1].layout = SG_UNIFORMLAYOUT_STD140;
            desc.uniform_blocks[1].size = 16;
            desc.uniform_blocks[1].wgsl_group0_binding_n = 8;
            desc.images[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.images[0].image_type = SG_IMAGETYPE_2D;
            desc.images[0].sample_type = SG_IMAGESAMPLETYPE_FLOAT;
            desc.images[0].multisampled = false;
            desc.images[0].wgsl_group1_binding_n = 64;
            desc.samplers[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.samplers[0].sampler_type = SG_SAMPLERTYPE_FILTERING;
            desc.samplers[0].wgsl_group1_binding_n = 80;
            desc.image_sampler_pairs[0].stage = SG_SHADERSTAGE_FRAGMENT;
            desc.image_sampler_pairs[0].image_slot = 0;
            desc.image_sampler_pairs[0].sampler_slot = 0;
            desc.label = "sky_shader";
        }
        return &desc;
    }
    return 0;
}
