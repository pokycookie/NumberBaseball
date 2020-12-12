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

void setColor(unsigned short color, unsigned short background) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (background << 4));
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

void removeArea(int rowStart, int rowEnd, int columnStart, int columnEnd) {
	for (int column = columnStart; column <= columnEnd; column++) {
		for (int row = rowStart; row <= rowEnd; row++) {
			setCurser(row, column);
			printf(" ");
		}
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

// Print Large Number
void printLargeNumber(char character, int displayNumber) {
	switch (character){
	case '1':
		setColor(8, 7);
		setCurser(LNX(displayNumber) + 29, 9);
		printf("■");
		for (int i = 0; i < 26; i++) {
			setCurser(LNX(displayNumber) + 27, 10 + i);
			printf("■■■");
		}
		setCurser(LNX(displayNumber) + 29, 36);
		printf("■");
		break;
	case '2':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 27, 12 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 3, 24 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case '3':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 27, 12 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case '4':
		setColor(8, 7);
		for (int i = 0; i < 12; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("■■■");
		}
		break;
	case '5':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 3, 12 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case '6':
		setColor(8, 7);
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("■■■");
		}
		break;
	case '7':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("■■■");
		}
		break;
	case '8':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case '9':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 12; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case '0':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		break;
	case 'S':
		setColor(6, 15);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 3, 12 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		setCurser(LNX(displayNumber) + 3, 9); printf("  ");
		setCurser(LNX(displayNumber) + 31, 9); printf("  ");
		setCurser(LNX(displayNumber) + 9, 12); printf("■");
		setCurser(LNX(displayNumber) + 27, 12); printf("■■■");
		setCurser(LNX(displayNumber) + 29, 13); printf("■■");
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 31, 14 + i);
			printf("■");
		}
		setCurser(LNX(displayNumber) + 9, 20); printf("■");
		setCurser(LNX(displayNumber) + 31, 21); printf("  ");
		setCurser(LNX(displayNumber) + 3, 23); printf("  ");
		setCurser(LNX(displayNumber) + 25, 24); printf("■");
		setCurser(LNX(displayNumber) + 25, 33); printf("■");
		setCurser(LNX(displayNumber) + 31, 36); printf("  ");
		setCurser(LNX(displayNumber) + 3, 36); printf("  ");
		setCurser(LNX(displayNumber) + 3, 33); printf("■■■");
		setCurser(LNX(displayNumber) + 3, 32); printf("■■");
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 29 + i);
			printf("■");
		}
		break;
	case 'B':
		setColor(6, 15);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■■■■■■■■■■");
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("■■■■■■■■■■■■■■■");
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 21, 12 + i);
			printf("■■■");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("■■■");
		}
		break;
	case 'O':
		setColor(6, 15);
		// O
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 7, 9 + i);
			printf("■■■■■■■■■■■■■■■■");
			setCurser(LNX(1) + 7, 34 + i);
			printf("■■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 22; i++) {
			setCurser(LNX(1) + 7, 12 + i);
			printf("■■■");
			setCurser(LNX(1) + 33, 12 + i);
			printf("■■■");
		}
		// U
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(1) + 53, 9 + i);
			printf("■■■");
			setCurser(LNX(1) + 79, 9 + i);
			printf("■■■");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 59, 34 + i);
			printf("■■■■■■■■■■");
		}
		// T
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 99, 9 + i);
			printf("■■■■■■■■■■■■■■■■■");
		}
		for (int i = 0; i < 25; i++) {
			setCurser(LNX(1) + 113, 12 + i);
			printf("■■■");
		}
		break;
	default:
		break;
	}
	setColor(0, 15);
}
int LNX(int displayNumber) {
	switch (displayNumber) {
	case 1:
		return 31 - 1;
		break;
	case 2:
		return 66 - 1;
		break;
	case 3:
		return 101 - 1;
		break;
	case 4:
		return 136 - 1;
		break;
	default:
		return 0;
		break;
	}
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
	setCurser(80, 20);
	printf("숫자야구 도움말 들어갈 예정");
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

void printFreeBaseballSetting(void) {
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

void printSignUpModeForm(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶     ID:");
	setCurser(90, 25);
	printf("▷     PW:");
	setCurser(90, 26);
	printf("▷PW 확인:");
}

void printLoginModeForm(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶ID:");
	setCurser(90, 25);
	printf("▷PW:");
}