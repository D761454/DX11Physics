#pragma once
#include "Collider.h"
#include "AABBCollider.h"
#include "SphereCollider.h"

class PlaneCollider : public Collider
{
	Vector3 normal;

public:
	PlaneCollider(Transform* tf, Vector3 n) : Collider(tf) { normal = n; normal.Normalize(); }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) override { return other.CollidesWith(*this, out); }
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) override;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) override;

	virtual void Update(float dt) override {}

	Vector3 GetNRML() const { return normal; }
};

