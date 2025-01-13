#pragma once
#include "Collider.h"

class AxisAlignedBoundingBox : public Collider
{
	Vector3 min, max;

public:
	AxisAlignedBoundingBox(Transform* tf) : Collider(tf) { }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;
};

