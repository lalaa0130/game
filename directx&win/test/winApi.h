#pragma once
#include <Windows.h>
#include"Resource.h"
#include  "directx.h"

class C_WINAPI
{
private:
	static C_WINAPI* m_winApi;
	C_DIRETCX m_cDx;


private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;


private:
	C_WINAPI() = default;


    static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    LRESULT myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


public:
	bool init(HINSTANCE hInstance);
	void updateMsg();
	
public:
	static void createApi();
	static C_WINAPI* getApi();
	static void release();


};