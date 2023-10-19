#include"winAPI.h"
#include"resource.h"

C_WINAPI* C_WINAPI::m_pApi = nullptr;

void C_WINAPI::createApi()
{
    if (!m_pApi)
        m_pApi = new C_WINAPI{};
}

C_WINAPI* C_WINAPI::getApi()
{
    return m_pApi;
}

void C_WINAPI::releaseApi()
{
    if (m_pApi)
    {
        delete m_pApi;
        m_pApi = nullptr;
    }
}

bool C_WINAPI::init(HINSTANCE hInstance)
{
    registerMsgFunc();


    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT3));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = L"MY_WINDOW_CLASS";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    HWND hWnd = CreateWindowW(L"MY_WINDOW_CLASS", L"WIN", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, SW_SHOWDEFAULT);
    UpdateWindow(hWnd);

	return false;
}

void C_WINAPI::updateMsg()
{
    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

LRESULT CALLBACK C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return m_pApi->myProc(hWnd, message, wParam, lParam);
}

LRESULT C_WINAPI::myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    if (message >= WM_USER ||!m_arrMsgFunc[message] )
        return DefWindowProc(hWnd, message, wParam, lParam);
    
    return (this->*m_arrMsgFunc[message])(hWnd, wParam, lParam);
}

void C_WINAPI::registerMsgFunc()
{
    m_arrMsgFunc[WM_PAINT] = &C_WINAPI::OnPaint;
    m_arrMsgFunc[WM_DESTROY] = &C_WINAPI::OnDestroy;
    m_arrMsgFunc[WM_KEYDOWN] = &C_WINAPI::OnKeyDown;
}


LRESULT C_WINAPI::OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
    EndPaint(hWnd, &ps);

    return 0;
}

LRESULT C_WINAPI::OnDestroy(HWND hWnd,WPARAM wParam, LPARAM lParam)
{
    PostQuitMessage(0);
    return 0;
}

LRESULT C_WINAPI::OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
    if (wParam == VK_ESCAPE)
        DestroyWindow(hWnd);

    return 0;
}

