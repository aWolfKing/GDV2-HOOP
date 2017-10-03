#pragma once
#include "Module.h"
#include "Teacher.h"

Module::Module()
{
}

Module::Module(string name, int ec) {
	Name = name;
	EC = ec;
}

Module::~Module()
{
}