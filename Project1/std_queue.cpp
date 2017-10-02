#include <iostream>
#include <queue>
#include <stdexcept>

using namespace std;

int std_queue() {
	queue<int> q;

	q.push(1);
	q.push(2);
	cout << "now fron: " << q.front() << endl;;
	cout << "size: " << q.size() << endl;
	q.pop();
	cout << "now fron: " << q.front() << endl;;
	q.pop();

	if (q.empty()) throw out_of_range("buffer is empty");
}

