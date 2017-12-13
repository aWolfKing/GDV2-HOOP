#pragma once
#include <string>
#include "Parent.h"
#include <iostream>

class SmartParent : public shared_ptr<Parent>
{
public:
	//SmartParent();
	~SmartParent();

	SmartParent(std::string name) : shared_ptr<Parent>(new Parent(name)) {
		this->name = name;
	};
	SmartParent(Parent * p) : shared_ptr<Parent>(p) {
		this->name = p->name;
	};

	//operator shared_ptr<Parent> const();

	SmartParent operator=(Parent * p) {
		return SmartParent(p);
	}

private:
	std::string name;
	//shared_ptr<Parent> ptr;
};