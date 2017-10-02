#include <iostream>

using namespace std;

int memo[1000] = { 0, };

int fibo(int i) {
	if (memo[i] != 0) return memo[i];

	if (i == 1 || i == 2) {
		memo[i] = 1;
		return memo[i];
	}

	return (memo[i] = fibo(i - 1) + fibo(i - 2));
}

int fibonacci() {
	int input;
	cin >> input;

	int r = fibo(input);

	cout << r << endl;
	return 0;
}
