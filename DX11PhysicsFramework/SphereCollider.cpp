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
	return false;
}