#pragma once
#include <iostream>
#include <mutex>
#include "iteratorPattern.h"
#include "IEnumerable.h"

using namespace std;

template <typename T>
class vclist : public IEnumerable<T> {
public:
	vclist();
	virtual ~vclist();
	virtual void push_front(T t);
	virtual void push_back(T t);
	virtual void pop_front();
	virtual void pop_back();
	virtual T front();
	virtual T back();
	Iterator<T> begin();
	Iterator<T> end();
	virtual void insert(T t);
	virtual void erase(T t);
	virtual int size();
	virtual bool find(T t);
	// top
	// add (lambda enabled)
	// subclassing vclist so it can add top, add, and disable front (is it possible??? polymophism) 
	// iterator
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> tail;
	mutex mutex1;
	//Node<T>** itorator;
	int count;
private:
	// prohibit copy constructor
	// vclist(const T& obj); Todo
	// do not delete???? memo-201706
};
