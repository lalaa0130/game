// WindowsProject3.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include"winAPI.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    C_WINAPI::createApi();
    C_WINAPI::getApi()->init(hInstance);
    C_WINAPI::getApi()->updateMsg();
    C_WINAPI::getApi()->releaseApi();


}