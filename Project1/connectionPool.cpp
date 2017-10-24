#include "connectionPool.h"
#include "connection.h"

// 생성자
CConnectionPool::CConnectionPool(unsigned int poolSize)
{
	// 풀 사이즈만큼 커넥션 생성
	for (int i = 0; i<poolSize; i++)
	{
		CResource* resource = new CConnection;
		m_pool.push_back(resource);
	}
}

// 소멸자
CConnectionPool::~CConnectionPool()
{
	// 모든 커넥션 메모리 해제
	for each (CResource* entry in m_pool)
		delete entry;

	m_pool.clear();
}

// 커넥션 얻기, 없으면 생성 반환
CResource* CConnectionPool::aquire()
{
	CResource * resource = NULL;

	if (NULL == (resource = findNewConnection()))
	{
		resource = new CConnection;
		m_pool.push_back(resource);
	}

	return resource;
}

// 커넥션 반환
void CConnectionPool::release(CResource* res)
{
	for each (CResource* entry in m_pool)
	{
		if (entry == res)
		{
			static_cast<CConnection*>(entry)->setInUse(true);
			break;
		}
	}
}

// 사용 가능 커넥션 찾기
CResource* CConnectionPool::findNewConnection()
{
	for each (CResource* entry in m_pool)
	{
		if (!static_cast<CConnection*>(entry)->getInUse())
		{
			static_cast<CConnection*>(entry)->setInUse(true);
			return entry;
		}
	}

	return NULL;
}