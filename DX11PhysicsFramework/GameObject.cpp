#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance)
{
	_transform = new Transform(XMFLOAT3(), XMFLOAT3(), XMFLOAT3(1.0f, 1.0f, 1.0f));

	_appearance = appearance;
}

GameObject::~GameObject()
{
	_parent = nullptr;
}

void GameObject::Update(float dt)
{
	_transform->Update(dt);

	if (_parent != nullptr)
	{
		//XMStoreFloat4x4(&_world, this->GetWorldMatrix() * _parent->GetTransform()->GetWorldMatrix());
		XMStoreFloat4x4(_transform->GetWorld(), this->_transform->GetWorldMatrix() * _parent->GetTransform()->GetWorldMatrix());
	}
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
