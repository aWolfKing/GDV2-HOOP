#pragma once
#include "Humanoid.h"

class Soldier : public Entity
{
public:
	void render();
	Soldier(Entity * e);
protected:
	Entity * base;
};

void Soldier::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " soldier ";
}

Soldier::Soldier(Entity * e) {
	base = e;
}