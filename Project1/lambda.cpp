#include <iostream>

using namespace std;

int lambdaTest() {
	auto fn = [](string str) { return "hello " + str; };
	auto fn1 = [](string str) { return "my life" + str; };
	//cout << fn1("ABC") << endl;
	int x = 1000;
	//cout << fn("call 1") << endl;
	//cout << fn("call 2") << endl;

	auto fn2 = [=](string str) -> int { return  2 * x; };
	cout << fn2("good") << endl;
	return 0;
}
