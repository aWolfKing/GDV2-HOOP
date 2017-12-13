#include <iostream>
#include "Parent.h"


int main() {

	Parent p = Parent("tijdelijk");
	{
		//Parent p = Parent("tijdelijk");
		Parent&& t = Parent("joop");
		//Parent t = std::move(p);
		//t = Parent("a");
		
		Parent a = Parent("a");
		Parent _b = std::move(a);
		a = t;

		/*{
			p = t;
		}*/
		//p = Parent(t);
		//Parent a = Parent(t);
	}

	char key;
	std::cin >> key;

	return 0;
}
