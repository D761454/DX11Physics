#pragma once
#include "Collider.h"
#include "SphereCollider.h"

class AxisAlignedBoundingBox : public Collider
{
	Vector3 min, max;

public:
	AxisAlignedBoundingBox(Transform* tf) : Collider(tf) {
		// add/remove half width/height to get min and max from pos
	}

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;
};

