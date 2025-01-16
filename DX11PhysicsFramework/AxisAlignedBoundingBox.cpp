#include "AxisAlignedBoundingBox.h"

bool AxisAlignedBoundingBox::CollidesWith(SphereCollider& other) {
	const float x = max(this->min.x, min(other.GetPosition().x, this->max.x));
	const float y = max(this->min.y, min(other.GetPosition().y, this->max.y));
	const float z = max(this->min.z, min(other.GetPosition().z, this->max.z));

	const float dist = (x - other.GetPosition().x) * (x - other.GetPosition().x) +
		(y - other.GetPosition().y) * (y - other.GetPosition().y) +
		(z - other.GetPosition().z) * (z - other.GetPosition().z);

	return dist < (other.GetRadius() * other.GetRadius());
}

bool AxisAlignedBoundingBox::CollidesWith(AxisAlignedBoundingBox& other) {
	return (this->min.x <= other.max.x && this->max.x >= other.min.x) &&
		(this->min.y <= other.max.y && this->max.y >= other.min.y) &&
		(this->min.z <= other.max.z && this->max.z >= other.min.z);
}

bool AxisAlignedBoundingBox::CollidesWith(Plane& other) {
	return false;
}