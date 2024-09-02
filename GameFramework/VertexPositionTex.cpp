#include "pch.h"
#include "VertexPositionTex.h"
#include "Game.h"
#include "../FbxLoader/MeshVertex.h"


ID3D11InputLayout* VertexPositionTex::GetLayout(ID3DBlob* signature)
{
	// Layout from VertexShader input signature
	D3D11_INPUT_ELEMENT_DESC inputElements[] = {
		D3D11_INPUT_ELEMENT_DESC {
			"POSITION",
			0,
			DXGI_FORMAT_R32G32B32A32_FLOAT,
			0,
			0,
			D3D11_INPUT_PER_VERTEX_DATA,
			0},
		D3D11_INPUT_ELEMENT_DESC {
			"TEXCOORD",
			0,
			DXGI_FORMAT_R32G32B32A32_FLOAT,
			0,
			D3D11_APPEND_ALIGNED_ELEMENT,
			D3D11_INPUT_PER_VERTEX_DATA,
			0},
	};

	ID3D11InputLayout* layout;
	Game::Instance->Device->CreateInputLayout(inputElements, 2, signature->GetBufferPointer(), signature->GetBufferSize(), &layout);

	return layout;
}


void VertexPositionTex::Convert(const FbxNative::MeshVertex& v)
{
	Position = Vector4(v.Position.x, v.Position.y, v.Position.z, 1.0f);
	Tex = Vector4(v.TexCoord0.x, v.TexCoord0.y, v.TexCoord1.x, v.TexCoord1.y);
}
