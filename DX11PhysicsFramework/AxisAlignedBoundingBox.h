#pragma once
#include "Collider.h"
#include "SphereCollider.h"
#include "Plane.h"

class AxisAlignedBoundingBox : public Collider
{
	Vector3 min, max;
	Vector3 halfExtents;

public:
	AxisAlignedBoundingBox(Transform* tf) : Collider(tf) {
		// add/remove half width/height to get min and max from pos
		min = tf->GetPosition() - tf->GetScale();
		max = tf->GetPosition() + tf->GetScale();
		halfExtents = max / 2;
	}

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;
	virtual bool CollidesWith(Plane& other) override;

	virtual void Update(float dt) override {
		min = this->GetPosition() - this->_tf->GetScale();
		max = this->GetPosition() + this->_tf->GetScale();
	}

	Vector3 GetMin() const { return min; }
	Vector3 GetMax() const { return max; }
	Vector3 GetHalfExtents() const { return halfExtents; }

	virtual float CalculatePenetrationDepth(Collider& other) override { return other.CalculatePenetrationDepth(*this); }
	virtual float CalculatePenetrationDepth(SphereCollider& other) override { return 0.0f; }
	virtual float CalculatePenetrationDepth(AxisAlignedBoundingBox& other) override { return 0.0f; }
};

