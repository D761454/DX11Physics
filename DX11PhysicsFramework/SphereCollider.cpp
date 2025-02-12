#include "SphereCollider.h"

bool SphereCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	float combinedRadii = other.radius + radius;
	Vector3 between = other.GetPosition() - GetPosition();

	if (between.Magnitude() < combinedRadii) {
		out.collisionNormal = between;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * radius);
		out.points[0].PenetrationDepth = fabs(between.Magnitude() - combinedRadii);
		// doing this in collides with means no specific collider info needed in main program, can use depth of 0 for more complex solves before implementation - AABB, OOBB
		return true;
	}

	return false;
}

/// <summary>
/// swap to using half extents
/// </summary>
/// <param name="other"></param>
/// <param name="out"></param>
/// <returns></returns>
bool SphereCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	// box closest pt to sphere
	Vector3 closestPt = Vector3(
		max(other.GetMin().x, min(GetPosition().x, other.GetMax().x)), 
		max(other.GetMin().y, min(GetPosition().y, other.GetMax().y)), 
		max(other.GetMin().z, min(GetPosition().z, other.GetMax().z)));

	Vector3 between = closestPt - GetPosition();

	const float dist = between.Magnitude();

	if (dist < radius) {
		out.collisionNormal = between;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * radius);
		out.points[0].PenetrationDepth = fabs(dist - radius);

		return true;
	}

	return false;
}

bool SphereCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	Vector3 toPlane = other.GetNRML(); toPlane.Reverse(); toPlane.Normalize(); 

	Vector3 pos = GetPosition();
	Vector3 nrml = other.GetNRML();
	nrml.Normalize();

	float distance = nrml * pos / sqrt(nrml * nrml);

	if (distance < radius) {
		out.collisionNormal = toPlane;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * radius);
		out.points[0].PenetrationDepth = fabs(distance - radius);

		return true;
	}

	return false;
}