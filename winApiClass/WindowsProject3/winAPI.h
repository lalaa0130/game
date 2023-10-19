#pragma once

#include<Windows.h>

class C_WINAPI
{

private:
	HINSTANCE	 m_hInstance;
	HWND		 m_hWnd;

	int			 m_nData;


	static		 C_WINAPI* m_pApi;

	LRESULT		 (C_WINAPI::*m_arrMsgFunc[WM_USER])(HWND, WPARAM, LPARAM);

private:
	C_WINAPI() = default;

	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void registerMsgFunc();

private:
	LRESULT OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam);
	LRESULT OnDestroy(HWND hWnd,WPARAM wParam, LPARAM lParam);
	LRESULT OnKeyDown(HWND hWnd,WPARAM wParam, LPARAM lParam);




public:

	static void createApi();
	static C_WINAPI* getApi();
	static void releaseApi();


	bool init(HINSTANCE hInstance);
	void updateMsg();



};
