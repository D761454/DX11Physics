#pragma once

#include "Transform.h"

class PhysicsModel
{
private:

protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;

public:
	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }
	Vector3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }

	PhysicsModel(Transform* transform);

	void Update(float dt);

	bool accelerate = false;
};

