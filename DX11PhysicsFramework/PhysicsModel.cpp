#include "PhysicsModel.h"

PhysicsModel::PhysicsModel(Transform* transform) {

}

void PhysicsModel::Update(float dt) {
	Vector3 position = _transform->GetPosition();
	position += _velocity * dt;
	_transform->SetPosition(position);
}