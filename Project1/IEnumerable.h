#pragma once

#include "iteratorPattern.h"

template <typename T>
class IEnumerable {
 public:
	 virtual Iterator<T> begin() = 0; // memo_201710: Do not forget virtual for pure virtual function
	 virtual Iterator<T> end() = 0;
	 // virtual Iterator<T> moveNext(); // memo_201710: better design to provide moveNext and hide actual pointer of head
};
