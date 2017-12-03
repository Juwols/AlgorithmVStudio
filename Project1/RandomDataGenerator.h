#pragma once

#define STRING_MAX_ROW 100000 // big enough to hold any string
#define STRING_MAX_LEN 30

#define INT_MAX_SIZE 100000

int randomStringGenerator(int length, int numOf, char strArray[STRING_MAX_ROW][STRING_MAX_LEN]);
int randomIntGenerator(int min, int max, int numOf, int* intArray);