#include "classDeclaration.h"

ClassDefinition::ClassDefinition() {
	cout << "Const Simiple" << endl;
}

ClassDefinition::~ClassDefinition() {
	cout << "Destroy Simple" << endl;
}

void ClassDefinition::publicMethod() {
	cout << "Public method" << endl;
}

ClassDefinition& ClassDefinition::operator=(const ClassDefinition& rhs) {
	return *this; // revisit: = should return *this
}