#include "AABBCollider.h"

/// <summary>
/// need manifold
/// </summary>
/// <param name="other"></param>
/// <param name="out"></param>
/// <returns></returns>
bool AABBCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	Vector3 const closestPt = Vector3(
		max(min.x, min(other.GetPosition().x, max.x)), 
		max(min.y, min(other.GetPosition().y, max.y)), 
		max(min.z, min(other.GetPosition().z, max.z)));

	// is point in sphere
	const float dist = (closestPt.x - other.GetPosition().x) * (closestPt.x - other.GetPosition().x) +
		(closestPt.y - other.GetPosition().y) * (closestPt.y - other.GetPosition().y) +
		(closestPt.z - other.GetPosition().z) * (closestPt.z - other.GetPosition().z);

	return dist < (other.GetRadius() * other.GetRadius());
}

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <param name="out"></param>
/// <returns></returns>
bool AABBCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	return (min.x <= other.max.x && max.x >= other.min.x) &&
		(min.y <= other.max.y && max.y >= other.min.y) &&
		(min.z <= other.max.z && max.z >= other.min.z);
}

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool AABBCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	return false;
}