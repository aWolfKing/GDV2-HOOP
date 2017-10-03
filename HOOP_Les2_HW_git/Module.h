#pragma once
using namespace std;
#include <string>
#include "Teacher.h"

class  Module
{
public:

	string Name = "";
	int EC = 0;
	Teacher * Teacher;


	 Module();
	 Module(string name, int ec);
	~ Module();

private:

};
