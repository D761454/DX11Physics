#pragma once
#include "Collider.h"
#include "SphereCollider.h"
#include "PlaneCollider.h"

class AABBCollider : public Collider
{
	Vector3 min, max;
	Vector3 halfExtents;

public:
	AABBCollider(Transform* tf) : Collider(tf) {
		// add/remove half width/height to get min and max from pos
		min = tf->GetPosition() - tf->GetScale();
		max = tf->GetPosition() + tf->GetScale();
		halfExtents = max / 2;
	}

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;

	virtual void Update(float dt) override {
		min = this->GetPosition() - this->_tf->GetScale();
		max = this->GetPosition() + this->_tf->GetScale();
	}

	Vector3 GetMin() const { return min; }
	Vector3 GetMax() const { return max; }
	Vector3 GetHalfExtents() const { return halfExtents; }

	virtual float CalculatePenetrationDepth(Collider& other, CollisionManifold& out) override { return other.CalculatePenetrationDepth(*this, out); }
	virtual float CalculatePenetrationDepth(SphereCollider& other, CollisionManifold& out) override { return 0.0f; }
	virtual float CalculatePenetrationDepth(AABBCollider& other, CollisionManifold& out) override;
};

