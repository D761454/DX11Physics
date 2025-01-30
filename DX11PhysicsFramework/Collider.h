#pragma once
#include "Transform.h"
#include "Structures.h"

class SphereCollider;
class AABBCollider;
class PlaneCollider;

class Collider abstract
{
protected:
	Transform* _tf;
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other, CollisionManifold& out) =0;
	virtual bool CollidesWith(SphereCollider& other, CollisionManifold& out) =0;
	virtual bool CollidesWith(AABBCollider& other, CollisionManifold& out) = 0;
	virtual bool CollidesWith(PlaneCollider& other, CollisionManifold& out) = 0;

	Vector3 GetPosition() const { return _tf->GetPosition(); }

	virtual void Update(float dt) =0;

	virtual float CalculatePenetrationDepth(Collider& other, CollisionManifold& out) = 0;
	virtual float CalculatePenetrationDepth(SphereCollider& other, CollisionManifold& out) =0;
	virtual float CalculatePenetrationDepth(AABBCollider& other, CollisionManifold& out) = 0;
};
