#pragma once
#include <iostream>

using namespace std;

class Simple {
public:
	Simple();
	virtual ~Simple(); // memo_201710: virtual only to class declaration
	virtual void publicMethod(); // VTable is table for class methods and VPtr is pointing on VTable of class hierarchy of the class
	Simple& operator=(const Simple& rhs);
	static const int mConstantInt = 2; // revisit
	static int sStaticInt;
protected:
	int mProtectedInteger;
private:
	Simple(const Simple&src);
};
