#pragma once

#include "Transform.h"
#include "SphereCollider.h"
#include "AxisAlignedBoundingBox.h"
#include "Plane.h"
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
	float GetMass() const { return _mass; }

	void AddForce(Vector3 force) { _netforce += force; }
	Vector3 GravityForce() { 
		if (_invertGravity) {
			return Vector3(0, 9.81f * _mass, 0);
		}
		return Vector3(0, -9.81f * _mass, 0); }

	Vector3 DragForce() { 
		float force = 0.5f * 1.0f * 1.05f * 1.0f * (_velocity.Magnitude() * _velocity.Magnitude());
		Vector3 temp = _velocity;
		temp.Reverse();
		temp.Normalize();
		return temp * force;
	}
	Vector3 FrictionForce() {
		if (_transform->GetPosition().y <= 0.5f) {
			float force = 1.0f * (9.81f * _mass); // edit 1 to later be dependant on colliding object
			Vector3 temp = _velocity;
			temp.Reverse();
			temp.Normalize();
			return temp * force;
		}
		return Vector3(0, 0, 0);
	}

	void ApplyImpulse(Vector3 impulse) { _velocity += impulse; }

	bool IsCollideable() const { return _collider != nullptr; }
	Collider* GetCollider() const { return _collider; }
	void SetCollider(Collider* collider) { _collider = collider; }

	PhysicsModel(Transform* transform);

	virtual void Update(float dt);

	bool constantAcceleration = false;
	bool simulateGravity = true;
};

