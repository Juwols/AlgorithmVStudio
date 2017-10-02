#include "classDeclaration.h"

Simple::Simple() {
	cout << "Const Simiple" << endl;
}

Simple::~Simple() {
	cout << "Destroy Simple" << endl;
}

void Simple::publicMethod() {
	cout << "Public method" << endl;
}

Simple& Simple::operator=(const Simple& rhs) {
	return *this; // revisit: = should return *this
}