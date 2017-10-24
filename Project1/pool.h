#pragma once

class CResource;

class CPool
{
public:
	virtual CResource* aquire() = 0;
	virtual void release(CResource* res) = 0;
};