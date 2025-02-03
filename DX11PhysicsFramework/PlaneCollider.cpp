#include "PlaneCollider.h"

bool PlaneCollider::CollidesWith(PlaneCollider& other, CollisionManifold& out) {
	return false;
}

bool PlaneCollider::CollidesWith(SphereCollider& other, CollisionManifold& out) {
	
}

bool PlaneCollider::CollidesWith(AABBCollider& other, CollisionManifold& out) {
	return false;
}

