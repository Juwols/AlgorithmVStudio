#include "connectionPool.h"
#include "connection.h"

// ������
CConnectionPool::CConnectionPool(unsigned int poolSize)
{
	// Ǯ �����ŭ Ŀ�ؼ� ����
	for (int i = 0; i<poolSize; i++)
	{
		CResource* resource = new CConnection;
		m_pool.push_back(resource);
	}
}

// �Ҹ���
CConnectionPool::~CConnectionPool()
{
	// ��� Ŀ�ؼ� �޸� ����
	for each (CResource* entry in m_pool)
		delete entry;

	m_pool.clear();
}

// Ŀ�ؼ� ���, ������ ���� ��ȯ
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

// Ŀ�ؼ� ��ȯ
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

// ��� ���� Ŀ�ؼ� ã��
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