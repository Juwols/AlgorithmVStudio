#include <iostream>
#include <exception>
#include <stdexcept> // last_visit: standard exception

using namespace std;

class MyException2 : public runtime_error {
	virtual const char* what(const string& msg) const noexcept { // last_visit: vcc what cn
		string s = "FUCK";
		return s.c_str();
	}
};

class MyException : public runtime_error { // memo-20171029: difference runtime_error vs. exception
	// memo_201706: invalid_argument, bad_alloc, bad_cast, out_of_range, overflow_error, underflow_error
public:
	MyException(const string& str) : runtime_error(str.c_str()), _str(str) {
	};
	virtual const char* what() const noexcept { // memo_201706
		return _str.c_str();
	}
private:
	string _str;
};

int cppCheatSheet_exception() {
	try {
		throw MyException("vincent"); // memo_201710: it is better to throw call by value and receive by const &
	}
	catch (const MyException& m) { // memo_201710: it is better to throw call by value and receive by const &
		cout << m.what() << endl;
		throw;
		throw (bad_alloc());
	}
	return 0;
}
