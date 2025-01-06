#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float mass) : PhysicsModel(transform, mass) {
	
}

void ParticleModel::Update(float dt) {
	Vector3 position = _transform->GetPosition();

	if (!constantAcceleration) {
		_acceleration += _netforce / _mass;
	}

	_velocity += (_acceleration * dt);

	position += _velocity * dt;

	_netforce = Vector3(0, 0, 0);
	_acceleration = Vector3(0, 0, 0);

	_transform->SetPosition(position);
}