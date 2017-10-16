#pragma once
#include "Bankrekening.h"
#include "Transactie.h"
#include <iostream>

int main() {

	Bankrekening rekening = Bankrekening();

	rekening += Transactie(1, "nu");
	rekening -= Transactie(10, "net");

	rekening += Transactie(1000000, "nooit");
	rekening -= Transactie(0, "ooit");

	rekening -= Transactie(rekening.saldo, "straks");

	std::cout << rekening << std::endl;
	
	char key;
	std::cin >> key;

}