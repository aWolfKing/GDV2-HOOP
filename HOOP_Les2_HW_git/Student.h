#pragma once
using namespace std;
#include <string>
#include <vector>
#include "Module.h"


class Student
{
public:
	
	string Name = "";
	vector<Module*> modules;
	int ECs;

	Student();
	Student(string name);
	~Student();

	void addModule(Module* module);
	void updateECs();
	void removeAllModules();

private:

};
