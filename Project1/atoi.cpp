// [NF]
// https://www.glassdoor.com/Interview/Netflix-Interview-Questions-E11891_P9.htm?filter.jobTitleFTS=software
// write atoi

#include <iostream>

using namespace std;

int atoiTest() {
	char str[25];
	cin >> str;
	int size = strlen(str);
	int decimal = 1;
	int sum = 0;
	for (int i = size - 1; i >= 0; i--) {
		int value = ((int)(str[i] - 48)) * decimal;
		sum += value;
		decimal *= 10;
	}

	cout << sum << endl;
	return 0;
}