#pragma once
#include "Transform.h"

class SphereCollider;
class AxisAlignedBoundingBox;

class Collider abstract
{
protected:
	Transform* _tf;
public:
	Collider(Transform* tf) { _tf = tf; }

	virtual bool CollidesWith(Collider& other) =0;
	virtual bool CollidesWith(SphereCollider& other) =0;
	virtual bool CollidesWith(AxisAlignedBoundingBox& other) = 0;

	Vector3 GetPosition() const { return _tf->GetPosition(); }
};
