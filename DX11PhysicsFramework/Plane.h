#pragma once
#include "Collider.h"
#include "AxisAlignedBoundingBox.h"
#include "SphereCollider.h"

class Plane : public Collider
{
	Vector3 normal;

public:
	Plane(Transform* tf, Vector3 n) : Collider(tf) { normal = n; normal.Normalize(); }

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;
	virtual bool CollidesWith(Plane& other) override;

	virtual void Update(float dt) override {}

	Vector3 GetNRML() const { return normal; }
};

