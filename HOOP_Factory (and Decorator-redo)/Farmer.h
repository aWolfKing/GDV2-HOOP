#pragma once
#include "Humanoid.h"

class Farmer : public Entity
{
public:
	void render();
	Farmer(Entity * e);
protected:
	Entity * base;
};

void Farmer::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " farmer ";
}

Farmer::Farmer(Entity * e) {
	base = e;
}