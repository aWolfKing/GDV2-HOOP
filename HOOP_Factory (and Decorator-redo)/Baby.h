#pragma once
#include "Entity.h"

class Baby : public Entity
{
public: 
	void render();
	Baby(Entity * e);
protected:
	Entity * base;
};

void Baby::render() {
	if (base != nullptr) {
		base->render();
	}
	std::cout << " baby ";
}

Baby::Baby(Entity * e) {
	base = e;
}