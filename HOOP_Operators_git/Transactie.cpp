#pragma once
#include "Transactie.h"

Transactie::Transactie()
{
}

Transactie::~Transactie()
{
}

Transactie::Transactie(double hoeveelheid, std::string datum) {
	this->bedrag = hoeveelheid;
	this->datum = datum;
}