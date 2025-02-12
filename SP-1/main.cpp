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
	const char* fileread = "t.txt", * filewrite = "tt.txt";

	printf("1 - cpC\n2 - cpW\n3 - cpCF\n> ");
	scanf("%d", &i);

	if(i == 1)
		cpC(fileread, filewrite);
	else if (i == 2) {
		LPWSTR filer = CharToLPWSTR(fileread);
		LPWSTR filew = CharToLPWSTR(filewrite);
		cpW(filer, filew);
	}
	else if (i == 3) {
		LPWSTR filer = CharToLPWSTR(fileread);
		LPWSTR filew = CharToLPWSTR(filewrite);
		cpCF(filer, filew);
	}
	else {
		printf("Wrong input.");
		main();
	}
}

LPWSTR CharToLPWSTR(const char* text) {
	wchar_t wtext[20];
	mbstowcs(wtext, text, strlen(text) + 1);
	LPWSTR ptr = wtext;
	return ptr;
}