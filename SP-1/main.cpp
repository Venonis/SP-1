#include <iostream>
#include <string>
#include <Windows.h>

#include "cpC.h"
#include "cpW.h"
#include "cpCF.h"

using namespace std;

LPWSTR CharToLPWSTR(const char* text);

int main() {
	setlocale(LC_ALL, "ru");
	int i;
	const char* fileread = "100m.txt", * filewrite = "copy.txt";

	printf("1 - cpC\n2 - cpW\n3 - cpCF\n> ");
	scanf("%d", &i);

	if (i == 1) {
		int starttime = GetTickCount64();
		cpC(fileread, filewrite);
		int exetime = GetTickCount64() - starttime;
		printf("\nexecution time: %d", exetime);
	}
	else if (i == 2) {
		LPWSTR filer = CharToLPWSTR(fileread);
		LPWSTR filew = CharToLPWSTR(filewrite);

		int starttime = GetTickCount64();
		cpW(filer, filew);
		int exetime = GetTickCount64() - starttime;
		printf("\nexecution time: %d", exetime);

		delete[] filer;
		delete[] filew;
	}
	else if (i == 3) {
		LPWSTR filer = CharToLPWSTR(fileread);
		LPWSTR filew = CharToLPWSTR(filewrite);

		int starttime = GetTickCount64();
		cpCF(filer, filew);
		int exetime = GetTickCount64() - starttime;
		printf("\nexecution time: %d", exetime);

		delete[] filer;
		delete[] filew;
	}
	else {
		printf("Wrong input.");
		main();
	}
}

LPWSTR CharToLPWSTR(const char* text) {
	int size = MultiByteToWideChar(CP_ACP, 0, text, -1, NULL, 0);
	wchar_t* wtext = new wchar_t[size];
	MultiByteToWideChar(CP_ACP, 0, text, -1, wtext, size);
	return wtext;
}