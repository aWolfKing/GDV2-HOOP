#pragma once
using namespace std;
#include <vector>
#include <string>


template<typename T> class Queue //: int,string
{
public:
	Queue();
	~Queue();

	void put(T item);//: int,string;
	T get(); //where T : int, string;
	int size();

	template<> void sort(); //: int,string;

private:
	vector<T> items;

};



template<> class Queue<int> 
{
public:
	void put(int item);
	int get();
	int size();

	void sort();

	string print();

private:
	vector<int> items;

};


template<> class Queue<string>
{
public:
	void put(string item);
	string get();
	int size();

	void sort();

private:
	vector<string> items;

};