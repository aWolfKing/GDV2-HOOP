#pragma once
#include "Entity.h"

class Parent : public Entity
{
public:
	void render();
	Parent(Entity * e);
protected:
	Entity * base;
};

void Parent::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " baby ";
}

Parent::Parent(Entity * e) {
	base = e;
}