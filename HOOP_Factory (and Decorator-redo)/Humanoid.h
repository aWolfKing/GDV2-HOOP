#pragma once
#include "Entity.h"

class Humanoid : public Entity
{
public:
	void render();
	Humanoid(Entity * e);
protected:
	Entity * base;
};

void Humanoid::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " humanoid ";
}

Humanoid::Humanoid(Entity * e) {
	base = e;
}