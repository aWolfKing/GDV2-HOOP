#pragma once
#include "Dog.h"
#include "Elf.h"
#include "Baby.h"
#include "Parent.h"
#include "Orc.h"
#include "Soldier.h"
#include "Farmer.h"
#include "Shaman.h"

enum EntityType
{
	DOG, ANIMAL, ELF, ORC, HUMANOID, PUPPY
};

enum Role
{
	FARMER, SOLDIER, SHAMAN
};


class Factory
{
public:
	static Entity * GetEntity(EntityType t);
	static Entity * GetEntity(EntityType t, Role r);
};

Entity * Factory::GetEntity(EntityType t) {
	switch (t)
	{
	case DOG:
		return new Dog(new Animal(nullptr));
		break;
	case PUPPY:
		return new Dog(new Animal(new Baby(nullptr)));
		break;
	case ANIMAL:
		return new Animal(nullptr);
		break;
	case ELF:
		return new Elf(new Humanoid(nullptr));
		break;
	case ORC:
		return new Orc(new Humanoid(nullptr));
		break;
	case HUMANOID:
		return new Humanoid(nullptr);
		break;
	default:
		return nullptr;
		break;
	}
}

Entity * Factory::GetEntity(EntityType t, Role r) {
	Entity * e;
	switch (t)
	{
	case DOG:
		e = new Dog(new Animal(nullptr));
		break;
	case PUPPY:
		e = new Dog(new Animal(new Baby(nullptr)));
		break;
	case ANIMAL:
		e = new Animal(nullptr);
		break;
	case ELF:
		e = new Elf(new Humanoid(nullptr));
		break;
	case ORC:
		e = new Orc(new Humanoid(nullptr));
		break;
	case HUMANOID:
		e = new Humanoid(nullptr);
		break;
	default:
		return nullptr;
		break;
	}
	switch (r) {
	case FARMER:
		return new Farmer(e);
		break;
	case SOLDIER:
		return new Soldier(e);
		break;
	case SHAMAN:
		return new Shaman(e);
		break;
	default:
		break;
	}
}