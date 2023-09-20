#include "mgr.h"

bool C_MGR::insert(int nId, int nData)
{
	/*auto insertResult = m_mapData.insert({ nId,nullptr });


	if (insertResult.second)
	{
		C_DATA* pData = new C_DATA();
		pData->setData(nData);
		insertResult.first->second = pData;
	}
	else
		return false;

	return true;*/

	auto iter = m_mapData.lower_bound(nId);

	if (iter != m_mapData.end() && iter->first == nId)
		return false;

	C_DATA* pData = new C_DATA();
	pData->setData(nData);
	m_mapData.insert(iter, { nId,pData });

	return true;

}

void C_MGR::printData()
{
	for (auto iter = m_mapData.begin();iter != m_mapData.end();iter++)
	{
		printf("key %d,value %d\n", iter->first, iter->second->getData());
	}
	printf("\n");
}

bool C_MGR::erase(int nId)
{
	auto iter = m_mapData.find(nId);

	if (iter == m_mapData.end())
		return false;

	delete iter->second;
	m_mapData.erase(iter);

	return true;
}

void C_MGR::clear()
{
}
