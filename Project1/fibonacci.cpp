#include <iostream>

using namespace std;
#if 0
int memo[1000] = { 0, };

int fibo(int i) {
	if (memo[i] != 0) return memo[i];

	if (i == 1 || i == 2) {
		memo[i] = 1;
		return memo[i];
	}

	return (memo[i] = fibo(i - 1) + fibo(i - 2));
}
#endif

int memo[1000] = { 0, };

int fibo(int value) {
	if (memo[value] != 0) return memo[value];
	if (value == 1 || value == 2) return 1;

	int& ret = memo[value];
	ret = fibo(value - 1) + fibo(value - 2);
	return ret;
}

int fibonacciTest() {
	int input;
	cin >> input;

	int r = fibo(input);

	cout << r << endl;
	return 0;
}
