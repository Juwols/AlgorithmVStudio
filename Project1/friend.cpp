#include <iostream>

using namespace std;

class FriendA {
public:
	friend class FriendB;
private:
	int a;
};

class FriendB {
public:
	void print() {
		FriendA obj;
		obj.a = 100;
		cout << obj.a << endl;
	}
};

int testFriend() {
	FriendB b;
	b.print();
	return 0;
}
