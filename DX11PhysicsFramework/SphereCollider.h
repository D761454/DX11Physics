#pragma once
#include "Collider.h"
#include "AxisAlignedBoundingBox.h"
#include "Plane.h"

class SphereCollider : public Collider
{
	float radius = 1.0f;

public:
	SphereCollider(Transform* tf, float r) : Collider(tf) { radius = r; }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;
	virtual bool CollidesWith(Plane& other) override;

	float GetRadius() const { return radius; }

	virtual void Update(float dt) override {}

	virtual float CalculatePenetrationDepth(Collider& other) override { return other.CalculatePenetrationDepth(*this); }
	virtual float CalculatePenetrationDepth(SphereCollider& other) override;
	virtual float CalculatePenetrationDepth(AxisAlignedBoundingBox& other) override { return 0.0f; }
};

