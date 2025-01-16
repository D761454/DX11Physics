#pragma once
#include "Collider.h"
#include "SphereCollider.h"

class AxisAlignedBoundingBox : public Collider
{
	Vector3 min, max;

public:
	AxisAlignedBoundingBox(Transform* tf) : Collider(tf) {
		// add/remove half width/height to get min and max from pos
		min = tf->GetPosition(); // temporary - assume all objects with collision have base size of 1x1x1
		max = tf->GetPosition() + tf->GetScale();
	}

	virtual bool CollidesWith(Collider& other) override { return other.CollidesWith(*this); }
	virtual bool CollidesWith(SphereCollider& other) override;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) override;

	virtual void Update(float dt) override {
		min = this->GetPosition(); // temporary - assume all objects with collision have base size of 1x1x1
		max = this->GetPosition() + this->_tf->GetScale();
	}
};

