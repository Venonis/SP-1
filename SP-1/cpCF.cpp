#include <windows.h>
#include <stdio.h>
#include <string>
#include "cpCF.h"

using namespace std;

int cpCF(LPWSTR filr, LPWSTR filw) {

    if (!CopyFile(filr, filw, FALSE)) {
        printf("Ошибка копирования: %d\n", GetLastError());
        return 1;
    }

    return 0;
}