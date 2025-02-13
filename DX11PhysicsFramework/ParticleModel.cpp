#include "ParticleModel.h"

ParticleModel::ParticleModel(Transform* transform, float resetTime, Vector3 pertubation, bool invertGravity) : PhysicsModel(transform) {
	this->resetTime = resetTime;
	this->perturbation = pertubation;
}

void ParticleModel::Update(float dt) {
	timeAlive += dt;

	if (timeAlive > resetTime) {
		Reset();
	}

	PhysicsModel::Update(dt);
}

void ParticleModel::Reset() {

}

void ParticleModel::AddRelativeForce(Vector3 force, Vector3 point) {
	AddForce(force);
}
