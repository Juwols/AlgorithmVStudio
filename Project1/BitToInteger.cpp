#include <iostream>

using namespace std;

int bitToIntegerTest() {
	unsigned int original = 1 + (2 << 8) + (3 << 16) + (128 << 24);
	int signedVal = 128 << 24;
	unsigned int unsignedVal = signedVal;
	cout << "A: " << signedVal << endl;
	cout << "B: " << unsignedVal << endl;
	int an1 = signedVal >> 1;
	unsigned int an2 = signedVal >> 1;
	unsigned int an3 = 1 << 31;
	unsigned int an4 = an3 >> 1; // memo-20171118: if an3 is unsigned, 0 is filled 
	unsigned int trueOriginal = original;
	char val[4];
	int shiftValue = 0;
	unsigned int mask = (1 << 8) - 1;
 	for (int x = 0; x < 4; x++) {
		unsigned int tmp = original >> shiftValue;
		val[x] = (unsigned char)(mask & tmp);
		shiftValue += 8; 
	}

	unsigned int dest = val[0] + (val[1] << 8) + (val[2] << 16) + (val[3] << 24);

	cout << "compare: " << trueOriginal << "," << dest << endl;
	return 0;
}
