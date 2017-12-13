#include "SmartParent.h"

/*
SmartParent::SmartParent()
{
}
*/

SmartParent::~SmartParent()
{
	//this->~shared_ptr<Parent>();
	//SmartParent::~shared_ptr<Parent>();
}

/*
SmartParent::SmartParent(std::string name) : shared_ptr<Parent>(new Parent(name)) {
	this->name = name;
	//this->ptr = make_shared<Parent>(name);
}
*/

/*
SmartParent::operator shared_ptr<Parent>const()
{
	return make_shared<Parent>(this->name);
}
*/