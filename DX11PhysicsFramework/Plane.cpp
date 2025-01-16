#include "Plane.h"

bool Plane::CollidesWith(Plane& other) {
	return false;
}

bool Plane::CollidesWith(SphereCollider& other) {
	float projected = normal * (other.GetPosition() - this->GetPosition());

	Vector3 temp = other.GetPosition() - this->GetPosition();
	temp.Normalize();
	temp.Reverse();

	Vector3 closestPtOnPlane = other.GetPosition() - (temp * projected);
	//Vector3 closestPtOnSphere = other.GetPosition() - (temp * other.GetRadius());

	const float dist = (closestPtOnPlane.x - other.GetPosition().x) * (closestPtOnPlane.x - other.GetPosition().x) +
		(closestPtOnPlane.y - other.GetPosition().y) * (closestPtOnPlane.y - other.GetPosition().y) +
		(closestPtOnPlane.z - other.GetPosition().z) * (closestPtOnPlane.z - other.GetPosition().z);

	return dist < (other.GetRadius() * other.GetRadius());
}

bool Plane::CollidesWith(AxisAlignedBoundingBox& other) {
	return false;
}

