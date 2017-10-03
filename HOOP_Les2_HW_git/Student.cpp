#pragma once
#include "Student.h"

Student::Student()
{
}

Student::Student(string name) {
	Name = name;
	modules = vector<Module*>();
}

Student::~Student()
{
}

void Student::addModule(Module* module) {
	modules.push_back(module);
}

void Student::updateECs() {
	int ret = 0;
	for (int i = 0; i < modules.size(); i++) {	//sizeof not working?
		//ret += modules[i].EC;
		ret += modules.at(i)->EC;
	}
	ECs = ret;
}

void Student::removeAllModules() {
	int loop = modules.size();
	for (int i = loop-1; i >= 0; i--) {
		//delete modules.at(i);
		modules.clear();
	}
}