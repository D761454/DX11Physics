#pragma once
#include "Collider.h"
#include "SphereCollider.h"
#include "PlaneCollider.h"

class AABBCollider : public Collider
{
	Vector3 halfExtents;

public:
	AABBCollider(Transform* tf) : Collider(tf) {
		halfExtents = tf->GetScale() / 2;
	}

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;

	virtual void Update(float dt) override {
		
	}

	Vector3 GetHalfExtents() const { return halfExtents; }
};

