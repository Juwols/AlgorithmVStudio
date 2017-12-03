#include <iostream>
#include "RandomDataGenerator.h"

using namespace std;

static char gId[STRING_MAX_ROW][STRING_MAX_LEN];
static char gPasswd[STRING_MAX_ROW][STRING_MAX_LEN];
static int  gAction[INT_MAX_SIZE];
static int  gCar[INT_MAX_SIZE];

#define ID_MIN_LEN 5
#define ID_MAX_LEN 10
#define ID_NUM 20

#define PASSWD_LEN 20
#define PASSWD_NUM 3

#define ACTION_MIN 1000
#define ACTION_MAX 6000
#define ACTION_NUM 5

#define CAR_MIN 2010
#define CAR_MAX 2018
#define CAR_NUM 3

int connectionManagementTest() {
	randomVarLenStringGenerator(ID_MIN_LEN, ID_MAX_LEN, ID_NUM, gId);

	for (int i = 0; i < ID_NUM; i++)
		cout << gId[i] << endl;

	cout << "Next string generation...." << endl;

	randomFixedLenStringGenerator(PASSWD_LEN, PASSWD_NUM, gPasswd);

	for (int i = 0; i < PASSWD_NUM; i++)
		cout << gPasswd[i] << endl;

	randomIntGenerator(ACTION_MIN, ACTION_MAX, ACTION_NUM, gAction);

	for (int i = 0; i < ACTION_NUM; i++)
		cout << gAction[i] << endl;


	randomIntGenerator(CAR_MIN, CAR_MAX, CAR_NUM, gCar);

	for (int i = 0; i < CAR_NUM; i++)
		cout << gCar[i] << endl;


	return 0;
}