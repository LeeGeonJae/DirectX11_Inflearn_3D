#include "00. Global.fx"

// 버텍스 셰이더
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

// 텍스쳐
Texture2D Texture0;

// 픽셀 셰이더
float4 PS(VertexOutput input) : SV_TARGET
{
    float3 normal = normalize(input.normal);
    float3 light = -LightDir;
    
    //return Texture0.Sample(Sampler0, input.uv) * dot(light, normal);
    return float4(0.f, 0.f, 0.f, 1.f);

}

// 테크니크
technique11 T0
{
    PASS_VP(P0, VS, PS)
};