#include "AABBCollider.h"

bool AABBCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	Vector3 pos = GetPosition();

	Vector3 closestPt = Vector3(
		max(pos.x - halfExtents.x, min(other.GetPosition().x, pos.x + halfExtents.x)),
		max(pos.y - halfExtents.y, min(other.GetPosition().y, pos.y + halfExtents.y)),
		max(pos.z - halfExtents.z, min(other.GetPosition().z, pos.z + halfExtents.z)));

	Vector3 between = closestPt - other.GetPosition();

	const float dist = between.Magnitude();

	between.Normalize();

	float radius = between * halfExtents;

	if (dist < other.GetRadius()) {
		out.collisionNormal = between;
		out.collisionNormal.Reverse();
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = other.GetPosition() + (between * other.GetRadius());
		out.points[0].PenetrationDepth = fabs(dist - other.GetRadius());

		return true;
	}

	return false;
}

bool AABBCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	/*return (min.x <= other.max.x && max.x >= other.min.x) &&
		(min.y <= other.max.y && max.y >= other.min.y) &&
		(min.z <= other.max.z && max.z >= other.min.z);*/

	// with half extents = 1 and pos = 3 and 2
	// A3 - B2 = dist 1 between x s,
	// 1 < A1 + B1 = dist 2 combined half extents
	// overlap on x		-	repeat

	Vector3 diff = GetPosition() - other.GetPosition();
	Vector3 combinedExtents = halfExtents + other.GetHalfExtents();

	Vector3 nrml = diff;
	nrml.Normalize();

	float radius = halfExtents * nrml;

	if (fabs(diff.x) < combinedExtents.x && fabs(diff.y) < combinedExtents.y && fabs(diff.z) < combinedExtents.z) {

		out.collisionNormal = nrml;
		out.collisionNormal.Reverse();
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (nrml * radius);
		out.points[0].PenetrationDepth = fabs(diff.Magnitude() - (radius + (other.GetHalfExtents() * nrml)));

		return true;
	}

	return false;
}

bool AABBCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	Vector3 nrml = other.GetNRML();
	nrml.Normalize();

	float radius = halfExtents * nrml;

	// distance of box center from plane
	float dist = nrml * GetPosition() / sqrt(nrml * nrml);

	if (dist < radius) {
		nrml.Reverse();
		out.collisionNormal = nrml;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * radius);
		out.points[0].PenetrationDepth = fabs(dist - radius);

		return true;
	}

	return false;
}