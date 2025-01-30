#include "AxisAlignedBoundingBox.h"

bool AxisAlignedBoundingBox::CollidesWith(SphereCollider& other) {
	Vector3 const closestPt = Vector3(
		max(this->min.x, min(other.GetPosition().x, this->max.x)), 
		max(this->min.y, min(other.GetPosition().y, this->max.y)), 
		max(this->min.z, min(other.GetPosition().z, this->max.z)));

	// is point in sphere
	const float dist = (closestPt.x - other.GetPosition().x) * (closestPt.x - other.GetPosition().x) +
		(closestPt.y - other.GetPosition().y) * (closestPt.y - other.GetPosition().y) +
		(closestPt.z - other.GetPosition().z) * (closestPt.z - other.GetPosition().z);

	return dist < (other.GetRadius() * other.GetRadius());
}

bool AxisAlignedBoundingBox::CollidesWith(AxisAlignedBoundingBox& other) {
	return (this->min.x <= other.max.x && this->max.x >= other.min.x) &&
		(this->min.y <= other.max.y && this->max.y >= other.min.y) &&
		(this->min.z <= other.max.z && this->max.z >= other.min.z);
}

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool AxisAlignedBoundingBox::CollidesWith(Plane& other) {
	return false;
}

/// <summary>
/// WIP		-- remember - AA so no rotation in collidable space
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
float AxisAlignedBoundingBox::CalculatePenetrationDepth(AxisAlignedBoundingBox& other) {
	// closest pt
	Vector3 const closestPt = Vector3(
		max(this->min.x, min(other.GetPosition().x, this->max.x)), 
		max(this->min.y, min(other.GetPosition().y, this->max.y)), 
		max(this->min.z, min(other.GetPosition().z, this->max.z)));

	const float dist = (other.GetPosition() - closestPt).Magnitude();

	return 0;
}