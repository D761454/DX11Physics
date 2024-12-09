#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance)
{
	_transform = new Transform(XMFLOAT3(), XMFLOAT3(), XMFLOAT3(1.0f, 1.0f, 1.0f));

	_appearance = appearance;
}

GameObject::~GameObject()
{

}

void GameObject::Update(float dt)
{
	_transform->Update(dt);
}

void GameObject::Draw(ID3D11DeviceContext * pImmediateContext)
{
	_appearance->Draw(pImmediateContext);
}
