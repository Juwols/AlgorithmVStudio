#include <iostream>
#include "RandomDataGenerator.h"
#include <time.h>
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

void doNewAccount(char* id, char* passwd, int default) {
	cout << "[NEW] " << id << ":" << passwd << ":" << default << endl;
}

void doConnect(char* id, char* passwd) {
	cout << "[Connect] " << id << ":" << passwd << endl;
}

void doLogout(char* id) {
	cout << "[Logout] " << id << endl;
}

int doTick() {
	cout << "[Tick] " << endl;
	return 0;
}

int connectionManagementTest() {
	int idOffset = -1;
	int passwdOffset = -1;
	int defaultTimeOffset = -1;

	randomInit();
	for (int i = 0; i < 3; i++) {
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

		for (int j = 0; j < 10000; j++) {
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
				if (gIsLogout[index] == false)
					gIsLogout[index] = true;

				// TODO: handle logout
				doLogout(gId[index]);
			}
			else { // tmp is Tick
				//reduce all remaining time by 1
				doTick();
			}
		}
		// random(all) + tick 10000¹ø
	}
	return 0;
}
//	randomVarLenStringGenerator(ID_MIN_LEN, ID_MAX_LEN, ID_NUM, gId, true);
//
//	for (int i = 0; i < ID_NUM; i++)
//		cout << gId[i] << endl;
//
//	cout << "Next string generation...." << endl;
//
//	randomFixedLenStringGenerator(PASSWD_LEN, PASSWD_NUM, gPasswd, true);
//
//	for (int i = 0; i < PASSWD_NUM; i++)
//		cout << gPasswd[i] << endl;
//
//	randomIntGenerator(ACTION_MIN, ACTION_MAX, ACTION_NUM, gAction, true);
//
//	for (int i = 0; i < ACTION_NUM; i++)
//		cout << gAction[i] << endl;
//
//	randomIntGenerator(CAR_MIN, CAR_MAX, CAR_NUM, gCar, true);
//
//	for (int i = 0; i < CAR_NUM; i++)
//		cout << gCar[i] << endl;
//
//	return 0;
//}