#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

bool isEven(double val) {
	//return ((int)val) % 2 == 0;
	//std::cout << val << " is even: " << std::to_string((bool)(((int)val) == val) && (((int)val) % 2 == 0)) << std::endl;
	return (((int)val) == val) && (((int)val) % 2 == 0);
	//return val % 2 == 0;
}


int main() {


	std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) de vector in 2 nieuwe vectoren te splitsen, 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
	// 2) alle elementen UPPERCASE te maken.
	// 3) alle dubbele te verwijderen


	{

		std::vector<std::string> colours_1 = colours;
		std::sort(colours_1.begin(), colours_1.end());
		auto purple = std::find(colours_1.begin(), colours_1.end(), "purple");

		std::vector<std::string> beforePurple(colours_1.begin(), purple);
		std::advance(purple, 1);
		std::vector<std::string> afterPurple(purple, colours_1.end());

		std::cout << "Before purple:" << std::endl;
		for (auto i = beforePurple.begin(); i != beforePurple.end(); std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}
		std::cout << std::endl << "After purple:" << std::endl;
		for (auto i = afterPurple.begin(); i != afterPurple.end(); std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}
		

		std::vector<std::string> uppers = colours;
		std::cout << std::endl << "TO UPPER:" << std::endl;
		std::sort(uppers.begin(), uppers.end());
		//deze manier want kreeg errors die ik niet kon oplossen en niet kon vinden op t internet
		for (auto i = uppers.begin(); i != uppers.end(); std::advance(i, 1)) {
			for (auto o = i->begin(); o != i->end(); std::advance(o, 1)) {
				*o = ::toupper(*o);
			}
		}
		for (auto i = uppers.begin(); i != uppers.end(); std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}


		std::cout << std::endl << "Remove duplicates:" << std::endl;

		std::vector<std::string> duplicateRemove = colours;
		std::sort(duplicateRemove.begin(), duplicateRemove.end());
		std::unique(duplicateRemove.begin(), duplicateRemove.end());
		for (auto i = duplicateRemove.begin(); i != duplicateRemove.end(); std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}

	}


	std::cout << std::endl << std::endl;


	std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	// 1) alle negatieve elementen te verwijderen
	// 2) voor alle elementen te bepalen of ze even of oneven zijn
	// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

	{

		std::vector<double> numbers_1 = numbers;
		std::sort(numbers_1.begin(), numbers_1.end());
		auto newEnd1 = std::remove_if(numbers_1.begin(), numbers_1.end(), [](double val) -> bool {return val < 0; });
		numbers_1.erase(newEnd1, numbers_1.end());

		for (int i = 0; i < numbers_1.size(); i++) {
			std::cout << numbers_1.at(i) << std::endl;
		}


		std::cout << "==========" << std::endl;


		std::vector<double> numbers_2 = numbers;
		std::sort(numbers_2.begin(), numbers_2.end());		
		//isEven not working for remove_if etc?
		std::vector<double> even;
		std::vector<double> odd;
		for (auto i = numbers_2.begin(); i != numbers_2.end(); std::advance(i, 1)) {
			if (isEven(*i)) {
				even.push_back(*i);
			}
			else {
				odd.push_back(*i);
			}
		}

		for (auto i = odd.begin(); i != odd.end(); std::advance(i, 1)) {
			std::cout << "Odd: " << *i << std::endl;
		}
		for (auto i = even.begin(); i != even.end(); std::advance(i, 1)) {
			std::cout << "Even: " << *i << std::endl;
		}


		/*
		auto half = numbers_2.begin();
			std::advance(half, numbers_2.size() / 2);

		for (auto i = numbers_2.begin(); i != half; std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}
		std::cout << "===" << std::endl;
		for (auto i = half; i != numbers_2.end(); std::advance(i, 1)) {
			std::cout << *i << std::endl;
		}
		*/
	
		double sum = 0;
		double product = 1;
		for (auto i = numbers.begin(); i != numbers.end(); std::advance(i, 1)) {
			sum += *i;
			product *= *i;
		}
		double average = sum / numbers.size();

		std::cout << "Sum: " << sum << ", Product: " << product << ", Average: " << average << std::endl;

	}

	char key;
	std::cin >> key;

	return 0;
}