#include "RigidBodyModel.h"

RigidBodyModel::RigidBodyModel(Transform* transform) : PhysicsModel(transform) {
	XMStoreFloat3x3(&_inertiaTensorMatrix, XMMatrixIdentity());

	// comeback to clean up later either via a function or smth
	/*B* B_static_cast(A * item)
	{
		return static_cast<B*>(item);
	}

	A* item = new B();
	B_static_cast(item)->funtion_in_B();*/

	SphereCollider* temp = dynamic_cast<SphereCollider*>(GetCollider());

	if (temp != nullptr) {
		SetInertiaTensor(*temp);
	}
	
	AABBCollider* temp2 = dynamic_cast<AABBCollider*>(GetCollider());

	if (temp2 != nullptr) {
		SetInertiaTensor(*temp2);
	}
}

void RigidBodyModel::SetInertiaTensor(SphereCollider& collider) {
	_inertiaTensorMatrix._11 = (2 / 5) * GetMass() * (collider.GetRadius() * collider.GetRadius());
	_inertiaTensorMatrix._22 = (2 / 5) * GetMass() * (collider.GetRadius() * collider.GetRadius());
	_inertiaTensorMatrix._33 = (2 / 5) * GetMass() * (collider.GetRadius() * collider.GetRadius());
}

void RigidBodyModel::SetInertiaTensor(AABBCollider& collider) {
	_inertiaTensorMatrix._11 = (1 / 12) * GetMass() * ((collider.GetHalfExtents().y * collider.GetHalfExtents().y) + (collider.GetHalfExtents().z * collider.GetHalfExtents().z));
	_inertiaTensorMatrix._22 = (1 / 12) * GetMass() * ((collider.GetHalfExtents().x * collider.GetHalfExtents().x) + (collider.GetHalfExtents().z * collider.GetHalfExtents().z));;
	_inertiaTensorMatrix._33 = (1 / 12) * GetMass() * ((collider.GetHalfExtents().x * collider.GetHalfExtents().x) + (collider.GetHalfExtents().y * collider.GetHalfExtents().y));;
}

void RigidBodyModel::CalculateAngularVelocity(float deltaTime) {
	if (_mass == 0) {
		return;
	}

	XMMATRIX inverseInertiaTensor = XMMatrixInverse(nullptr, XMLoadFloat3x3(&_inertiaTensorMatrix));
	XMVECTOR torque = XMVectorSet(_torque.x, _torque.y, _torque.z, 0);
	XMVECTOR angularAcceleration = XMVector3Transform(torque, inverseInertiaTensor);

	XMFLOAT3 temp;
	XMStoreFloat3(&temp, angularAcceleration);

	_angularVelocity += Vector3(temp.x, temp.y, temp.z) * deltaTime;
}

void RigidBodyModel::Update(float dt) {
	PhysicsModel::Update(dt);

	CalculateAngularVelocity(dt);

	Quaternion orientation = _transform->GetOrientation();

	orientation += (orientation * _angularVelocity) * 0.5f * dt;

	if (orientation.Magnitude() != 0) {
		orientation /= orientation.Magnitude();
	}
	_transform->SetOrientation(orientation);

	_angularVelocity *= pow(_angularDamping, dt);

	// prevents infinite rotation
	_torque = Vector3();
}

void RigidBodyModel::AddRelativeForce(Vector3 force, Vector3 point) {
	AddForce(force);
	_torque = point ^ force;
}