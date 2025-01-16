#include "Plane.h"

bool Plane::CollidesWith(Plane& other) {
	return false;
}

bool Plane::CollidesWith(SphereCollider& other) {
	return false;
}

bool Plane::CollidesWith(AxisAlignedBoundingBox& other) {
	return false;
}

