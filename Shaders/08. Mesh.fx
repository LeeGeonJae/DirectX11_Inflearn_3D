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

// �ؽ���
Texture2D Texture0;

// ���÷� ����
// Fillter = Ȯ��/��� �Ͼ�� �� �߰����� ó���ϴ� ���
// Address = UV�� �츮�� ���ϴ� �������� ���� �� (1���� Ŭ ��) ��� ó���� ���̳�
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


// �ȼ� ���̴�
float4 PS(VertexOutput input) : SV_TARGET
{
    float3 normal = normalize(input.normal);
    float3 light = -LightDir;
    
    return Texture0.Sample(Sampler0, input.uv) * dot(light, normal);
}


// ä��� ��带 ���̾����������� ��ȯ
RasterizerState FillModeWireFrame
{
    FillMode = Wireframe;
};

// ��ũ��ũ
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