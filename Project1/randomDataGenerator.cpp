#include <iostream>
#include <time.h>
#include "RandomDataGenerator.h"

using namespace std;

int randomStringGenerator(int length, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN]) {
	time_t t = time(NULL);
	srand(t);
	for (int i = 0; i < numOf; i++) {
		for (int j = 0; j < length - 1; j++) {
			int s = rand() % 36;

			if (s < 10) { // digrit
				strArray[i][j] = '0' + s;
			}
			else { // 10 ~ 35
				strArray[i][j] = 'a' + s - 10;
			}
		}
		strArray[i][length - 1] = '\0';
	}
	return 0;
}

int randomIntGenerator(int min, int max, int numOf, int* intArray) {
	time_t t = time(NULL);
	srand(t);

	int minFromZero = min;
	int maxFromZero = max - min;

	for (int i = 0; i < numOf; i++) {
		int temp = rand();
		// if value is more than maxFromZero, then
		int rValue = temp % (maxFromZero + 1);
		rValue += minFromZero;
		intArray[i] = rValue;
	}

	return 0;
}