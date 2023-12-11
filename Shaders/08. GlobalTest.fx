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
    PASS_VP(P0, VS, PS)
};