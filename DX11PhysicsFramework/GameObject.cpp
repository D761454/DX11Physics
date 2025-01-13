#include "GameObject.h"

GameObject::GameObject(string type, Appearance* appearance)
{
	_transform = new Transform(Vector3(), Vector3(), Vector3(1.0f, 1.0f, 1.0f));

	_physics = new RigidBodyModel(_transform);

	_appearance = appearance;
}

GameObject::~GameObject()
{
	_parent = nullptr;
}

void GameObject::Update(float dt)
{
	_physics->Update(dt);

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
