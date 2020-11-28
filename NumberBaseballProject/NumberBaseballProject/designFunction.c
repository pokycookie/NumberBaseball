#include <stdio.h>
#include <Windows.h>

void initialDesign(void) {
	system("title Number Baseball");
	system("mode con: cols=200 lines=50");
	system("color F0");
}

void setCurser(short x, short y) {
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}