#include <iostream>
#include <algorithm>

using namespace std;

static string str = "BBABCBCAB";

static int longPalindrom(int startIndex, int endIndex) {
	if (startIndex == endIndex) return 1;
	if (startIndex > endIndex) return 0;
	if (str[startIndex] == str[endIndex]) {
		return 2 + longPalindrom(startIndex + 1, endIndex - 1);
	}
	else {
		return max(longPalindrom(startIndex + 1, endIndex), longPalindrom(startIndex, endIndex - 1));
	}
}

static string longPalindromStr(int startIndex, int endIndex) {
	string cs1(1, str[startIndex]);
	string cs2(1, str[endIndex]);
	if (startIndex == endIndex) return cs1;
	if (startIndex > endIndex) return "";
	if (str[startIndex] == str[endIndex]) {
		return cs1 + longPalindromStr(startIndex + 1, endIndex - 1) + cs2;
	}
	else {
		string s1 = longPalindromStr(startIndex + 1, endIndex);
		string s2 = longPalindromStr(startIndex, endIndex - 1);
		if (s1.size() > s2.size()) return s1;
		else return s2;
	}
}

int palindromTest() {
	cout << longPalindrom(0, str.size() - 1) << endl;
	//cout << longPalindromStr(0, str.size() - 1) << endl;
	return 0;
}
