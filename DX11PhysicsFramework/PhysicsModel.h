#pragma once

#include "Transform.h"

class PhysicsModel
{
private:

protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration = { 0.0f, 1.0f, 0.0f };

public:
	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }

	PhysicsModel(Transform* transform);

	void Update(float dt);

	bool accelerate = false;
};

