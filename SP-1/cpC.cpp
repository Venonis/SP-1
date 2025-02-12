#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "cpC.h"
using namespace std;

int cpC(const char* filr, const char* filw) {

    FILE* src = fopen(filr, "rb"); // Двоичный режим для чтения
    FILE* dst = fopen(filw, "wt"); // Текстовый режим для записи

    if (!src || !dst) {
        perror("Ошибка открытия файла");
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