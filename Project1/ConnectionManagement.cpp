#include <iostream>
#include "RandomDataGenerator.h"
#include <time.h>
#include <list>

using namespace std;

static char gId[STRING_MAX_ROW][STRING_MAX_LEN];
static char gPasswd[STRING_MAX_ROW][STRING_MAX_LEN];
static int gDefaultTime[INT_MAX_SIZE];
static int gCurrentTime[INT_MAX_SIZE];
static int gIsLogout[INT_MAX_SIZE];

#define ID_MIN_LEN 5
#define ID_MAX_LEN 10

#define PASSWD_MIN_LEN 5
#define PASSWD_MAX_LEN 10

#define DEFAULT_MIN_TIME 1
#define DEFAULT_MAX_TIME 30000

#define NEW_ACCOUNT_CALL_MAX 50000

#define TICK_CALL_MAX 50000

enum Actions {
	NEW_ACCOUNT,
	CONNECT,
	LOG_OUT,
	TICK
};

// my code
typedef struct _Node {
	char id[12];
	char password[12];
	int defaultTime;
	int currentTime;
	bool isLogout;
} Node;

list<Node> gList;
// end of my code

void doInit() {
	// do init here
}

void doNewAccount(char* id, char* passwd, int default) {
	//cout << "[NEW] " << id << ":" << passwd << ":" << default << endl;
	Node n;
	strcpy_s(n.id, id);
	strcpy_s(n.password, passwd);
	n.defaultTime = default;
	n.currentTime = default;
	n.isLogout = false;

	gList.push_back(n);
}

void doConnect(char* id, char* passwd) {
	list<Node>::iterator itor = gList.begin();

	for (itor; itor != gList.end(); itor++) {
		if (strcmp(itor->id, id) == 0 &&
			strcmp(itor->password, passwd) == 0 && 
			itor->isLogout == false) {
			itor->currentTime = itor->defaultTime;
		}
	}
	//cout << "[Connect] " << id << ":" << passwd << endl;
}

void doLogout(char* id) {
	list<Node>::iterator itor = gList.begin();

	for (itor; itor != gList.end(); itor++) {
		if (strcmp(itor->id, id) == 0 &&
			itor->isLogout == false) {
			itor->isLogout = true;
			itor->currentTime = 0;
		}
	}
	//cout << "[Logout] " << id << endl;
}

int doTick() {
	list<Node>::iterator itor = gList.begin();
	int count = 0;
	for (itor; itor != gList.end(); itor++) {
		if (itor->isLogout == false) {
			if (itor->currentTime > 0) {
				itor->currentTime = itor->currentTime - 1;

				if (itor->currentTime == 0) {
					itor->isLogout = true;
					//cout << "[my] " << itor->id << " log out " << endl;
					count++;
				}
			}
		}
	}

	return count;
}

int connectionManagementTest() {
	int idOffset = -1;
	int passwdOffset = -1;
	int defaultTimeOffset = -1;

	randomInit();
	for (int i = 0; i < 1; i++) {
		// generate ID 10000¹ø
		idOffset = randomVarLenStringGenerator(ID_MIN_LEN, ID_MAX_LEN, 10000, gId, true, idOffset+1);
		passwdOffset = randomVarLenStringGenerator(PASSWD_MIN_LEN, PASSWD_MAX_LEN, 10000, gPasswd, false, passwdOffset+1);
		defaultTimeOffset = randomIntGenerator(DEFAULT_MIN_TIME, DEFAULT_MAX_TIME, 10000, gDefaultTime, false, defaultTimeOffset + 1);

		for (int k = 0; k <= idOffset; k++) {
			gIsLogout[k] = false; // set logout true
			gCurrentTime[k] = gDefaultTime[k]; // set current time to default time

 		    // TODO: fill your account by yourself for 10000 account
			doNewAccount(gId[k], gPasswd[k], gDefaultTime[k]);
		}

		for (int j = 0; j < 1000; j++) {
			int tmp = rand() % 4;

			if (tmp == NEW_ACCOUNT) {
				idOffset = randomVarLenStringGenerator(ID_MIN_LEN, ID_MAX_LEN, 1, gId, true, idOffset + 1);
				passwdOffset = randomVarLenStringGenerator(PASSWD_MIN_LEN, PASSWD_MAX_LEN, 1, gPasswd, false, passwdOffset + 1);
				defaultTimeOffset = randomIntGenerator(DEFAULT_MIN_TIME, DEFAULT_MAX_TIME, 1, gDefaultTime, false, defaultTimeOffset + 1);

				gIsLogout[idOffset] = false; // set logout true
				gCurrentTime[idOffset] = gDefaultTime[idOffset]; // set current time to default time

				// TODO: fill your account by yourself for one account
				doNewAccount(gId[idOffset], gPasswd[passwdOffset], gDefaultTime[defaultTimeOffset]);
			}
			else if (tmp == CONNECT) {
				// select ID and passwd (sometimes wrong)
				int index = randomIntSelector(0, idOffset);

				if (time(NULL) % 2) {
					// set as default time if connected
					if (gIsLogout[index] == false) {
						gCurrentTime[index] = gDefaultTime[index];
					}

					// TODO: handle connect request
					doConnect(gId[index], gPasswd[index]);
				}
				else {
					// TODO: handle connect request
					doConnect(gId[index], gId[index]);
				}
			}
			else if (tmp == LOG_OUT) {
				//log out this user. if no user exists for the id, ignore
				// select ID and logout
				int index = randomIntSelector(0, idOffset);
				if (gIsLogout[index] == false) {
					gIsLogout[index] = true;
					gCurrentTime[index] = 0;
				}

				// TODO: handle logout
				doLogout(gId[index]);
			}
			else { // tmp is Tick
				int testerCount = 0;
				for (int y = 0; y <= idOffset; y++) {
					if (gIsLogout[y] == false) {
						gCurrentTime[y]--;

						if (gCurrentTime[y] == 0) {
							gIsLogout[y] = true;
							testerCount++;
							//cout << "[test] " << y << " is out" << endl;
						}
					}
				}
				//reduce all remaining time by 1
				int myAnswer = doTick();
				if (myAnswer != testerCount) {
					cout << "[Tick] test failed !!!! " << endl;
					return 1;
				}
			}
		}
		// random(all) + tick 10000¹ø

		list<Node>::iterator itorFinal = gList.begin();
		for (int x = 0; x <= idOffset; x++) {
			if ((strcmp(itorFinal->id, gId[x]) == 0) &&
				(strcmp(itorFinal->password, gPasswd[x]) == 0) &&
				itorFinal->isLogout == gIsLogout[x] &&
				itorFinal->currentTime == gCurrentTime[x] &&
				itorFinal->defaultTime == gDefaultTime[x]) {

			}
			else {
				cout << x << " of " << idOffset << ": wrong !!!! test failed !!!! " << endl;
				return 1;
			}
			itorFinal++;
		}
		cout << "Test success !!!! " << endl;
	}
	return 0;
}