#pragma once
#include "Teacher.h"
#include "Student.h"
#include "Module.h"
#include <iostream>

int main() {

	if (true) {

		// 'vector->at(i)' == 'array[i]'?

		/*
		Teacher * test;
		Teacher * test2;
		test = new Teacher("a");
		test2 = test;
		test2->Name = "b";
		cout << test->Name << endl;
		delete test;
		//delete test2	//niet nodig?
		*/

		//Student * students[10] = { new Student("a"), new Student("b"), new Student("c"), new Student("d"), new Student("e"), new Student("f"), new Student("g"), new Student("h"), new Student("i"), new Student("j") };
		vector<Student> * students = new vector<Student>();
		for (int i = 0; i < 10; i++) {
			students->push_back(Student("Student " + to_string(i+1)));
		}

		//Teacher teachers[3] = { Teacher("Jan"), Teacher("Henk"), Teacher("Ron") };
		vector<Teacher> * teachers = new vector<Teacher>();
		teachers->push_back(Teacher("Jan"));
		teachers->push_back(Teacher("Henk"));
		teachers->push_back(Teacher("Ron"));

		//Module modules[3] = { Module("C++", 30), Module("C#", 32), Module("Python", 25) };
		vector<Module> * modules = new vector<Module>();
		modules->push_back(Module("C++", 30));
		modules->push_back(Module("C#", 32));
		modules->push_back(Module("Python", 25));
		

		for (int i = 0; i < 3; i++) {
			//modules[i].Teacher = teachers[i];
			modules->at(i).Teacher = &teachers->at(i);
		}

		//cout << modules->at(0).Teacher->Name << endl; teachers->at(0).Name = "abrakadabra"; cout << modules->at(0).Teacher->Name << endl;

		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0) {
				//students[i]->addModule(modules[0]);
				//students->at(i).addModule(modules[0]);
				students->at(i).addModule(&modules->at(0));
			}
			if (i > 3 && i < 7) {
				//students[i]->addModule(modules[1]);
				//students->at(i).addModule(modules[1]);
				students->at(i).addModule(&modules->at(1));
			}
			else {
				//students[i]->addModule(modules[2]);
				//students->at(i).addModule(modules[2]);
				students->at(i).addModule(&modules->at(2));
			}
		}

		for (int i = 0; i < 3; i++) {
			//cout << "Module: " << modules[i].Name << ", Teacher: " << modules[i].Teacher.Name << endl;
			cout << "Module: " << modules->at(i).Name << ", Teacher: " << modules->at(i).Teacher->Name << endl;
		}

		cout << "" << endl;

		for (int i = 0; i < 10; i++) {
			//students[i]->updateECs();
			//cout << "Student: " << students[i]->Name << ", ECs: " << students[i]->ECs << endl;
			students->at(i).updateECs();
			cout << "Student: " << students->at(i).Name << ", ECs: " << students->at(i).ECs << endl;
		}

		cout << "" << endl;

		//modules[0].EC -= 4;
		//cout << "ec change " << &students->at(0).modules.at(0)->EC << " to " << endl;
		int startec = modules->at(0).EC;
		modules->at(0).EC -= 4;
		students->at(0).updateECs();
		//cout << "ec change " << &students->at(0).modules.at(0)->EC << " to " << endl;

		cout << "Changed ECs from module: '" << modules->at(0).Name << "' from " << to_string(startec) << " to " << to_string(modules->at(0).EC) << endl;

		for (int i = 0; i < 10; i++) {
			//students[i]->updateECs();
			//cout << "Student: " << students[i]->Name << ", ECs: " << students[i]->ECs << endl;
			students->at(i).updateECs();
			cout << "Student: " << students->at(i).Name << ", ECs: " << students->at(i).ECs << endl;
		}


		cout << "" << endl;

		//students[0]->modules.erase(students[0]->modules.begin());
		cout << "deleted module: '" << students->at(0).modules.at(0)->Name << "' with " << students->at(0).modules.at(0)->EC << " points" 
		<< " from " << students->at(0).Name <<
		endl;

		students->at(0).modules.erase(students->at(0).modules.begin());

		for (int i = 0; i < 10; i++) {
			//students[i]->updateECs();
			//cout << "Student: " << students[i]->Name << ", ECs: " << students[i]->ECs << endl;
			students->at(i).updateECs();
			cout << "Student: " << students->at(i).Name << ", ECs: " << students->at(i).ECs << endl;
		}

		for (int i = 0; i < 10; i++) {
			students->at(i).removeAllModules();
		}

		delete students;
		delete teachers;
		delete modules;
	}
	
	char key;
	cin >> key;

	return 0;
}