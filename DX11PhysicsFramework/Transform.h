#pragma once

#include "GameObject.h"
#include <directxmath.h>
#include <d3d11_1.h>

using namespace DirectX;

class Transform
{
private:
	XMFLOAT3 _position;
	XMFLOAT3 _rotation;
	XMFLOAT3 _scale;

	GameObject* _parent = nullptr;

	XMFLOAT4X4 _world;

public:
	Transform(XMFLOAT3 position, XMFLOAT3 rotation, XMFLOAT3 scale);

	~Transform();

	// Setters and Getters for position/rotation/scale
	void SetPosition(XMFLOAT3 position) { _position = position; }
	void SetPosition(float x, float y, float z) { _position.x = x; _position.y = y; _position.z = z; }

	XMFLOAT3 GetPosition() const { return _position; }

	void SetScale(XMFLOAT3 scale) { _scale = scale; }
	void SetScale(float x, float y, float z) { _scale.x = x; _scale.y = y; _scale.z = z; }

	XMFLOAT3 GetScale() const { return _scale; }

	void SetRotation(XMFLOAT3 rotation) { _rotation = rotation; }
	void SetRotation(float x, float y, float z) { _rotation.x = x; _rotation.y = y; _rotation.z = z; }

	XMFLOAT3 GetRotation() const { return _rotation; }

	XMMATRIX GetWorldMatrix() const { return XMLoadFloat4x4(&_world); }

	void SetParent(GameObject* parent) { _parent = parent; }

	void Move(XMFLOAT3 direction);

	void Update(float dt);
};

