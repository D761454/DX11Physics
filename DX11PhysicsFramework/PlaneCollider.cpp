#include "PlaneCollider.h"

bool PlaneCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	return false;
}

bool PlaneCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	Vector3 toPlane = GetNRML(); toPlane.Reverse(); toPlane.Normalize();

	Vector3 pos = other.GetPosition();
	Vector3 nrml = GetNRML();
	nrml.Normalize();

	float distance = nrml * pos / sqrt(nrml * nrml);

	if (distance < other.GetRadius()) {
		out.collisionNormal = GetNRML();
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = other.GetPosition() + (toPlane * distance);
		out.points[0].PenetrationDepth = fabs(other.GetRadius() - distance);

		return true;
	}

	return false;
}

bool PlaneCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	Vector3 nrml = GetNRML();
	nrml.Normalize();

	float radius = other.GetHalfExtents() * nrml;

	// distance of box center from plane
	float dist = nrml * other.GetPosition() / sqrt(nrml * nrml);

	if (dist < radius) {
		out.collisionNormal = nrml;
		out.collisionNormal.Normalize();
		nrml.Reverse();
		out.contactPointCount = 1;
		out.points[0].Position = other.GetPosition() + (nrml * dist);
		out.points[0].PenetrationDepth = fabs(radius - dist);

		return true;
	}

	return false;
}

