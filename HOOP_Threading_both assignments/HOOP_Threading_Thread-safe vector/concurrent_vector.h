#pragma once
#include <vector>
#include <thread>
#include <mutex>


template<class T> class concurrent_vector
{
public:

	concurrent_vector();
	~concurrent_vector();

	concurrent_vector(const concurrent_vector<T> & other);				//waarom moet dit?
	concurrent_vector& operator=(const concurrent_vector<T> & other);	//waarom moet dit?
	concurrent_vector& operator=(concurrent_vector<T> && other);		//waarom moet dit?

	void push_back(T item);
	T at(int index);

	int size();

private:
	std::vector<T> vector;
	std::mutex mutex;
};






template<class T> concurrent_vector<T>::concurrent_vector()
{
	this->vector = std::vector<T>();
}

template<class T> concurrent_vector<T>::~concurrent_vector()
{
	//delete this->vector;
}




template<class T> concurrent_vector<T>::concurrent_vector(const concurrent_vector<T> & other) {
	this->vector = other.vector;
}

template<class T> concurrent_vector<T> & concurrent_vector<T>::operator=(const concurrent_vector<T>& other)
{
	//delete this->vector;
	this->vector = other.vector;
	return *this;
}

template<class T> concurrent_vector<T> & concurrent_vector<T>::operator=(concurrent_vector<T>&& other)
{
	if (this != &other) // prevent self-move
	{
		delete this->vector;
		this->vector = other.vector;
		other.vector = nullptr;
	}
	return *this;
}




template<class T> void concurrent_vector<T>::push_back(T item) {
	//this->mutex.try_lock();
	this->mutex.lock();
	this->vector.push_back(item);
	this->mutex.unlock();
}

template<class T> T concurrent_vector<T>::at(int index) {
	return this->vector.at(index);
}


template<class T> int concurrent_vector<T>::size() {
	return this->vector.size();
}