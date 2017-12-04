#include <iostream>
#include <time.h>
#include <sstream>

#include "RandomDataGenerator.h"

using namespace std;

void randomInit() {
	time_t n = time(NULL);
	srand(n);
}

int randomIntSelector(int minIndex, int maxIndex) {
	int rSize = maxIndex - minIndex + 1;
	return (rand() % (rSize+1)) + minIndex;
}

int randomFixedLenStringGenerator(int length, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN], bool unique, int offset) {
	for (int i = 0; i < numOf; i++) {
		for (int j = 0; j < length; j++) {
			int s = rand() % 36;

			if (s < 10) { // digrit
				strArray[i + offset][j] = '0' + s;
			}
			else if (s >= 10 && s <= 16) { // :~ @
				strArray[i + offset][j] = 'a' + s - 10; // do not allow special characters
			}
			else { // a ~ z
				strArray[i + offset][j] = 'a' + s - 17; // s is at least 17
			}
		}
		strArray[i][length] = '\0';
		// update string with unique header
        if (unique) {
			stringstream ss;
			ss << (i + offset) << "@";
			for (int k = 0; k < ss.str().size(); k++) {
				strArray[i + offset][k] = ss.str().at(k);
			}
			if (length < ss.str().size()) {
				strArray[i + offset][ss.str().size()] = '\0';
			}
		}
	}
	return numOf + offset - 1;
}


int randomVarLenStringGenerator(int minLength, int maxLength, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN], bool unique, int offset) {
	int rSize = maxLength - minLength;
	for (int i = 0; i < numOf; i++) {
		int rLength = minLength + rand() % (rSize + 1);
		for (int j = 0; j < rLength; j++) {
			int s = rand() % 36;

			if (s < 10) { // digrit
				strArray[i + offset][j] = '0' + s;
			}
			else if (s >= 10 && s <= 16) { // :~ @
				strArray[i + offset][j] = 'a' + s - 10; // do not allow special characters
			}
			else { // a ~ z
				strArray[i + offset][j] = 'a' + s - 17; // s is at least 17
			}
		}
		strArray[i + offset][rLength] = '\0';

		// update string with unique header
		if (unique) {
			stringstream ss;
			ss << (i + offset) << "@";
			for (int k = 0; k < ss.str().size(); k++) {
				strArray[i + offset][k] = ss.str().at(k);
			}
			if (rLength < ss.str().size()) {
				strArray[i + offset][ss.str().size()] = '\0';
			}
		}
	}
	return numOf + offset - 1;
}

int randomIntGenerator(int min, int max, int numOf, int* intArray, bool unique, int offset) {
	int minFromZero = min;
	int maxFromZero = max - min;
	if (unique) {
		for (int i = 0; i < numOf; i++) {
			intArray[i + offset] = min + i + offset;
		}
	}
	else {
		for (int i = 0; i < numOf; i++) {
			int temp = rand();
			// if value is more than maxFromZero, then
			int rValue = temp % (maxFromZero + 1);
			rValue += minFromZero;
			intArray[i + offset] = rValue;
		}
	}
	return numOf + offset - 1;
}

