// [NF]
//https://www.glassdoor.com/Interview/Letter-Combinations-of-a-Phone-Number-QTN_1018153.htm

#include <iostream>

using namespace std;

char phoneKeys[10][5] = { 
	"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

int gInt;

void iteratePossibility(int current, char *input, string s) {
	if (current == strlen(input)) {
		cout << s.c_str() << endl;
		gInt++;
	}
	int sizeOfCurrent = input[current];
	int keyNum = input[current] - 48;
	if (keyNum == 0 || keyNum == 1) {
		cout << "Can't parse " << endl;
		exit(0);
	}
	int keyLen = strlen(phoneKeys[keyNum]);
	for (int i = 0; i < keyLen; i++) {
		string newS = s + phoneKeys[keyNum][i];
		iteratePossibility(current + 1, input, newS);
	}
}

int keyPadLetterTest() {
	char input[25];
	cin >> input;
	int size = strlen(input);
	gInt = 0;
	iteratePossibility(0, input, "");
	cout << "total: " << gInt << endl;
	return 0;
} 