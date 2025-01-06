#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
private:

protected:

public:
	ParticleModel(Transform* transform, float mass = 1.0f);

	void Update(float dt);
};

