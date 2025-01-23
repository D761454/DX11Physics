#include "Transform.h"

Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale) {
	_position = position; 
	SetRotation(rotation); 
	_scale = scale; 
}

Transform::~Transform() {
	
}

void Transform::Move(Vector3 direction) {
	_position.x += direction.x;
	_position.y += direction.y;
	_position.z += direction.z;
}

void Transform::Update(float dt) {
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	Quaternion temp = GetOrientation();
	XMMATRIX rotation = XMMatrixRotationQuaternion(XMVectorSet(temp.GetVector().x, temp.GetVector().y, temp.GetVector().z, temp.GetScalar()));
	//XMMatrixRotationX(GetRotation().x) * XMMatrixRotationY(GetRotation().y) * XMMatrixRotationZ(GetRotation().z);
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);
}

void Transform::Update(float dt, Transform* parent) {
	// Calculate world matrix
	XMMATRIX scale = XMMatrixScaling(_scale.x, _scale.y, _scale.z);
	Quaternion temp = GetOrientation();
	XMMATRIX rotation = XMMatrixRotationQuaternion(XMVectorSet(temp.GetVector().x, temp.GetVector().y, temp.GetVector().z, temp.GetScalar()));
	XMMATRIX translation = XMMatrixTranslation(_position.x, _position.y, _position.z);

	XMStoreFloat4x4(&_world, scale * rotation * translation);

	XMStoreFloat4x4(&_world, this->GetWorldMatrix() * parent->GetWorldMatrix());
}