#include <iostream>
#include <vector>
using namespace std;

void testSimpler(int n) {
	vector<vector<int>> m(n, vector<int>(n, 0));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c <= r; c++) {
			if (c == 0) m[r][c] = 1;
			else if (c == r) m[r][c] = 1;
			else m[r][c] = m[r - 1][c] + m[r - 1][c - 1];
		}
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c <= r; c++) {
			cout << m[r][c] << " ";
		}
		cout << "" << endl;
	}
}

void testO3(int line) { // memo_201710: how to allocate double array? may easier with vector
	int *arrayP = (int*)malloc(sizeof(int) * (line + 1) * (line + 1));
	memset(arrayP, 0, sizeof(int)*(line + 1)*(line + 1));

	if (!arrayP) return;
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= i; j++) {

			if (j == 1) {
				arrayP[i * (line + 1) + j] = 1;
			}
			else if (j == i) {
				arrayP[i * (line + 1) + j] = 1;
			}
			else {
				arrayP[i * (line + 1) + j] = arrayP[i * (line + 1) + j - (line+1)] +
					arrayP[i * (line + 1) + j - (line + 2)];
			}
		}
	}
	for (int i = 1; i <= line; i++) {
		for (int j = 1; j <= i; j++ ) {
			cout << arrayP[i*(line + 1) + j] << " ";
		}
		cout << "" << endl;
	}
}

int pascalTriangleTest() {
	int line;
	cin >> line;
	//testO3(line);
	testSimpler(line);
	return 0;
}