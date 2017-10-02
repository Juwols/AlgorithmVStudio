#include <iostream>

using namespace std;

class ArrayTest {
public:
	ArrayTest() { cout << "create simple " << endl; }
	virtual ~ArrayTest() { cout << "destruct simple " << endl; }
	void Print() { cout << "print..." << endl; }
};

int arrayTest() {
	ArrayTest *s = new ArrayTest();

	cout << "now array of 4 " << endl;

	ArrayTest *sarr = new ArrayTest[4];

	s->Print();
	sarr[1].Print(); // memo-201706 : Hmmm [] makes *(sarr+1) 
	(sarr + 1)->Print();
	return 0;
}
