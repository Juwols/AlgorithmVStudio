#include <iostream>
#include <algorithm>

using namespace std;

static char str[20];

static int add[20];
static int sub[20];

static int bet[20];

static int gMin = 987654321;

static int  minPalindrome(int start, int end, int sum) {
	if (start >= end) return sum;

	//start fix
	//// adding
	if (str[start] == str[end])
		gMin = min(gMin, minPalindrome(start + 1, end - 1, sum));

	gMin = min(gMin, minPalindrome(start + 1, end, sum + bet[str[start] - 'a']));

	gMin = min(gMin, minPalindrome(start, end - 1, sum + bet[str[end] - 'a']));

	return gMin;
}

int minPalindromeTest() {

	int len, num;
	cin >> len;
	cin >> num;
	cin >> str;

	for (int i = 0; i < num; i++) {
		cin >> add[i];
		cin >> sub[i];

		if (add[i] < sub[i]) bet[i] = add[i];
		else bet[i] = sub[i];
	}

	minPalindrome(0, len - 1, 0);

	cout << "r:" << gMin << endl;
	return 0;
}
