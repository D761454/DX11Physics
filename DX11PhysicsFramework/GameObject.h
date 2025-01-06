#pragma once

#include "Transform.h"
#include "Appearance.h"
#include "ParticleModel.h"
#include "Structures.h"
#include <string>

using namespace DirectX;
using namespace std;

class GameObject
{
public:
	GameObject(string type, Appearance* appearance);
	~GameObject();

	string GetType() const { return _type; }

	Transform* GetTransform() { return _transform; }
	Appearance* GetAppearance() { return _appearance; }
	PhysicsModel* GetPhysicsModel() { return _physics; }

	void SetParent(GameObject* parent) { _parent = parent; }

	void Update(float dt);
	void Draw(ID3D11DeviceContext * pImmediateContext);

private:

	Transform* _transform;
	Appearance* _appearance;
	ParticleModel* _physics;

	string _type;

	GameObject* _parent = nullptr;
};

