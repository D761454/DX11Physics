#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
private:

protected:
	float timeAlive = 0.0f;
	float resetTime;

public:
	ParticleModel(Transform* transform, float mass = 1.0f) : PhysicsModel(transform, mass) {};
	ParticleModel(Transform* transform, float mass = 1.0f, float resetTime, Vector3 pertubation, bool invertGravity);

	void Update(float dt) override;

	void Reset();
};

