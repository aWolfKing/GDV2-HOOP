#pragma once
#include "Bankrekening.h"
#include <iostream>

Bankrekening::Bankrekening()
{
	saldo = 0;
	transacties = std::vector<Transactie>();
}

Bankrekening::~Bankrekening()
{
}

Bankrekening& Bankrekening::operator+(Transactie t) {
	saldo += t.bedrag;
	transacties.push_back(t);
	return *this;
}

Bankrekening& Bankrekening::operator+=(Transactie t) {
	saldo += t.bedrag;
	transacties.push_back(t);
	return *this;
}

Bankrekening& Bankrekening::operator-(Transactie t) {
	saldo -= t.bedrag;
	Transactie tclone = t;
	tclone.bedrag *= -1;
	transacties.push_back(tclone);
	return *this;
}

Bankrekening& Bankrekening::operator-=(Transactie t) {
	saldo -= t.bedrag;
	Transactie tclone = t;
	tclone.bedrag *= -1;
	transacties.push_back(tclone);
	return *this;
}

std::ostream& operator<<(std::ostream& s, const Bankrekening r) {
	float saldo = 0;
	s << "Rekening: " << "\tsaldo: " << r.saldo << "\n";
	for (int i = 0; i < r.transacties.size(); i++) {
		saldo += r.transacties.at(i).bedrag;
		s << "\t" << (r.transacties.at(i).bedrag < 0?"af: ":"bij: ") << std::to_string(r.transacties.at(i).bedrag) << ", datum:" << r.transacties.at(i).datum << ", saldo: " << std::to_string(saldo) << "\n";
	}
	return s;
}
