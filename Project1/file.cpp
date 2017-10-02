
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

int fileTest() {
	ifstream inFile2("name");
	ofstream outFile2("name2", ios_base::in);
	if (outFile2.fail()) throw invalid_argument("test");
	ifstream inFile("file.txt"); // revisit
	ofstream outFile("out.txt", ios_base::app); // revisit: ios_base:app, in, out

	if (inFile.fail()) { // revisit
		throw invalid_argument("bad file name"); // revisit: exceptions
	}
	int nextToken;
	while (inFile >> nextToken) { // revisit: file read inFile returns NULL when no data available
		cout << "next: " << nextToken << endl;
		outFile << nextToken << ":";
	}
	inFile.close();
	outFile.close();
	return 0;
}
