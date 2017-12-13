#pragma once

#include <string>
#include <ostream>
#include "Child.h"
#include <memory>

using namespace std;

class Parent {
public:
	Parent(string name);

	Parent(const Parent& other);

	Parent(Parent&& other);

	virtual ~Parent();

	Parent& operator=(const Parent& other);

	friend ostream& operator<<(ostream& os, const Parent& parent);

	string name;

private:
	//string name;
	//Child* child;
	std::unique_ptr<Child> child;
};