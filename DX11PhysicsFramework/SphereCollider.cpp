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
		// doing this in collides with means no specific collider info needed in main program
		return true;
	}

	return false;
}

bool SphereCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	Vector3 const closestPt = Vector3(
		max(other.GetMin().x, min(GetPosition().x, other.GetMax().x)), 
		max(other.GetMin().y, min(GetPosition().y, other.GetMax().y)), 
		max(other.GetMin().z, min(GetPosition().z, other.GetMax().z)));

	const float dist = (closestPt.x - GetPosition().x) * (closestPt.x - GetPosition().x) +
		(closestPt.y - GetPosition().y) * (closestPt.y - GetPosition().y) +
		(closestPt.z - GetPosition().z) * (closestPt.z - GetPosition().z);

	return dist < (radius * radius);
}

/// <summary>
/// WIP
/// </summary>
/// <param name="other"></param>
/// <returns></returns>
bool SphereCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	float projected = other.GetNRML() * (GetPosition() - other.GetPosition());

	Vector3 temp = GetPosition() - other.GetPosition();
	temp.Normalize();
	temp.Reverse();

	Vector3 closestPtOnPlane = GetPosition() - (temp * projected);
	//Vector3 closestPtOnSphere = other.GetPosition() - (temp * other.GetRadius());

	const float dist = (closestPtOnPlane.x - GetPosition().x) * (closestPtOnPlane.x - GetPosition().x) +
		(closestPtOnPlane.y - GetPosition().y) * (closestPtOnPlane.y - GetPosition().y) +
		(closestPtOnPlane.z - GetPosition().z) * (closestPtOnPlane.z - GetPosition().z);

	return dist < (radius * radius);
}

float SphereCollider::CalculatePenetrationDepth(SphereCollider& other, CollisionManifold& out) {
	return (GetPosition() - other.GetPosition()).Magnitude() - GetRadius() - other.GetRadius();
}