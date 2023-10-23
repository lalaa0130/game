#include "winApi.h"

C_WINAPI* C_WINAPI::m_winApi = nullptr;

bool C_WINAPI::init(HINSTANCE hInstance)
{
    m_hInstance = hInstance;
    //UNREFERENCED_PARAMETER(hPrevInstance);
    //UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInstance;
    wcex.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(IDI_TEST));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = L"MY_WINDOW_CLASS";
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    RegisterClassExW(&wcex);

    m_hWnd = CreateWindowW(L"MY_WINDOW_CLASS", L"GAME", WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, m_hInstance, nullptr);

    if (!m_hWnd)
    {
        return FALSE;
    }

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);

    m_cDx.InitDevice(m_hWnd);

    return true;

}

void C_WINAPI::updateMsg()
{
    MSG msg = { 0 };
    while (WM_QUIT != msg.message)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            m_cDx.Render();
        }
    }
    m_cDx.CleanupDevice();
}

void C_WINAPI::createApi()
{
    if (!m_winApi)
    {
        m_winApi = new C_WINAPI{};
    }
}

C_WINAPI* C_WINAPI::getApi()
{
    return m_winApi;
}

void C_WINAPI::release()
{
    if (m_winApi)
    {
        delete m_winApi;
        m_winApi = nullptr;
    }
}

LRESULT C_WINAPI::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    return m_winApi->myProc(hWnd, message, wParam, lParam);
       
}

LRESULT C_WINAPI::myProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
