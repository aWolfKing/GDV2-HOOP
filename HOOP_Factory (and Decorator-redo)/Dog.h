#pragma once
#include "Animal.h"

class Dog : public Entity
{
public:
	void render();
	Dog(Animal * a);
protected:
	Animal * base;
};

void Dog::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " dog ";
}

Dog::Dog(Animal * a) {
	base = a;
}