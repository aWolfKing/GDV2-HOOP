#pragma once
#include "Decorators.h"
#include <iostream>

npc::npc() {

}

npc::npc(string _name)
{
	name = _name;
}

npc::~npc()
{
}

void role::render() {
	cout << ", role here" << endl;
}

void npc::render() {
	cout << name;
}

void Farmer::render() {
	cout << ", Farmer" << endl;
}

void Soldier::render() {
	cout << ", Soldier" << endl;
}

void Shaman::render() {
	cout << ", Shaman" << endl;
}


Elf::Elf(string _name, role _role) {
	name = _name;
	this->_role = _role;
}

void Elf::render() {
	npc::render();
	_role.render();
}
