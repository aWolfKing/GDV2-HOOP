#pragma once
#include <vector>
#include "Transactie.h"

class Bankrekening
{
public:
	Bankrekening();
	~Bankrekening();

	float saldo;
	std::vector<Transactie> transacties;

	Bankrekening& operator+(const Transactie t);
	Bankrekening& operator-(const Transactie t);

	Bankrekening& operator+=(const Transactie t);
	Bankrekening& operator-=(const Transactie t);

	friend std::ostream& operator<<(std::ostream& s, const Bankrekening b);

private:

};
