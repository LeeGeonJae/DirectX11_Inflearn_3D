matrix World;
matrix View;
matrix Projection;
uint Address;
float3 LightDir;

struct VertextInput
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};

struct VertexOutput
{
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD;
    float3 normal : NORMAL;
};

VertexOutput VS(VertextInput input)
{
    VertexOutput output;
    output.position = mul(input.position, World);
    output.position = mul(output.position, View);
    output.position = mul(output.position, Projection);
    
    output.normal = mul(input.normal, (float3x3)World);
    output.uv = input.uv;

    return output;
}

// 텍스쳐
Texture2D Texture0;

// 샘플러 세팅
// Fillter = 확대/축소 일어났을 때 중간값을 처리하는 방식
// Address = UV가 우리가 원하는 범위보다 컸을 때 (1보다 클 때) 어떻게 처리할 것이냐
SamplerState Sampler0;

SamplerState SamplerAddressWrap
{
    AddressU = Wrap;
    AddressV = Wrap;
};

SamplerState SamplerAddressMirror
{

    AddressU = Mirror;
    AddressV = Mirror;
};

SamplerState SamplerAddressClamp
{
    AddressU = Clamp;
    AddressV = Clamp;
};

SamplerState SamplerAddressBorder
{
    AddressU = Border;
    AddressV = Border;

    BorderColor = float4(1.f, 0.f, 0.f, 1.f);
};


// 픽셀 셰이더
float4 PS(VertexOutput input) : SV_TARGET
{
    float3 normal = normalize(input.normal);
    float3 light = -LightDir;
    
    return Texture0.Sample(Sampler0, input.uv) * dot(light, normal);
}


// 채우는 모드를 와이어프레임으로 변환
RasterizerState FillModeWireFrame
{
    FillMode = Wireframe;
};

// 테크니크
technique11 T0
{
    pass P0
    {
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }

    pass P1
    {
        SetRasterizerState(FillModeWireFrame);
        SetVertexShader(CompileShader(vs_5_0, VS()));
        SetPixelShader(CompileShader(ps_5_0, PS()));
    }
};