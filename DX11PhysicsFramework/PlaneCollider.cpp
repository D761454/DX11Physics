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
	return false;
}

