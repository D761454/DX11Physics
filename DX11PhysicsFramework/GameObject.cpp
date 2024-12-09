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
	if (_parent != nullptr)
	{
		_transform->Update(dt, _parent->GetTransform());
	}
	else {
		_transform->Update(dt);
	}
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
