#include <windows.h>
#include <stdio.h>
#include "cpW.h"

int cpW(LPWSTR filr, LPWSTR filw) {

    HANDLE hSrc = CreateFile(
        filr,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_SEQUENTIAL_SCAN,
        NULL
    );

    if (hSrc == INVALID_HANDLE_VALUE) {
        printf("������ �������� ��������� �����\n");
        return 1;
    }

    HANDLE hDst = CreateFile(
        filw,
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hDst == INVALID_HANDLE_VALUE) {
        CloseHandle(hSrc);
        printf("������ �������� �������� �����\n");
        return 1;
    }

    char buffer[4096];
    DWORD bytesRead, bytesWritten;

    while (ReadFile(hSrc, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) {
        WriteFile(hDst, buffer, bytesRead, &bytesWritten, NULL);
        if (bytesWritten != bytesRead) {
            printf("������ ������\n");
            break;
        }
    }

    CloseHandle(hSrc);
    CloseHandle(hDst);
    return 0;
}