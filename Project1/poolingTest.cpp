#include <iostream>
#include "pool.h"
#include "connectionPool.h"

using namespace std;

int testPooling()
{
	//CoInitialize(NULL);

	// Ǯ ���� ���� Ǯ����
	CPool* mPool = new CConnectionPool(5);

	// ���ҽ� ��û
	CResource* pResource = mPool->aquire();

	// ���ҽ� ���....  

	// ���ҽ� ��ȯ
	mPool->release(pResource);

	delete mPool;

	//CoUninitialize();
	return 0;
}