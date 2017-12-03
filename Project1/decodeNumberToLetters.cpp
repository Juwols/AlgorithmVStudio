#include <iostream>
#include <sstream>
#include <assert.h>
using namespace std;

/*
  when given number, 123 => 1, 23 or 1, 2, 3 or 12, 3

  10,12....19,
  20,2...6
*/

int gTotal;

void decode(int index, string str, string result) { 
	if (index == str.size()) {
		gTotal++;
		cout << result << endl;
		return;
	}

	int thisNum = str[index] - 48;
	char c1, c2;

	if (index == (str.size() - 1)) {
		c1 = 'a' + str[index] - '0' - 1; // 65 + 3
		decode(index + 1, str, result + c1); // one way
	}
	else if (thisNum > 2) {
		c1 = 'a' + str[index] - '0' - 1;
		decode(index + 1, str, result + c1); // one way
	}
	else if (thisNum == 2) {
		int nextNum = str[index + 1] - 48;
		if (nextNum > 6) {
			c1 = 'a' + str[index] - '0' - 1;
			decode(index + 1, str, result + c1); // one way
		}
		else if (nextNum == 0) {
			int num = stoi(str.substr(index, 2));
			c2 = 'a' + num - 1;
			decode(index + 2, str, result + c2); // one way
		}
		else {
			c1 = 'a' + str[index] - '0' - 1;
			decode(index + 1, str, result + c1); // one way
			int num = stoi(str.substr(index, 2));
			c2 = 'a' + num - 1;
			decode(index + 2, str, result + c2); // one way
		}
	}
	else if (thisNum == 1) {
		int nextNum = str[index + 1] - 48;
        if (nextNum == 0) {
			int num = stoi(str.substr(index, 2));
			c2 = 'a' + num - 1;
			decode(index + 2, str, result + c2); // one way
		}
		else {
			c1 = 'a' + str[index] - '0' - 1;
			decode(index + 1, str, result + c1); // one way
			int num = stoi(str.substr(index, 2));
			c2 = 'a' + num - 1;
			decode(index + 2, str, result + c2); // one way
		}
	}
	else {
		assert(0);
	}
}

int decodeTest() {
	int i; 
	cin >> i;
	stringstream ss;
	ss << i ;
	cout << ss.str() << endl;
	gTotal = 0;
	decode(0, ss.str(), "");
	cout << "total:" << gTotal << endl;
	return 0;
}