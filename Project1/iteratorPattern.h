#pragma once

#include <iostream>
#include <memory>

#include "node.h"

using namespace std;

template <typename T>
class Iterator {
public:
	Iterator(shared_ptr<Node<T>> h);
	virtual ~Iterator();
	Iterator<T>& operator++();
	bool operator==(const Iterator<T>& rhs);
	bool operator!=(const Iterator<T>& rhs);
	T operator*();
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> pos;
private:
};
