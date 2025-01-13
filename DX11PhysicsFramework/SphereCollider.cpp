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
	return false;
}