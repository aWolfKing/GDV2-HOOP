#pragma once
#include <iostream>
#include "concurrent_vector.h"
#include <string>



concurrent_vector<int> sharedvec;
std::vector<int> sharedNonsafeVec;



void threadOne() {
	for (int i = 0; i < 1000; i += 2) {
		sharedvec.push_back(i);
	}
	std::cout << "Thread 1 ended" << std::endl;
	std::cout << "Size: " << sharedvec.size() << std::endl;
}
void threadTwo() {
	//std::this_thread::sleep_for(std::chrono::microseconds(1));
	for (int i = 1; i < 1000; i += 2) {
		sharedvec.push_back(i);
	}
	std::cout << "Thread 2 ended" << std::endl;
	std::cout << "Size: " << sharedvec.size() << std::endl;
}


void nonsafeOne() {
	for (int i = 0; i < 1000; i += 2) {
		sharedNonsafeVec.push_back(i);
	}
	std::cout << "nonsafe Thread 1 ended" << std::endl;
	std::cout << "Size: " << sharedNonsafeVec.size() << std::endl;
}

void nonsafeTwo() {
	//std::this_thread::sleep_for(std::chrono::microseconds(1));
	for (int i = 1; i < 1000; i += 2) {
		sharedNonsafeVec.push_back(i);
	}
	std::cout << "nonsafe Thread 2 ended" << std::endl;
	std::cout << "Size: " << sharedNonsafeVec.size() << std::endl;
}




int main() {

	std::vector<int> tstVec = std::vector<int>();
	concurrent_vector<int> tstConVec = concurrent_vector<int>();
	
	sharedNonsafeVec = std::vector<int>();

	sharedvec = tstConVec;

	std::thread thread1(threadOne);
	std::thread thread2(threadTwo);

	thread1.join();
	thread2.join();


	if (false) {
		std::thread nonsafeThread1(nonsafeOne);
		std::thread nonsafeThread2(nonsafeTwo);

		nonsafeThread1.join();
		nonsafeThread2.join();
	}


	if (false) {
		std::cout << std::endl << std::endl;

		std::string print = "";
		for (int i = 0; i < sharedvec.size(); i++) {
			print += std::to_string(sharedvec.at(i));
		}

		std::cout << print << std::endl;
	}

	std::cout << std::endl;

	std::cout << "If the code reached this point, no errors should have occurred" << std::endl;
	std::cout << "I will now show the standard vector class with the 'same' threads" << std::endl << "(expect an error because this class is not thread safe)" << std::endl;

	std::cout << std::endl;
	std::cout << "Input 'q' to quit or input anything else to continue and get an error because of the non-thread-safe standard vector" << std::endl;
	std::cout << std::endl;

	char key;
	std::cin >> key;

	if (true && key != 'q') {
		std::thread nonsafeThread1(nonsafeOne);
		std::thread nonsafeThread2(nonsafeTwo);

		nonsafeThread1.join();
		nonsafeThread2.join();
	}


	return 0;
}