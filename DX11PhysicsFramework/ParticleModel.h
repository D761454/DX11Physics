#pragma once
#include "PhysicsModel.h"

class ParticleModel : public PhysicsModel
{
private:

protected:

public:
	ParticleModel(Transform* transform);

	void Update(float dt);
};

