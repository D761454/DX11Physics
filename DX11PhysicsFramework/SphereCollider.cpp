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

bool SphereCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	// box closest pt to sphere
	Vector3 closestPt = Vector3(
		max(other.GetMin().x, min(GetPosition().x, other.GetMax().x)), 
		max(other.GetMin().y, min(GetPosition().y, other.GetMax().y)), 
		max(other.GetMin().z, min(GetPosition().z, other.GetMax().z)));

	Vector3 between = closestPt - GetPosition();

	const float dist = between.Magnitude();

	/*const float dist = (closestPt.x - GetPosition().x) * (closestPt.x - GetPosition().x) +
		(closestPt.y - GetPosition().y) * (closestPt.y - GetPosition().y) +
		(closestPt.z - GetPosition().z) * (closestPt.z - GetPosition().z);*/

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

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool SphereCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	// returns plane facing axis pos e.g. y pos / returns sphere pos on plane facing axis
	const float distToPlane = (other.GetPosition() * other.GetNRML()) - (GetPosition() * other.GetNRML());

	Vector3 between = (GetPosition() - (other.GetNRML() * distToPlane)) - GetPosition();

	if (distToPlane < radius) {
		out.collisionNormal = between;
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * radius);
		out.points[0].PenetrationDepth = fabs(distToPlane - radius);

		return true;
	}

	return false;
}

float SphereCollider::CalculatePenetrationDepth(SphereCollider& other, CollisionManifold& out) {
	return (GetPosition() - other.GetPosition()).Magnitude() - GetRadius() - other.GetRadius();
}