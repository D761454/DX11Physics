#pragma once
#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
private:

protected:
	

public:
	RigidBodyModel(Transform* transform) : PhysicsModel(transform) {};

	//void Update(float dt) override;

};

