#pragma once
#include "Entity.h"

class Animal : public Entity
{
public:
	void render();
	Animal(Entity * e);
protected:
	Entity * base;
};

void Animal::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " animal ";
}

Animal::Animal(Entity * e) {
	base = e;
}