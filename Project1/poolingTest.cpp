#include <iostream>
#include "pool.h"
#include "connectionPool.h"

using namespace std;

int testPooling()
{
	//CoInitialize(NULL);

	// 풀 갯수 지정 풀생성
	CPool* mPool = new CConnectionPool(5);

	// 리소스 요청
	CResource* pResource = mPool->aquire();

	// 리소스 사용....  

	// 리소스 반환
	mPool->release(pResource);

	delete mPool;

	//CoUninitialize();
	return 0;
}