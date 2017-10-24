#pragma once
#include "pool.h"
#include "connectionPool.h"
#include <list>

using namespace std;

class CConnectionPool : public CPool
{
public:
	CConnectionPool(unsigned int poolSize);
	virtual ~CConnectionPool();

public:
	CResource* aquire();
	void release(CResource* res);

protected:
	CResource* findNewConnection();

private:
	list<CResource*> m_pool;
};