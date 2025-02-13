#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
private:

protected:
	float timeAlive = 0.0f;
	float resetTime;

	Vector3 perturbation = Vector3(0, 0, 0);

public:
	ParticleModel(Transform* transform) : PhysicsModel(transform) {};
	ParticleModel(Transform* transform, float resetTime, Vector3 pertubation, bool invertGravity);

	virtual void AddRelativeForce(Vector3 force, Vector3 point) override;

	void Update(float dt) override;

	void Reset();
};

