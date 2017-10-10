#pragma once
#include "Queue.h"
#include <iostream>


template<typename T> Queue<T>::Queue()
{
	this->items = vector<T>();
}

template<typename T> Queue<T>::~Queue()
{
}


template<typename T> void Queue<T>::put(T item) {
	this->items.push_back(item);
}



template<typename T> T Queue<T>::get() {
	if (this->items.size() > 0) {
		T ret = this->items.at(0);
		this->items.erase(0);
		return ret;
	}
	else {
		throw exception("no items where put in the queue");
	}
}



template<typename T> int Queue<T>::size() {
	return this->items.size();
}



void Queue<int>::sort() {
	cout << "Sorted for an int queue" << endl;
}

void Queue<string>::sort() {
	cout << "Sorted for a string queue" << endl;
}


void Queue<int>::put(int item) {
	this->items.push_back(item);
}

void Queue<string>::put(string item) {
	this->items.push_back(item);
}


int Queue<int>::get() {
	if (this->items.size() > 0) {
		int ret = this->items.at(0);
		//this->items.erase(0);
		this->items.erase(items.begin());
		return ret;
	}
	else {
		throw exception("no items where put in the queue");
	}
}

string Queue<string>::get() {
	if (this->items.size() > 0) {
		string ret = this->items.at(0);
		//this->items.erase(0);
		this->items.erase(items.begin());
		return ret;
	}
	else {
		throw exception("no items where put in the queue");
	}
}



string Queue<int>::print() {
	string ret = "elements: ";
	for (int i = 0; i < items.size(); i++) {
		ret += to_string(items.at(i));
		if (i < items.size() - 1) {
			ret += ",";
		}
	}

	ret += "\t\t";
	ret += "size: ";
	ret += to_string(size());

	return ret;
}

int Queue<int>::size() {
	return items.size();
}
int Queue<string>::size() {
	return items.size();
}