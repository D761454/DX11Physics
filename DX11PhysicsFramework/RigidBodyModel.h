#pragma once
#include "PhysicsModel.h"

class RigidBodyModel : public PhysicsModel
{
private:

protected:
	Vector3 _torque;
	XMFLOAT3X3 _inertiaTensorMatrix;
	float _angularDamping = 0.99f;

public:
	RigidBodyModel(Transform* transform);

	void SetInertiaTensor(SphereCollider& collider);
	void SetInertiaTensor(AxisAlignedBoundingBox& collider);

	virtual void AddRelativeForce(Vector3 force, Vector3 point) override;

	void Update(float dt) override;
};

