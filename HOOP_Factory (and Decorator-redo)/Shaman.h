#pragma once
#include "Humanoid.h"

class Shaman : public Entity
{
public:
	void render();
	Shaman(Entity * e);
protected:
	Entity * base;
};

void Shaman::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " shaman ";
}

Shaman::Shaman(Entity * e) {
	base = e;
}