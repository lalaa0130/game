#include "bts.h"

C_BST::S_NODE** C_BST::FindNode(S_NODE** ppNode, int nData)
{
    if (!*ppNode || (*ppNode)->nData == nData)
        return ppNode;

    if ((*ppNode)->nData > nData)
    {
        return FindNode(&(*ppNode)->pL, nData);
    }
    if ((*ppNode)->nData < nData)
    {
        return FindNode(&(*ppNode)->pR, nData);
    }

}

void C_BST::FindMaxNode(S_NODE** ppNode, S_NODE*** pppMaxNode)
{
    if (!(*ppNode)->pR)
    {
        *pppMaxNode = ppNode;
        return;
    }
    FindMaxNode(&(*ppNode)->pR, pppMaxNode);
}


bool C_BST::Add(int nData)
{
    S_NODE** ppNode = FindNode(&m_pRoot, nData);

    if (*ppNode)
        return false;

    *ppNode = createNode(nData);

    return true;
}

bool C_BST::Erase(int nData)
{
    S_NODE** ppNode = FindNode(&m_pRoot, nData);
    if (!*ppNode)
        return false;

    if ((*ppNode)->pL && (*ppNode)->pR)
    {
        S_NODE** ppMaxNode = &(*ppNode)->pL;
        FindMaxNode(&(*ppNode)->pL, &ppMaxNode);

        (*ppNode)->nData = (*ppMaxNode)->nData;
        ppNode = ppMaxNode;
    }

    S_NODE* pDel = *ppNode;
    *ppNode = pDel->pL;
    if (!*ppNode)
        * ppNode= pDel->pR;
    
    delete pDel;

    return true;
}

bool C_BST::Find(int nData)
{
    S_NODE** ppNode = FindNode(&m_pRoot, nData);
    if (*ppNode)
        return true;

    return false;
}

C_BST::S_NODE* C_BST::createNode(int nData)
{
    S_NODE* pNode = new S_NODE{};

    pNode->nData = nData;
    pNode->pL = nullptr;
    pNode->pR = nullptr;

    return pNode;
}

void C_BST::printNode(S_NODE* pNode)
{
    if (!pNode)
        return;

    printNode(pNode->pL);
    printf("%d ", pNode->nData);
    printNode(pNode->pR);
}
void C_BST::Print()
{
    printNode(m_pRoot);
    printf("\n");
}
