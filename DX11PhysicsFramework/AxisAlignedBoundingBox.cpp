#include "AxisAlignedBoundingBox.h"

bool AxisAlignedBoundingBox::CollidesWith(SphereCollider& other) {
	return false;
}

bool AxisAlignedBoundingBox::CollidesWith(AxisAlignedBoundingBox& other) {
	return (this->min.x <= other.max.x && this->max.x >= other.min.x) &&
		(this->min.y <= other.max.y && this->max.y >= other.min.y) &&
		(this->min.z <= other.max.z && this->max.z >= other.min.z);
}