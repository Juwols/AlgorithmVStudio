#include <iostream>
#include "connection.h"
#include <time.h>

CConnection::CConnection() : m_currentlyUsed(false)
{
	// ����
	//m_connection.CreateInstance(__uuidof(Connection));
	//m_connection->CursorLocation = adUseServer;
	//m_connection->Open(L"���� ���ι��̴� ����", L"", L"", adConnectUnspecified);
}

CConnection::~CConnection()
{
	//if (m_connection)
	//{
	//	m_connection->Close();
	//	m_connection = NULL;
	//}
}

void* CConnection::getConnection()
{
	//return m_connection;
	return NULL;
}

void CConnection::setInUse(bool value)
{
	// ��� ��¥ �ð�����(Leaseing Pattern �̿� ����)
	if (value)
	{
		time_t seconds = time(NULL);
		//struct tm* timeinfo = localtime(&seconds);
		//mlastUsage.ticks = seconds;
		//mlastUsage.hour = timeinfo->tm_hour;
		//mlastUsage.minutes = timeinfo->tm_min;
		//mlastUsage.seconds = timeinfo->tm_sec;
		//mlastUsage.month = timeinfo->tm_mon;
		//mlastUsage.year = timeinfo->tm_year;
		//mlastUsage.day = timeinfo->tm_mday;
	}

	m_currentlyUsed = value;
}

bool CConnection::getInUse()
{
	return m_currentlyUsed;
}