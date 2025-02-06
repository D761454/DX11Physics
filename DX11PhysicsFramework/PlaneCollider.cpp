#include "PlaneCollider.h"

bool PlaneCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	return false;
}

bool PlaneCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	Vector3 toPlane = GetNRML(); toPlane.Reverse(); toPlane.Normalize();

	Vector3 sphereIntersectPt = other.GetPosition() + toPlane;

	Vector3 pos = other.GetPosition();
	Vector3 nrml = GetNRML();
	nrml.Normalize();

	//float distance = (GetPosition() - other.GetPosition()) * toPlane;
	float distance = nrml * pos / sqrt(nrml * nrml);

	if (distance < other.GetRadius()) {
		out.collisionNormal = toPlane;
		out.collisionNormal.Reverse();
		out.collisionNormal.Normalize();
		out.contactPointCount = 1;
		out.points[0].Position = GetPosition() + (out.collisionNormal * other.GetRadius());
		out.points[0].PenetrationDepth = fabs(distance - other.GetRadius());

		return true;
	}

	return false;
}

bool PlaneCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	return false;
}

