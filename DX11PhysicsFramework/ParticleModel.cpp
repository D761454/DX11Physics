#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform) : PhysicsModel(transform) {
	_transform = transform;
}

void ParticleModel::Update(float dt) {
	Vector3 position = _transform->GetPosition();
	if (accelerate) {
		_velocity += (_acceleration * dt);
	}
	position += _velocity * dt;
	_transform->SetPosition(position);
}