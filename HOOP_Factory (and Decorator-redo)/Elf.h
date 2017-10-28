#pragma once
#include "Humanoid.h"

class Elf : public Entity
{
public:
	void render();
	Elf(Humanoid * e);
protected:
	Entity * base;
};

void Elf::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " elf ";
}

Elf::Elf(Humanoid * e) {
	base = e;
}