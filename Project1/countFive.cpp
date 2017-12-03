#include <iostream>

using namespace std;

int testCount() {
	unsigned long long int val = 1;

	for (int i = 1; i <= 25; i++) {
		val = val * i;
	}
	cout << "total: " << val << endl;
	return 0;
}