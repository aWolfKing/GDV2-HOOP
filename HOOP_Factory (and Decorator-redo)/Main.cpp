#pragma once
#include <iostream>
#include "Factory.h"

int main() {

	//Dog e1 = Dog(new Animal(new Baby(nullptr)));
	//Elf e2 = Elf(new Humanoid(nullptr));

	//e1.render(); std::cout << std::endl;
	//e2.render(); std::cout << std::endl;

	Entity * e = Factory::GetEntity(PUPPY, FARMER);
	e->render();

	delete e;

	std::cout << std::endl;

	e = Factory::GetEntity(ELF, SOLDIER);
	e->render();

	delete e;

	std::cout << std::endl;

	e = Factory::GetEntity(ORC);
	e->render();

	delete e;

	std::cout << std::endl;

	char key;
	std::cin >> key;

	return 0;
}