#pragma once

#include "resource.h"

typedef struct
{
	long ticks;
	int hour;
	int minutes;
	int seconds;
	int month;
	int day;
	int year;
} DATETIME;

class CConnection : public CResource
{
public:
	CConnection();
	virtual ~CConnection();

public:
	void* getConnection() override;
	void setInUse(bool value);
	bool getInUse();

private:
	bool m_currentlyUsed;
	DATETIME mlastUsage;
	//_ConnectionPtr m_connection;
};