#pragma once
#include <cstring>
#include <d3d11.h>
#include <directxmath.h>

using namespace DirectX;

struct SurfaceInfo
{
	XMFLOAT4 AmbientMtrl;
	XMFLOAT4 DiffuseMtrl;
	XMFLOAT4 SpecularMtrl;
};

struct Light
{
	XMFLOAT4 AmbientLight;
	XMFLOAT4 DiffuseLight;
	XMFLOAT4 SpecularLight;

	float SpecularPower;
	XMFLOAT3 LightVecW;
};

struct ConstantBuffer
{
	XMMATRIX World;
	XMMATRIX View;
	XMMATRIX Projection;

	SurfaceInfo surface;

	Light light;

	XMFLOAT3 EyePosW;
	float HasTexture;
};

struct SimpleVertex
{
	XMFLOAT3 Pos;
	XMFLOAT3 Normal;
	XMFLOAT2 TexC;

	bool operator<(const SimpleVertex other) const
	{
		return memcmp((void*)this, (void*)&other, sizeof(SimpleVertex)) > 0;
	};
};

struct MeshData
{
	ID3D11Buffer* VertexBuffer;
	ID3D11Buffer* IndexBuffer;
	UINT VBStride;
	UINT VBOffset;
	UINT IndexCount;
};