#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "define.h"

void initialDesign(void) {
	system("title Number Baseball");
	system("mode con: cols=200 lines=50");
	system("color F0");
}

void setCurser(short x, short y) {
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void cursorView(char show)
{
	// 0: hide cursor, 1: show cursor
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void removeOneLine(int line) {
	for (int i = 0; i < 200; i++) {
		setCurser(i, line);
		printf(" ");
	}
}

int arrowControl(void) {
	cursorView(0);
	int temp = _getch();
	if (temp == 0 || temp == 0xE0) {
		temp = _getch();
		switch (temp) {
		case LEFT:
			return LEFT;
			break;
		case RIGHT:
			return RIGHT;
			break;
		case UP:
			return UP;
			break;
		case DOWN:
			return DOWN;
			break;
		default:
			break;
		}
	}
	else if (temp == ENTER || temp == SPACE) {
		return 0; //Enter & Spacebar
	}
}

int selectColumnMenu(int x, int y, int count) {
	int currentCurser = 1;

	while (1) {
		int temp = arrowControl();
		if (temp == UP && currentCurser > 1) {
			currentCurser--;
		}
		else if (temp == DOWN && currentCurser < count) {
			currentCurser++;
		}
		else if (temp == 0) {
			break;
		}
		else {
			continue;
		}

		for (int i = 0; i < count; i++) {
			setCurser(x, y + i);
			printf("▷");
		}
		setCurser(x, y + currentCurser - 1);
		printf("▶");
	}
	return currentCurser;
}

// Print Select Menu

void printLogin(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶로그인");
	setCurser(90, 25);
	printf("▷회원가입");
	setCurser(90, 26);
	printf("▷비로그인");
	setCurser(90, 27);
	printf("▷Exit");
}

void printMainMenu(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶Game Start");
	setCurser(90, 25);
	printf("▷Help");
	setCurser(90, 26);
	printf("▷Back");
}

void printMode(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶Single Mode");
	setCurser(90, 25);
	printf("▷Multi Mode");
	setCurser(90, 26);
	printf("▷A.I Mode");
	setCurser(90, 27);
	printf("▷Back");
}

void printHelp(void) {
	system("cls");
	setCurser(70, 20);
	printf("숫자야구 인터넷에서 찾아보고 오세요. 귀찮습니다.");
	setCurser(90, 24);
	printf("▶Back");
}

void printBaseballLength(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶Easy");
	setCurser(90, 25);
	printf("▷Normal");
	setCurser(90, 26);
	printf("▷Hard");
	setCurser(90, 27);
	printf("▷사용자지정");
}

void printFreeBaseballLength(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶Set Baseball Length");
	setCurser(90, 25);
	printf("▷Back");
}

void printPracticeModeForm(void) {
	for (int i = 0; i < 200; i++) {
		setCurser(i, 5);
		printf("-");
		setCurser(i, 40);
		printf("-");
	}
	for (int i = 6; i < 40; i++) {
		setCurser(30, i);
		printf("|");
		setCurser(170, i);
		printf("|");
	}
}