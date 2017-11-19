#include <iostream>
#include "Parent.h"
#include "SmartParent.h"
#include <vector>

using namespace std;

int main() {

	{

		//Parent* p1 = new Parent("Parent1");
		//cout << "P1:" << *p1 << endl;

		shared_ptr<Parent> p1 = make_shared<Parent>("Parent1");
		cout << "P1:" << *p1.get() << endl;

		//Parent* p2 = new Parent(*p1); // roept de copy constructor aan
		//cout << "P2:" << *p2 << endl;

		shared_ptr<Parent> p2 = make_shared<Parent>(*p1.get());
		cout << "P2:" << *p2.get() << endl;

		//Parent* p3 = new Parent("Parent3");
		//cout << "P3:" << *p3 << endl;

		shared_ptr<Parent> p3 = make_shared<Parent>("Parent3");
		cout << "P3:" << *p3.get() << endl;

		//*p3 = *p1; // roept de assignment operator 
		//cout << "P3:" << *p3 << endl;

		p3 = p1;
		cout << "P3:" << *p3.get() << endl;

		//std::shared_ptr<Parent> p5 = new SmartParent();

		//shared_ptr<Parent> p6 = SmartParent("Smart");
		SmartParent p6 = SmartParent("Smart");
		cout << "P6:" << *p6.get() << endl;

		//Parent * p = new Parent("to Smart");

		SmartParent p7 = new Parent("to Smart");  //p;
		cout << "P7:" << *p7.get() << endl;

		shared_ptr<Parent> p = make_shared<Parent>("UseCount");
		{
			vector<shared_ptr<Parent>> pvec = vector<shared_ptr<Parent>>();
			vector<SmartParent> spvec = vector<SmartParent>();
			for (int i = 0; i < 9; i++) {
				pvec.push_back(p);
				spvec.push_back(p7);
				cout << "use count: " << p.use_count() << endl;
				//cout << "use count: " << p7.use_count() << " (smart parent)" << endl;
			}
		}
		cout << "use count: " << p.use_count() << endl;
		//cout << "use count: " << p7.use_count() << " (smart parent)" << endl;

		//delete p;
		

		//delete new SmartParent();

		/*
		shared_ptr<Parent> p4 = make_shared<Parent>("Parent4");
		cout << "P4:" << *p4.get() << endl;
		*p4.get() = *p2.get();
		cout << "P4:" << *p4.get() << endl;
		*/
			

		//delete p3.get();	//ik moest het even testen hoor

		//delete p1;
		//delete p2;
		//delete p3;

	}

	char key;
	std::cin >> key;

	return 0;
}