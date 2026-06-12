#include <windows.h>
#include <string>

#define ID_INPUT 101
#define ID_BUTTON 102
#define ID_RESULT 103

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "Sample Window Class";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Aplikasi Input Teks",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
        NULL, NULL, hInstance, NULL
    );

    if (hwnd == NULL) return 0;

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    static HWND hInput, hButton, hResult;

    switch (uMsg) {
    case WM_CREATE:
        // Text input
        hInput = CreateWindow("EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            20, 20, 340, 25,
            hwnd, (HMENU)ID_INPUT, NULL, NULL);

        // Tombol
        hButton = CreateWindow("BUTTON", "Tampilkan",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            20, 60, 100, 30,
            hwnd, (HMENU)ID_BUTTON, NULL, NULL);

        // Label hasil
        hResult = CreateWindow("STATIC", "Hasil: ",
            WS_CHILD | WS_VISIBLE,
            20, 110, 340, 25,
            hwnd, (HMENU)ID_RESULT, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BUTTON) {
            char buffer[256];
            GetWindowText(hInput, buffer, 256); // ambil teks dari input

            std::string hasil = "Hasil: " + std::string(buffer);
            SetWindowText(hResult, hasil.c_str()); // tampilkan ke label
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}