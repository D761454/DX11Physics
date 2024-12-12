#pragma once

#include "Transform.h"

class PhysicsModel
{
private:

protected:
	Transform* _transform;
	Vector3 _velocity;

public:
	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }

	PhysicsModel(Transform* transform);

	void Update(float dt);
};

