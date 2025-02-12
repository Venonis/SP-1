#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpC.h"
using namespace std;

int cpC(const char* filr, const char* filw) {

    FILE* src = fopen(filr, "rb"); // �������� ����� ��� ������
    FILE* dst = fopen(filw, "wt"); // ��������� ����� ��� ������

    if (!src || !dst) {
        perror("������ �������� �����");
        return 1;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);
    return 0;
}