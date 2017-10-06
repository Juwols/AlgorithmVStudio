// [NF]
// malloc vs free
// constructor 
// vtable
// reverse string inplace
// constructor / destructor

#include <iostream>

using namespace std;

class SuperA {
public:
	SuperA() {
		methodA();
	}
	virtual ~SuperA() {
		methodA();
	}
	void methodA() {
		cout << "Hello Super A" << endl;
	}
};

class MinorA : public SuperA {
public:
	MinorA() {
		methodA();
	}
	~MinorA() {
		methodA();
	}
	void methodA() {
		cout << "Hello MinorA A" << endl;
	}
};

int testSuperSubVtable() {
	SuperA* a = new MinorA();
	cout << "Call direct: ";
	a->methodA();
	delete a;
	cout << "End" << endl;
	return 0;
}