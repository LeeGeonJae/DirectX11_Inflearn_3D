#include "00. Global.fx"

// ���ؽ� ���̴�
VertexOutput VS(VertexTextureNormal input)
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

// �ȼ� ���̴�
float4 PS(VertexOutput input) : SV_TARGET
{
    float3 normal = normalize(input.normal);
    float3 light = -LightDir;
    
    //return Texture0.Sample(Sampler0, input.uv) * dot(light, normal);
    return float4(0.f, 0.f, 0.f, 1.f);

}

// ��ũ��ũ
technique11 T0
{
    PASS_VP(P0, VS, PS)
};