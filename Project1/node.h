#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
	T value;
	virtual ~Node() {
		cout << "Node destructor : " << value << endl;
	}
	shared_ptr<Node<T>> next;
	shared_ptr<Node<T>> prev;
};

