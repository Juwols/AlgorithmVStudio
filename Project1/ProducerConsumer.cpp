// [NF] lock/unlock/wait/notify
// https://www.glassdoor.com/Interview/Netflix-Interview-Questions-E11891_P8.htm?filter.jobTitleFTS=software
// Explain wait and notify.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable> // last_visit: condition variable
#ifdef __unix__ // memo_201710: indicator for unix and windows cross-compile
#include <unistd.h>
#elif defined(_WIN32) || defined(WIN32) 
#include <windows.h>
#endif

using namespace std;

int producerConsumer() {
	mutex mMutex;
	condition_variable mCondvar;

	// one producer
	thread th1([&] {
		int count = 10;
		while (true) {
			cout << "[pdd] entering lock " << endl;
			unique_lock<mutex> lock(mMutex); // last_visit: unique_lock<mutex> lock(mMutex); 
			mCondvar.notify_all(); // last_visit: m.nofity_all
			count--;
			if (count < 0) break;
			lock.unlock();
#ifdef __unix__ 
			sleep(2);
#elif defined(_WIN32) || defined(WIN32)
			Sleep(2);
#endif
		}});

	// one consumer
	thread th2([&] {
		while (true) {
			cout << "[css] condwait.wait" << endl;
			unique_lock<mutex> lock(mMutex);
			mCondvar.wait(lock); // last_visit: condiva.wait(mutex)
								 // if got here, notified
			cout << "[css] lock.unlock(); .... " << endl;
			cout << "[css] Consume:: take care of queue exclusively .... " << endl;
			lock.unlock();
		}});
	th1.join();
	th2.join();
	return 0;
}

