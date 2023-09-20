#pragma once
#include <map>
#include"data.h"


class C_MGR
{
private:
	std::map<int, C_DATA*> m_mapData;

public:
	C_MGR() = default;
	bool insert(int nId, int nData);
	void printData();
	bool erase(int nId);
	void clear();


};