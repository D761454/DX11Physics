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
	Vector3 GravityForce() { return Vector3(0, -9.81f * _mass, 0); }

	Vector3 DragForce() { 
		float force = 0.5f * 1.0f * 1.05f * 1.0f * (_velocity.Magnitude() * _velocity.Magnitude());
		Vector3 temp = _velocity;
		temp.Reverse();
		temp.Normalize();
		return temp * force;
	}
	Vector3 FrictionForce() {
		float force = 1.0f * 9.81f; // edit 1 to later be dependant on colliding object
		Vector3 temp = _velocity;
		temp.Reverse();
		temp.Normalize();
		return temp * force;
	}

	PhysicsModel(Transform* transform, float mass = 1.0f);

	virtual void Update(float dt);

	bool constantAcceleration = false;
	bool simulateGravity = true;
};

