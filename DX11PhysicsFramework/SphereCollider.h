#pragma once
#include "Collider.h"
#include "AABBCollider.h"
#include "PlaneCollider.h"

class SphereCollider : public Collider
{
	float radius = 1.0f;

public:
	SphereCollider(Transform* tf, float r) : Collider(tf) { radius = r; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;

	float GetRadius() const { return radius; }

	virtual void Update(float dt) override {}
};

