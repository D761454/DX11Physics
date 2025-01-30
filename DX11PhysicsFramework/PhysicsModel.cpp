#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform) {
	_transform = transform;
}

void PhysicsModel::Update(float dt) {
	if (_mass == 0) {
		return;
	}

	Vector3 position = _transform->GetPosition();
	if (_collider) {
		_collider->Update(dt);
	}

	if (simulateGravity) {
		_netforce += GravityForce();
	}

	_netforce += DragForce();
	
	//_netforce += FrictionForce(); // causes errors with interpenetrations

	if (!constantAcceleration) {
		_acceleration += _netforce / _mass;
	}

	_velocity += (_acceleration * dt);

	position += _velocity * dt;

	_netforce = Vector3(0, 0, 0);

	if (!constantAcceleration) {
		_acceleration = Vector3(0, 0, 0);
	}

	_transform->SetPosition(position);
}

void PhysicsModel::AddRelativeForce(Vector3 force, Vector3 point) {
	AddForce(force);
}