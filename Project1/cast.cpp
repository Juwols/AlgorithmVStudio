#include <iostream>
using namespace std;

class CastA {
public:
	virtual void Print() { cout << "A: " << endl; }
};

class CastB : public CastA {
public:
	virtual void Print() { cout << "Sub: " << endl; }
};

void pass(void* v) {
	CastB* ss2 = static_cast<CastB*>(v);
	ss2->CastA::Print();
	CastB* ss = static_cast<CastB*>(v); // memo-201706 : const_cast to remove const, reinterpret_cast to just cast (not safe)
	ss->Print();
	ss->CastA::Print();
}
int testCast() {
	CastB* s = new CastB();
	pass((void*)s);
	return 0;
}
