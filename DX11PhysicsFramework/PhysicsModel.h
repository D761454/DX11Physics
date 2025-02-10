#pragma once

#include "Transform.h"
#include "SphereCollider.h"
#include "AABBCollider.h"
#include "PlaneCollider.h"
#include "Debug.h"

class PhysicsModel abstract
{
private:

protected:
	Transform* _transform;
	Collider* _collider = nullptr;
	Vector3 _velocity = Vector3(0, 0, 0);
	Vector3 _acceleration = Vector3(0, 0, 0);

	Vector3 _netforce = Vector3(0, 0, 0);
	float _mass = 1.0f;

	bool _invertGravity = false;

public:
	Vector3 GetVelocity() const { return _velocity; }
	void SetVelocity(Vector3 velocity) { _velocity = velocity; }
	Vector3 GetAcceleration() const { return _acceleration; }
	void SetAcceleration(Vector3 acceleration) { _acceleration = acceleration; }

	void SetMass(float mass) { _mass = mass; };
	float GetMass() const { return _mass; }
	float GetInverseMass() const { if (_mass == 0) { return 0.0f; } return 1.0f / _mass; }

	void AddForce(Vector3 force) { _netforce += force; }
	Vector3 GravityForce() { 
		if (_invertGravity) {
			return Vector3(0, 9.81f * _mass, 0);
		}
		return Vector3(0, -9.81f * _mass, 0); }

	Vector3 DragForce() { 
		// |F| = 0.5 p Cd A |V|2
		float force = 0.5f * 1.293 * 0.47f * 1.0f * (_velocity.Magnitude() * _velocity.Magnitude());
		Vector3 temp = _velocity;
		temp.Reverse();
		temp.Normalize();
		return temp * force;
	}

	Vector3 FrictionForce() {
		// Rf = 1/2 p V2 S Cf
		float force = 0.5f * 0.5f * (_velocity * _velocity) * 10.0f * 0.6f;

		Vector3 temp = _velocity;
		temp.Reverse();
		temp.Normalize();

		return temp * force;
	}

	void ApplyImpulse(Vector3 impulse) { _velocity += impulse; }

	virtual void AddRelativeForce(Vector3 force, Vector3 point);

	bool IsCollideable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }
	void SetCollider(Collider* collider) { _collider = collider; }

	PhysicsModel(Transform* transform);

	virtual void Update(float dt);

	bool constantAcceleration = false;
	bool simulateGravity = true;
};

