// [AM]
#include <iostream>
#include "Tree.h"
using namespace std;
using namespace utility::tree;

int bstCheck() {

	int tree[] = { 4, 2, 5, 1, 3 }; // [CheatSheet] int * sizeof returns 4 but sizeof(tree) returns size of array.
	IntegerTree t(tree, sizeof(tree) / sizeof(int), [](int newValue, int nodeValue) -> bool { return (newValue <= nodeValue) ? true : false; });

	t.removeInBst(t.getRoot(), 5);
	t.removeInBst(t.getRoot(), 4);
	
	cout << "Pre" << endl;
	t.traverse(PRE, [](Node* n) { cout << n->value << endl; });
	cout << "In" << endl;
	t.traverse(IN, [](Node* n) { cout << n->value << endl; });
	cout << "Post" << endl;
	t.traverse(POST, [](Node* n) { cout << n->value << endl; });

	t.removeInBst(t.getRoot(), 2);
	cout << "Pre" << endl;
	t.traverse(PRE, [](Node* n) { cout << n->value << endl; });
	cout << "In" << endl;
	t.traverse(IN, [](Node* n) { cout << n->value << endl; });
	cout << "Post" << endl;
	t.traverse(POST, [](Node* n) { cout << n->value << endl; });
	
	t.removeInBst(t.getRoot(), 1);

	cout << "Pre" << endl;
	t.traverse(PRE, [](Node* n) { cout << n->value << endl; });
	cout << "In" << endl;
	t.traverse(IN, [](Node* n) { cout << n->value << endl; });
	cout << "Post" << endl;
	t.traverse(POST, [](Node* n) { cout << n->value << endl; });

	Node* node = t.findInBst(t.getRoot(), 7);
	if (node) cout << node->value << " is found" << endl;
	else cout << "Not found" << endl;
	return 0;
}