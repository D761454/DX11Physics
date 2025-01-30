#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other) {
	float combinedRadii = other.radius + radius;
	Vector3 between = other.GetPosition() - this->GetPosition();

	if (between.Magnitude() < combinedRadii) {
		return true;
	}

	return false;
}

bool SphereCollider::CollidesWith(AxisAlignedBoundingBox& other) {
	Vector3 const closestPt = Vector3(
		max(other.GetMin().x, min(this->GetPosition().x, other.GetMax().x)), 
		max(other.GetMin().y, min(this->GetPosition().y, other.GetMax().y)), 
		max(other.GetMin().z, min(this->GetPosition().z, other.GetMax().z)));

	const float dist = (closestPt.x - this->GetPosition().x) * (closestPt.x - this->GetPosition().x) +
		(closestPt.y - this->GetPosition().y) * (closestPt.y - this->GetPosition().y) +
		(closestPt.z - this->GetPosition().z) * (closestPt.z - this->GetPosition().z);

	return dist < (radius * radius);
}

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool SphereCollider::CollidesWith(Plane& other) {
	float projected = other.GetNRML() * (this->GetPosition() - other.GetPosition());

	Vector3 temp = this->GetPosition() - other.GetPosition();
	temp.Normalize();
	temp.Reverse();

	Vector3 closestPtOnPlane = this->GetPosition() - (temp * projected);
	//Vector3 closestPtOnSphere = other.GetPosition() - (temp * other.GetRadius());

	const float dist = (closestPtOnPlane.x - this->GetPosition().x) * (closestPtOnPlane.x - this->GetPosition().x) +
		(closestPtOnPlane.y - this->GetPosition().y) * (closestPtOnPlane.y - this->GetPosition().y) +
		(closestPtOnPlane.z - this->GetPosition().z) * (closestPtOnPlane.z - this->GetPosition().z);

	return dist < (radius * radius);
}

float SphereCollider::CalculatePenetrationDepth(SphereCollider& other) {
	return (this->GetPosition() - other.GetPosition()).Magnitude() - this->GetRadius() - other.GetRadius();
}