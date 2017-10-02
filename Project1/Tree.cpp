#include <stdexcept>
#include "Tree.h"
#include "assert.h"

using namespace std;
using namespace utility::tree;

IntegerTree::IntegerTree(int* arr, int size, bool(*leftAddPredicate)(int newValue, int nodeValue)) 
{
	createTree(arr, size, leftAddPredicate);
}

void utility::tree::IntegerTree::createNode(Node* node, int value) 
{
	if (node == NULL) {
		throw invalid_argument("node creation failed");
	}
	node->value = value;
	node->left = NULL;
	node->right = NULL;
}

Node* utility::tree::IntegerTree::addNode(int * arr, int size, int index) 
{
	if (arr == NULL) {
		throw invalid_argument("node creation failed");
	}
	
	assert(size > 0);
	assert(index >= 0);

	Node* newNode = new (nothrow) Node;
	createNode(newNode, arr[index]);
	return newNode;
}

Node * utility::tree::IntegerTree::getNextToSwap(Node * node)
{
	Node* nextNode = node;
	assert(nextNode->right != NULL);
	if (nextNode->right) {
		nextNode = nextNode->right;
		while (true) {
			if (!nextNode->left) return nextNode;
			else nextNode = nextNode->left;
		}
	}
	return NULL;
}

Node * utility::tree::IntegerTree::getParentOf(Node* startNode, Node * node)
{
	Node* nextNode = startNode;

	if (startNode == NULL) return NULL;
	if (startNode == node) return NULL;

	if (nextNode->left == node) return nextNode;
	else if (nextNode->right == node) return nextNode;

	nextNode = getParentOf(nextNode->left, node);
	if (nextNode != NULL) return nextNode;
	nextNode = nextNode->right;
	nextNode = getParentOf(nextNode->right, nextNode);
	return nextNode;
}

void utility::tree::IntegerTree::preVisit(Node * node, void(*funcPtr)(Node *))
{
	if (node == NULL) return;
	funcPtr(node);
	preVisit(node->left, funcPtr);
	preVisit(node->right, funcPtr);
}

void utility::tree::IntegerTree::inVisit(Node * node, void(*funcPtr)(Node *))
{
	if (node == NULL) return;
	inVisit(node->left, funcPtr);
	funcPtr(node);
	inVisit(node->right, funcPtr);
}

void utility::tree::IntegerTree::postVisit(Node * node, void(*funcPtr)(Node *))
{
	if (node == NULL) return;
	postVisit(node->left, funcPtr);
	postVisit(node->right, funcPtr);
	funcPtr(node);
}

void utility::tree::IntegerTree::traverse(Traversal way, void(*funcPtr)(Node *))
{
	Node* nextPtr = rootPtr;
	switch (way) {
	case PRE: 
		preVisit(nextPtr, funcPtr);
		break;
	case IN:
		inVisit(nextPtr, funcPtr);
		break;
	case POST:
		postVisit(nextPtr, funcPtr);
		break;
	}
}

Node * utility::tree::IntegerTree::findInBst(Node* startNode, int value)
{
	Node* nextNode = startNode;

	while (nextNode) {
		if (nextNode->value == value) return nextNode;
		else {
			if (nextNode->value >= value) {
				nextNode = nextNode->left;
			}
			else {
				nextNode = nextNode->right;
			}
		}
	}

	return nullptr; // [CheatSheet]
}

Node * utility::tree::IntegerTree::insertInBst(int value, bool (*leftAddPredicate)(int newValue, int nodeValue))
{
	Node* node = rootPtr;

	if (!node) {
		node = new (nothrow) Node;
		createNode(node, value);
		rootPtr = node;
		return node;
	}

	while (node) {
		if (leftAddPredicate(value, node->value)) {
			if (node->left) {
				node = node->left;
			}
			else {
				node->left = new (nothrow) Node();
				createNode(node->left, value);
				break;
			}
		}
		else {
			if (node->right) {
				node = node->right;
			}
			else {
				node->right = new (nothrow) Node();
				createNode(node->right, value);
				break;
			}
		}
	}

	return NULL;
}

void utility::tree::IntegerTree::removeInBst(Node *startNode, int value)
{
	Node* node;
	if (!startNode) return;

	node = findInBst(startNode, value);

	if (node == NULL) {
		cout << "Can't find and delete: " << value << endl;
		return;
	}

	if (node->left != NULL && node->right != NULL) {
		// if all left or right
		Node *toSwap = getNextToSwap(node);
		// case of three: no child, only one child, two child
		if (toSwap) {
			int tmp = node->value;
			node->value = toSwap->value;
			toSwap->value = tmp;
			removeInBst(toSwap, toSwap->value);
		}
	}
	else if (node->left != NULL) {
  		// parent of this node should set null
		Node *parent = getParentOf(rootPtr, node);
		if (!parent) rootPtr = node->left;
		else {
			if (parent->left->value == node->value) parent->left = node->left;
			else parent->right = node->left;
		}
		delete node; // leaf node case
	}
	else if (node->right != NULL) {
		// parent of this node should set null
		Node *parent = getParentOf(rootPtr, node);
		if (!parent) {
			rootPtr = node->right;
		}
		else {
			if (parent->left->value == node->value) parent->left = node->right;
			else parent->right = node->right;
		}
		delete node; // leaf node case

	}
	else {
		Node *parent = getParentOf(rootPtr, node);
		cout << parent->value << endl;
		if (!parent) {
			rootPtr = NULL; // set root null
		}
		else {
			if (parent->left->value == node->value) parent->left = NULL;
			else parent->right = NULL;
		}
		delete node; // leaf node case

	}
}

int utility::tree::IntegerTree::getMaxHeight()
{
	return 0;
}

bool utility::tree::IntegerTree::isBST()
{
	return false;
}

bool utility::tree::IntegerTree::isBalanced()
{
	return false;
}

void utility::tree::IntegerTree::createTree(int* arr, int size, bool(*leftAddPredicate)(int newValue, int nodeValue)) 
{
	int index = 1;
	Node* nextNodePtr = NULL;
	assert(arr);
	rootPtr = addNode(arr, size, 0);

	while (index < size) {
		nextNodePtr = rootPtr;
		while (nextNodePtr) {
			if (leftAddPredicate(arr[index], nextNodePtr->value)) {
				if (nextNodePtr->left) {
					nextNodePtr = nextNodePtr->left;
				}
				else {
					nextNodePtr->left = addNode(arr, size, index);
					//cout << "[node] " << nextNodePtr->left->value << endl;
					break;
				}
			}
			else {
				if (nextNodePtr->right) {
					nextNodePtr = nextNodePtr->right;
				}
				else {
					nextNodePtr->right = addNode(arr, size, index);
					//cout << "[node] " << nextNodePtr->right->value << endl;
					break;
				}
			}
		}
		index++;
	}
}

void utility::tree::IntegerTree::getLowestCommonAncestor(int value1, int value2)
{
}

int utility::tree::IntegerTree::getDistance(int value1, int value2)
{
	return 0;
}

Node * utility::tree::IntegerTree::getInorderSuccessor(int value)
{
	return nullptr;
}

Node * utility::tree::IntegerTree::getLargestBST()
{
	return nullptr;
}

Node * utility::tree::IntegerTree::toBSTfromBT()
{
	return nullptr;
}

Node * utility::tree::IntegerTree::converToSumTree()
{
	return nullptr;
}

int utility::tree::IntegerTree::getMaxLevelSum()
{
	return 0;
}

bool utility::tree::IntegerTree::isIdentical(Node * roo1, Node * root2)
{
	return false;
}

string utility::tree::IntegerTree::serialize(Node *)
{
	return string();
}

Node * utility::tree::IntegerTree::deserialize(string)
{
	return nullptr;
}

int utility::tree::IntegerTree::getKthSmallest() // [NF]
{
	return 0;
}

int utility::tree::IntegerTree::allPossibleBST(int * array, int size)
{
	return 0;
}
