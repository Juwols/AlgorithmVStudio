// [NF] 
// https://www.glassdoor.com/Interview/Netflix-Interview-Questions-E11891_P8.htm?filter.jobTitleFTS=software
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

using namespace std;

class DynamicSingleton {
private:
	DynamicSingleton() : value(100) {}
	~DynamicSingleton() {}
	int value;
	static DynamicSingleton* instance; // memo_201710: this is ok to private
	static mutex mMutex;
public:
	static DynamicSingleton *GetInstance() {
		unique_lock<mutex> uniqueLock(mMutex);

		if (instance == NULL) {
			cout << "New creation of singleton" << endl;
			instance = new DynamicSingleton();
		}
		return instance;
	}
	void print() { cout << value << endl; }
};

DynamicSingleton* DynamicSingleton::instance = NULL; // memo_201710: this is ok to private
mutex DynamicSingleton::mMutex; // memo_201710: this is ok to private

int singletonTest() {
	thread t1{
		[&] () {
			DynamicSingleton::GetInstance()->print();
		}
	};
	thread t2{
		[&]() {
		DynamicSingleton::GetInstance()->print();
	}
	};
	t1.join();
	t2.join();
	//cout << DynamicSingleton::instance << endl;
	return 0;
}