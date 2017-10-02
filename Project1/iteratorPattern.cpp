#include <iostream>
#include "iteratorPattern.h"
#include <stdexcept>

using namespace std;

template <typename T>
Iterator<T>::Iterator(shared_ptr<Node<T>> h) : head(h), pos(h) {

}

template <typename T>
Iterator<T>& Iterator<T>::operator++() { // memo_201710: ++ returns same type of & and it is *this
	if (pos != NULL) {
		pos = pos->next;
	}
	else {
		throw underflow_error("no more possible");
	}
	return *this;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator<T>& rhs) {
	if (pos == rhs.pos) return true;
	else return false;
}
// need to define equal here

template <typename T>
bool Iterator<T>::operator!=(const Iterator<T>& rhs) {
	if (pos == rhs.pos) return false;
	else return true;
}

template <typename T>
T Iterator<T>::operator*() {
	return (pos->value);
}

template <typename T>
Iterator<T>:: ~Iterator() {
	//cout << "Destructor" << endl;
}

template class Iterator<int>;
