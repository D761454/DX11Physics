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
	const float x = max(other.GetMin().x, min(this->GetPosition().x, other.GetMax().x));
	const float y = max(other.GetMin().y, min(this->GetPosition().y, other.GetMax().y));
	const float z = max(other.GetMin().z, min(this->GetPosition().z, other.GetMax().z));

	const float dist = (x - this->GetPosition().x) * (x - this->GetPosition().x) +
		(y - this->GetPosition().y) * (y - this->GetPosition().y) +
		(z - this->GetPosition().z) * (z - this->GetPosition().z);

	return dist < (radius * radius);
}

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