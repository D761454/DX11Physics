#include "RigidBodyModel.h"

RigidBodyModel::RigidBodyModel(Transform* transform) : PhysicsModel(transform) {
	XMStoreFloat3x3(&_inertiaTensorMatrix, XMMatrixIdentity());

	SphereCollider* temp = dynamic_cast<SphereCollider*>(GetCollider());

	// comeback to clean up later either via a function or smth
	if (temp != nullptr) {
		SetInertiaTensor(*temp);
	}
	
	AxisAlignedBoundingBox* temp = dynamic_cast<AxisAlignedBoundingBox*>(GetCollider());

	if (temp != nullptr) {
		SetInertiaTensor(*temp);
	}
}

void RigidBodyModel::SetInertiaTensor(SphereCollider& collider) {
	_inertiaTensorMatrix._11 = 2 / 5 * GetMass() * (collider.GetRadius() * collider.GetRadius());
}

void RigidBodyModel::SetInertiaTensor(AxisAlignedBoundingBox& collider) {

}

void RigidBodyModel::Update(float dt) {
	PhysicsModel::Update(dt);
}

void RigidBodyModel::AddRelativeForce(Vector3 force, Vector3 point) {
	AddForce(force);
	_torque = point ^ force;
}