#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float mass = 1.0f, float resetTime, Vector3 pertubation, bool invertGravity) {
	this->resetTime = resetTime;
}

void ParticleModel::Update(float dt) {
	timeAlive += dt;

	if (timeAlive > resetTime) {
		Reset();
	}

	PhysicsModel::Update(dt);
}