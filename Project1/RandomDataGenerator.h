#pragma once

#define STRING_MAX_ROW 100000 // big enough to hold any string
#define STRING_MAX_LEN 51 // total strlen should be max 50

#define INT_MAX_SIZE 100000

// length means actual based on strlen so +1 is needded to buffer
int randomFixedLenStringGenerator(int length, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN]);
// length means actual based on strlen so +1 is needded to buffer
int randomVarLenStringGenerator(int minLength, int maxLength, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN]);
int randomIntGenerator(int min, int max, int numOf, int* intArray);