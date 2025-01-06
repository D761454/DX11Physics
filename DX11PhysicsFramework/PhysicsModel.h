#pragma once

#include "Transform.h"

class PhysicsModel
{
private:

protected:
	Transform* _transform;
	Vector3 _velocity;
	Vector3 _acceleration;

	Vector3 _netforce;
	float _mass = 1.0f;

public:
	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }
	Vector3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }

	void AddForce(Vector3 force) { _netforce += force; }

	PhysicsModel(Transform* transform, float mass = 1.0f);

	virtual void Update(float dt) = 0;

	bool constantAcceleration = false;
};

