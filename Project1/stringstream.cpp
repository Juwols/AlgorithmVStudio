#include <iostream>
#include <sstream>

using namespace std;

void testStringStream() {
	stringstream ss;
	int part_index = 10;
	ss << "chunk_" << part_index << ".txt";
}