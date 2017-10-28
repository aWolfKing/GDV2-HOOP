#pragma once
#include "Humanoid.h"

class Orc : public Entity
{
public:
	void render();
	Orc(Humanoid * e);
protected:
	Entity * base;
};

void Orc::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " orc ";
}

Orc::Orc(Humanoid * e) {
	base = e;
}