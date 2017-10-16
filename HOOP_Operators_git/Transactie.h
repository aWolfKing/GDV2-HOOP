#pragma once
#include <string>

class Transactie
{
public:
	Transactie();
	~Transactie();

	Transactie(double hoeveelheid, std::string datum);

	float bedrag;
	std::string datum;

private:

};
