#ifndef _GLOBAL_FX_
#define _GLOBAL_FX_

////////////////////
// ConstantBuffer //
////////////////////

cbuffer GlobalBuffer
{
    matrix View;
    matrix Projection;
    matrix ViewProejction;
};

cbuffer TransformBuffer
{
    matrix World;
};

float3 LightDir;

// ÅØ½ºÃÄ
Texture2D Texture0;

////////////////
// VertexData //
////////////////

struct Vertex
{
    float4 position : POSITION;
};

struct VertexTexture
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
};

struct VertexColor
{
    float4 position : POSITIONT;
    float4 color : COLOR;
};

struct VertexTextureNormal
{
    float4 position : POSITIONT;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};

//////////////////
// VertexOutput //
//////////////////

struct VertexOutput
{
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};

//////////////////
// SamplerState //
//////////////////

SamplerState SamplerAddressWrap
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;
    AddressV = Wrap;
};

SamplerState SamplerPointWrap
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Wrap;
    AddressV = Wrap;
};

SamplerState SamplerAddressMirror
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Mirror;
    AddressV = Mirror;
};

SamplerState SamplerAddressClamp
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Clamp;
    AddressV = Clamp;
};

SamplerState SamplerAddressBorder
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Border;
    AddressV = Border;

    BorderColor = float4(1.f, 0.f, 0.f, 1.f);
};

/////////////////////
// RasterizerState //
/////////////////////

RasterizerState FillModeWireFrame
{
    FillMode = WireFrame;
};

///////////
// Macro //
///////////

#define PASS_VP(name, vs, ps)                       \
pass name                                           \
{                                                   \
    SetVertexShader(CompileShader(vs_5_0, vs()));   \
    SetPixelShader(CompileShader(ps_5_0, ps()));    \
}

//////////////
// Function //
//////////////

#endif