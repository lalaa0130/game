// template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void pibo(int nNumber1, int* pResult);

int main()
{
	int nResult{};
	pibo(7, &nResult);
	printf("%d\n", nResult);
}

void pibo(int nNumber1, int* pResult)
{
	if (nNumber1 <= 2)
	{
		*pResult = 1;
		return;
	}
	int pResult1{};
	int pResult2{};

	pibo(nNumber1 - 1, &pResult1);
	pibo(nNumber1 - 2, &pResult2);
	*pResult = pResult1 + pResult2;

}
