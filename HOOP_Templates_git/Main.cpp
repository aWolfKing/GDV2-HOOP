#pragma once
#include "Queue.h"
#include <iostream>
#include "Decorators.h"

int main() {

	Queue<int> intque = Queue<int>();
	Queue<string> stringque = Queue<string>();

	intque.sort();
	stringque.sort();

	char key;
	cin >> key;

	for (int i = 0; i < 5; i++) {
		intque.put(i);
	}

	cout << endl;

	cout << intque.print() << endl;
	intque.put(99);
	cout << intque.print() << endl;
	intque.get();
	cout << intque.print() << endl;
	//cout << "size: " << to_string(intque.size()) << endl;

	cin >> key;

	Elf elf = Elf("elf1", Farmer());
	elf.render();	//niet goed, waarom niet?
	cin >> key;

}