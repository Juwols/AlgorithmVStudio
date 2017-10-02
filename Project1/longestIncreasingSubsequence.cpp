#include <iostream>

using namespace std;

static int ar[10] = { 0, 3, 4, 5, 1, 2, 7, 6, 9, 8 };
static int memo[10] = { 0, };

int lcs(int start) {
	int tmp;
	int max = 1;

	if (memo[start] != 0) return memo[start];

	for (int i = start + 1; i < 10; i++) {
		if (ar[start] < ar[i]) {
			tmp = 1 + lcs(i);
			if (tmp > max) max = tmp;
		}
	}


	return memo[start] = max;
}

int simple_lcs() {
	int i;
	i = lcs(0);
	cout << i - 1 << endl;
	return 0;
}
