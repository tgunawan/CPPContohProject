#include <windows.h>
#include <string>
#include <cstring>

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")

#define ID_INPUT 101
#define ID_BUTTON 102
#define ID_RESULT 103

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void TampilkanHasil(HWND hwnd) {
    char buffer[512];
    HWND hInput = GetDlgItem(hwnd, ID_INPUT);
    HWND hResult = GetDlgItem(hwnd, ID_RESULT);

    GetWindowText(hInput, buffer, 512);

    std::string hasil = "Hasil: ";
    hasil += (strlen(buffer) > 0)? buffer : "[kosong]";

    SetWindowText(hResult, hasil.c_str());
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char CLASS_NAME[] = "Win32InputApp";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0, CLASS_NAME, "Win32 Input Demo",
        WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME, // non-resize biar rapi
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 180,
        NULL, NULL, hInstance, NULL
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_CREATE: {
        // Font biar gak jelek default
        HFONT hFont = CreateFont(16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                                 DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                                 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
                                 VARIABLE_PITCH, TEXT("Segoe UI"));

        // Input textbox
        HWND hInput = CreateWindow("EDIT", "",
            WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
            20, 20, 340, 25, hwnd, (HMENU)ID_INPUT, NULL, NULL);
        SendMessage(hInput, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Tombol
        HWND hButton = CreateWindow("BUTTON", "Tampilkan",
            WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
            280, 55, 80, 28, hwnd, (HMENU)ID_BUTTON, NULL, NULL);
        SendMessage(hButton, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Label hasil, SS_LEFTNOWORDWRAP biar wrap otomatis
        HWND hResult = CreateWindow("STATIC", "Hasil: ",
            WS_CHILD | WS_VISIBLE | SS_LEFT | SS_EDITCONTROL,
            20, 90, 340, 40, hwnd, (HMENU)ID_RESULT, NULL, NULL);
        SendMessage(hResult, WM_SETFONT, (WPARAM)hFont, TRUE);
        break;
    }

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BUTTON) {
            TampilkanHasil(hwnd);
        }
        // Enter di textbox = klik tombol
        if (HIWORD(wParam) == EN_UPDATE && LOWORD(wParam) == ID_INPUT) {
            if (wParam == (EN_UPDATE << 16 | ID_INPUT)) {
                // cek kalau tombol Enter ditekan
            }
        }
        if (LOWORD(wParam) == ID_INPUT && HIWORD(wParam) == EN_MAXTEXT) {
            MessageBeep(MB_ICONEXCLAMATION);
        }
        break;

    case WM_KEYDOWN:
        // Enter di textbox
        if (wParam == VK_RETURN) {
            HWND focused = GetFocus();
            if (GetDlgCtrlID(focused) == ID_INPUT) {
                TampilkanHasil(hwnd);
                return 0;
            }
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}