#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void initialDesign(void) {
	system("title Number Baseball");
	system("mode con: cols=180 lines=50");
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
	for (int i = 0; i < 180; i++) {
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
	cursorView(FALSE);
	int temp = _getch();
	if (temp == ENTER || temp == SPACE) {
		return 0; //Enter & Spacebar
	}
	else if (temp == 0 || temp == 0xE0) {
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
}

int selectColumnMenu(int x, int y, int count) {
	int currentCurser = 1;

	while (TRUE) {
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

int makeGameMenu() {
	removeArea(22, 158, 6, 39);
	cursorView(FALSE);
	
	// Print Form
	setCurser(61, 12);
	for (int i = 0; i < 59; i++) {
		printf("━");
	}
	setCurser(61, 33);
	for (int i = 0; i < 59; i++) {
		printf("━");
	}
	for (int i = 0; i < 20; i++) {
		setCurser(60, 13 + i);
		printf("┃");
		setCurser(120, 13 + i);
		printf("┃");
	}
	setCurser(60, 12); printf("┏");
	setCurser(120, 12); printf("┓");
	setCurser(60, 33); printf("┗");
	setCurser(120, 33); printf("┛");

	// Print Menu
	setCurser(MENUX + 5, 14);
	printf("▶계속하기");
	setCurser(MENUX + 5, 15);
	printf("▷포기하기");
	
	return selectColumnMenu(MENUX + 5, 14, 2);
}

// Print Large Number
void printLargeNumber(char character, int displayNumber) {
	cursorView(FALSE);
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
	cursorView(TRUE);
}
int LNX(int displayNumber) {
	switch (displayNumber) {
	case 1:
		return 22;
		break;
	case 2:
		return 55;
		break;
	case 3:
		return 90;
		break;
	case 4:
		return 123;
		break;
	default:
		return 0;
		break;
	}
}

// Print Logo
void printMainLogo(int x, int y) {
	setCurser(x, y + 0);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 1);
	printf("WWWWWWWWWWWWWWWWWW##::                                                                                                                                        ..##WWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 2);
	printf("WWWWWWWWWWWWWWWL      ");
	setColor(9, 15);
	printf("E####WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEL      ");
	setColor(0, 15);
	printf("tWWWWWWWWWWWWWWW");
	setCurser(x, y + 3);
	printf("WWWWWWWWWWWWW#    ");
	setColor(9, 15);
	printf(".WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            ");
	setColor(12, 15);
	printf("DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE:    ");
	setColor(0, 15);
	printf("#WWWWWWWWWWWWW");
	setCurser(x, y + 4);
	printf("WWWWWWWWWWWWWj    ");
	setColor(9, 15);
	printf("#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#          ");
	setColor(12, 15);
	printf(" DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE    ");
	setColor(0, 15);
	printf("iWWWWWWWWWWWWWWWW");
	setCurser(x, y + 5);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf(";KWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKL          ");
	setColor(12, 15);
	printf("KEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEj    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 6);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t          i#WWWWWWWWWWWWWWK          ");
	setColor(12, 15);
	printf(".EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 7);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                    #WWWWWWWWWW#          ");
	setColor(12, 15);
	printf("DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 8);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWG                        fWWWWWWWWWW#          ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 9);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                            WWWWWWWWWWWE,        ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 10);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                              #WWWWWWWWWW:        ");
	setColor(12, 15);
	printf("KDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 11);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                WWWWWWWWWWWW          ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 12);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                ,WWWWWWWWWWWW#        ");
	setColor(12, 15);
	printf("DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 13);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                  WWWWWWWWWWWWK#        ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 14);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t                                    WWWWWWWWWWWWWWWt      ");
	setColor(12, 15);
	printf(";DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 15);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                        WWWWWWWWWWWWWWWW        ");
	setColor(12, 15);
	printf("KEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 16);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWK,                                       WWWWWWWWWWWWWWWWW#         ");
	setColor(12, 15);
	printf("DEEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 17);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                              #WWWWWWWWWWWWWWWWWWWW#      ");
	setColor(12, 15);
	printf("EDEEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 18);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                              WWWWWWWWWWWWWWWWWWWWWWKG      ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 19);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                ########################      ");
	setColor(12, 15);
	printf(";KEEEEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 20);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKW                                                    ####          ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 21);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW##                                                              ");
	setColor(12, 15);
	printf(":EEEEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 22);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                ");
	setColor(12, 15);
	printf("jDEEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 23);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                  ");
	setColor(12, 15);
	printf("jEEEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 24);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                      ");
	setColor(12, 15);
	printf("DEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 25);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                                                                        ");
	setColor(12, 15);
	printf("EEEEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 26);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                            ");
	setColor(12, 15);
	printf("KEEEEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 27);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                ");
	setColor(12, 15);
	printf(".EEEEEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 28);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWW:    .WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWL                                                                                  ");
	setColor(12, 15);
	printf("jEEEEEEEDG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 29);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWi        ,WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      ");
	setColor(12, 15);
	printf("DEEEEEDG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 30);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                      ");
	setColor(12, 15);
	printf("tDEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 31);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWWE                                                                                        ");
	setColor(12, 15);
	printf("GEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 32);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWK        EWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW;                                                                                        ");
	setColor(12, 15);
	printf("iEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 33);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                          ");
	setColor(12, 15);
	printf("EEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 34);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        ");
	setColor(12, 15);
	printf(";DEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 35);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf("LWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        ");
	setColor(12, 15);
	printf("EEEEEEEG    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 36);
	printf("WWWWWWWWWWWW    ");
	setColor(9, 15);
	printf(";WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      ");
	setColor(12, 15);
	printf("EEEEEEEEEt    ");
	setColor(0, 15);
	printf("WWWWWWWWWWWW");
	setCurser(x, y + 37);
	printf("WWWWWWWWWWWWWt    ");
	setColor(9, 15);
	printf("#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW###D                                                              ");
	setColor(12, 15);
	printf("KEEEEEEEEEEEEEEEEEEEEEEE    ");
	setColor(0, 15);
	printf(";WWWWWWWWWWWWW");
	setCurser(x, y + 38);
	printf("WWWWWWWWWWWWW#      ");
	setColor(9, 15);
	printf("#WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                              ");
	setColor(12, 15);
	printf("KEEEEEEEEEEEEEEEEEEEEEE:    ");
	setColor(0, 15);
	printf("#WWWWWWWWWWWWW");
	setCurser(x, y + 39);
	printf("WWWWWWWWWWWWWWWL      ");
	setColor(9, 15);
	printf("G#######################################################                                                            ");
	setColor(12, 15);
	printf("WEEEEEEEEEEEEEEEEEEL      ");
	setColor(0, 15);
	printf("fWWWWWWWWWWWWWWW");
	setCurser(x, y + 40);
	printf("WWWWWWWWWWWWWWWWWj                                                                                                                                                iWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 41);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
}

// Print Select Menu
void printLogin(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("▶로그인");
	setCurser(MENUX, MENUY + 1);
	printf("▷회원가입");
	setCurser(MENUX, MENUY + 2);
	printf("▷비로그인");
	setCurser(MENUX, MENUY + 3);
	printf("▷도움말");
	setCurser(MENUX, MENUY + 4);
	printf("▷게임종료");
}

void printMode(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("▶게임시작");
	setCurser(MENUX, MENUY + 1);
	printf("▷기록보기");
	setCurser(MENUX, MENUY + 2);
	printf("▷도움말");
	setCurser(MENUX, MENUY + 3);
	printf("▷로그아웃");
}

// Large Select Menu

void printGameOption(int gameMode) {
	for (int i = 0; i < 165; i++) {
		setCurser(i + 7, 5);
		printf("─");
	}

	setCurser(7, 4);
	switch (gameMode) {
	case SINGLEMODE: printf("SINGLE MODE"); break;
	case MULTIMODE: printf("MULTI MODE"); break;
	case AIMODE: printf("AI MODE"); break;
	}
	setCurser(150, 4);
	printf("게임 옵션을 선택하세요");

	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 41; i++) {
			if (i > 4 && i < 37) {
				setCurser(GOX(n) + i, 13);
				printf("─");
				if (gameMode != AIMODE) {
					setCurser(GOX(n) + i, 17);
					printf("─");
				}
				else {
					setCurser(GOX(n) + i, 18);
					printf("─");
				}
			}
			setCurser(GOX(n) + i, 7);
			printf("─");
			setCurser(GOX(n) + i, 43);
			printf("─");
		}
		for (int i = 0; i < 37; i++) {
			setCurser(GOX(n), 7 + i);
			printf("│");
			setCurser(GOX(n) + 40, 7 + i);
			printf("│");
		}
		setCurser(GOX(n), 7); printf("┌");
		setCurser(GOX(n) + 40, 7); printf("┐");
		setCurser(GOX(n), 43); printf("└");
		setCurser(GOX(n) + 40, 43); printf("┘");
	}

	for (int i = 0; i < 23; i++) {
		setCurser(78 + i, 45);
		printf("─");
		setCurser(78 + i, 47);
		printf("─");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(78, 45 + i);
		printf("│");
		setCurser(100, 45 + i);
		printf("│");
	}
	setCurser(78, 45); printf("┌");
	setCurser(100, 45); printf("┐");
	setCurser(78, 47); printf("└");
	setCurser(100, 47); printf("┘");
	setCurser(88, 46); printf("BACK");

	setCurser(25, 11); printf("EASY");
	setCurser(66, 11); printf("NORMAL");
	setCurser(109, 11); printf("HARD");
	setCurser(148, 11); printf("사용자 지정");
	
	setCurser(20, 15); printf("숫자야구 3자리");
	setCurser(62, 15); printf("숫자야구 4자리");
	setCurser(104, 15); printf("숫자야구 5자리");
	setCurser(142, 15); printf("숫자야구 자릿수 자유");

	if (gameMode == AIMODE) {
		setCurser(20, 16); printf("인공지능 EASY");
		setCurser(62, 16); printf("인공지능 NORMAL");
		setCurser(104, 16); printf("인공지능 HARD");
		setCurser(146, 16); printf("인공지능 자유");

		setCurser(16, 20); printf("숫자야구 초급자용 입니다.");
		setCurser(8, 22); printf("숫자야구를 처음 접하는분께 추천합니다.");

		setCurser(58, 20); printf("숫자야구 중급자용 입니다.");
		setCurser(52, 22); printf("숫자야구에 익숙한분께 추천합니다.");

		setCurser(99, 20); printf("숫자야구 상급자용 입니다.");
		setCurser(96, 22); printf("숫자야구 고수에게 추천합니다.");

		setCurser(144, 20); printf("사용자 설정 입니다.");
		setCurser(138, 22); printf("숫자야구 자릿수와 인공지능을");
		setCurser(144, 23); printf("자유롭게 설정하세요");

		for (int i = 0; i < 32; i++) {
			setCurser(137 + i ,38);
			printf("─");
		}
	}
	else {
		setCurser(16, 19); printf("숫자야구 초급자용 입니다.");
		setCurser(8, 21); printf("숫자야구를 처음 접하는분께 추천합니다.");

		setCurser(58, 19); printf("숫자야구 중급자용 입니다.");
		setCurser(52, 21); printf("숫자야구에 익숙한분께 추천합니다.");

		setCurser(99, 19); printf("숫자야구 상급자용 입니다.");
		setCurser(96, 21); printf("숫자야구 고수에게 추천합니다.");

		setCurser(144, 19); printf("사용자 설정 입니다.");
		setCurser(134, 21); printf("숫자야구 자릿수를 자유롭게 설정하세요");

		for (int i = 0; i < 32; i++) {
			setCurser(137 + i, 38);
			printf("─");
		}
	}
}

int selectGameOption(void) {
	int currentCurser = 1;

	for (int i = 0; i < 41; i++) {
		setCurser(GOX(0) + i, 7);
		printf("━");
		setCurser(GOX(0) + i, 43);
		printf("━");
	}
	for (int i = 0; i < 37; i++) {
		setCurser(GOX(0), 7 + i);
		printf("┃");
		setCurser(GOX(0) + 40, 7 + i);
		printf("┃");
	}
	setCurser(GOX(0), 7); printf("┏");
	setCurser(GOX(0) + 40, 7); printf("┓");
	setCurser(GOX(0), 43); printf("┗");
	setCurser(GOX(0) + 40, 43); printf("┛");

	while (TRUE) {
		int temp = arrowControl();
		if (temp == LEFT && currentCurser > 1 && currentCurser != 5) {
			currentCurser--;
		}
		else if (temp == RIGHT && currentCurser < 4) {
			currentCurser++;
		}
		else if (temp == UP && currentCurser == 5) {
			currentCurser = 1;
		}
		else if (temp == DOWN) {
			currentCurser = 5;
		}
		else if (temp == 0) {
			break;
		}
		else {
			continue;
		}

		for (int n = 0; n < 4; n++) {
			for (int i = 0; i < 41; i++) {
				if (i > 4 && i < 37) {
					setCurser(GOX(n) + i, 13);
					printf("─");
				}
				setCurser(GOX(n) + i, 7);
				printf("─");
				setCurser(GOX(n) + i, 43);
				printf("─");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GOX(n), 7 + i);
				printf("│");
				setCurser(GOX(n) + 40, 7 + i);
				printf("│");
			}
			setCurser(GOX(n), 7); printf("┌");
			setCurser(GOX(n) + 40, 7); printf("┐");
			setCurser(GOX(n), 43); printf("└");
			setCurser(GOX(n) + 40, 43); printf("┘");
		}

		for (int i = 0; i < 23; i++) {
			setCurser(78 + i, 45);
			printf("─");
			setCurser(78 + i, 47);
			printf("─");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(78, 45 + i);
			printf("│");
			setCurser(100, 45 + i);
			printf("│");
		}
		setCurser(78, 45); printf("┌");
		setCurser(100, 45); printf("┐");
		setCurser(78, 47); printf("└");
		setCurser(100, 47); printf("┘");
		setCurser(88, 46); printf("BACK");

		if (currentCurser < 5) {
			for (int i = 0; i < 41; i++) {
				setCurser(GOX(currentCurser - 1) + i, 7);
				printf("━");
				setCurser(GOX(currentCurser - 1) + i, 43);
				printf("━");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GOX(currentCurser - 1), 7 + i);
				printf("┃");
				setCurser(GOX(currentCurser - 1) + 40, 7 + i);
				printf("┃");
			}
			setCurser(GOX(currentCurser - 1), 7); printf("┏");
			setCurser(GOX(currentCurser - 1) + 40, 7); printf("┓");
			setCurser(GOX(currentCurser - 1), 43); printf("┗");
			setCurser(GOX(currentCurser - 1) + 40, 43); printf("┛");
		}
		else {
			for (int i = 0; i < 23; i++) {
				setCurser(78 + i, 45);
				printf("━");
				setCurser(78 + i, 47);
				printf("━");
			}
			for (int i = 0; i < 3; i++) {
				setCurser(78, 45 + i);
				printf("┃");
				setCurser(100, 45 + i);
				printf("┃");
			}
			setCurser(78, 45); printf("┏");
			setCurser(100, 45); printf("┓");
			setCurser(78, 47); printf("┗");
			setCurser(100, 47); printf("┛");
			setCurser(88, 46); printf("BACK");
		}
	}
	return currentCurser;
}

int GOX(int displayNumber) {
	switch (displayNumber) {
	case 0: return 6; break;
	case 1: return 48; break;
	case 2: return 90; break;
	case 3: return 132; break;
	}
}

int selectAiDifficulty(int isGameOption) {
	int currentCurser = EASY;

	if (isGameOption) {
		setCurser(148, 42);
		printf("◁  EASY  ▶");

		while (1) {
			int temp = arrowControl();
			if (temp == LEFT && currentCurser > 1) {
				currentCurser--;
			}
			else if (temp == RIGHT && currentCurser < 3) {
				currentCurser++;
			}
			else if (temp == 0) {
				break;
			}
			removeArea(137, 169, 42, 42);
			switch (currentCurser) {
			case EASY: setCurser(148, 42); printf("◁  EASY  ▶"); break;
			case NORMAL: setCurser(148, 42); printf("◀ NORMAL ▶"); break;
			case HARD: setCurser(148, 42); printf("◀  HARD  ▷"); break;
			}
		}
	}
	else {
		setCurser(140, 42);
		printf("◁  EASY  ▶");

		while (1) {
			int temp = arrowControl();
			if (temp == LEFT && currentCurser > 1) {
				currentCurser--;
			}
			else if (temp == RIGHT && currentCurser < 3) {
				currentCurser++;
			}
			else if (temp == 0) {
				break;
			}
			removeArea(131, 164, 42, 42);
			switch (currentCurser) {
			case EASY: setCurser(140, 42); printf("◁  EASY  ▶"); break;
			case NORMAL: setCurser(140, 42); printf("◀ NORMAL ▶"); break;
			case HARD: setCurser(140, 42); printf("◀  HARD  ▷"); break;
			}
		}
	}
	return currentCurser;
}

// Large Game Mode

void printGameMode(void) {
	for (int i = 0; i < 149; i++) {
		setCurser(i + 16, 5);
		printf("─");
	}
	setCurser(144, 4);
	printf("게임 모드를 선택하세요");

	for (int n = 0; n < 3; n++) {
		for (int i = 0; i < 40; i++) {
			if (i > 4 && i < 37) {
				setCurser(GMX(n) + i, 13);
				printf("─");
				setCurser(GMX(n) + i, 17);
				printf("─");
			}
			setCurser(GMX(n) + i, 7);
			printf("─");
			setCurser(GMX(n) + i, 43);
			printf("─");
		}
		for (int i = 0; i < 37; i++) {
			setCurser(GMX(n), 7 + i);
			printf("│");
			setCurser(GMX(n) + 40, 7 + i);
			printf("│");
		}
		setCurser(GMX(n), 7); printf("┌");
		setCurser(GMX(n) + 40, 7); printf("┐");
		setCurser(GMX(n), 43); printf("└");
		setCurser(GMX(n) + 40, 43); printf("┘");
	}
	for (int i = 0; i < 23; i++) {
		setCurser(78 + i, 45);
		printf("─");
		setCurser(78 + i, 47);
		printf("─");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(78, 45 + i);
		printf("│");
		setCurser(100, 45 + i);
		printf("│");
	}
	setCurser(78, 45); printf("┌");
	setCurser(100, 45); printf("┐");
	setCurser(78, 47); printf("└");
	setCurser(100, 47); printf("┘");
	setCurser(88, 46); printf("BACK");

	setCurser(GMX(0) + 16, 11); printf("SINGLE MODE");
	setCurser(GMX(1) + 16, 11); printf("MULTI MODE");
	setCurser(GMX(2) + 18, 11); printf("AI MODE");

	setCurser(GMX(0) + 8, 15); printf("혼자서 연습할 수 있는 모드");
	setCurser(GMX(1) + 8, 15); printf("친구와 대전할 수 있는 모드");
	setCurser(GMX(2) + 10, 15); printf("AI와 대전할 수 있는 모드");

	setCurser(GMX(0) + 4, 19); printf("컴퓨터가 랜덤으로 만드는 숫자조합을");
	setCurser(GMX(0) + 8, 20); printf("맞추면서 실력을 늘려보세요.");

	setCurser(GMX(1) + 10, 19); printf("친구와 함께 대전하면서");
	setCurser(GMX(1) + 8, 20); printf("서로의 실력을 경쟁해보세요.");

	setCurser(GMX(2) + 14, 19); printf("AI와 대전하면서");
	setCurser(GMX(2) + 8, 20); printf("자신의 한계에 도전해보세요.");
	setCurser(GMX(2) + 9, 22); printf("※난이도가 매우 높습니다.");
}

int selectGameMode(void) {
	int currentCurser = 1;

	for (int i = 0; i < 40; i++) {
		setCurser(GMX(0) + i, 7);
		printf("━");
		setCurser(GMX(0) + i, 43);
		printf("━");
	}
	for (int i = 0; i < 37; i++) {
		setCurser(GMX(0), 7 + i);
		printf("┃");
		setCurser(GMX(0) + 40, 7 + i);
		printf("┃");
	}
	setCurser(GMX(0), 7); printf("┏");
	setCurser(GMX(0) + 40, 7); printf("┓");
	setCurser(GMX(0), 43); printf("┗");
	setCurser(GMX(0) + 40, 43); printf("┛");

	while (TRUE) {
		int temp = arrowControl();
		if (temp == LEFT && currentCurser > 1 && currentCurser != 5) {
			currentCurser--;
		}
		else if (temp == RIGHT && currentCurser < 3) {
			currentCurser++;
		}
		else if (temp == UP && currentCurser == 4) {
			currentCurser = 1;
		}
		else if (temp == DOWN) {
			currentCurser = 4;
		}
		else if (temp == 0) {
			break;
		}
		else {
			continue;
		}

		for (int n = 0; n < 3; n++) {
			for (int i = 0; i < 40; i++) {
				if (i > 4 && i < 37) {
					setCurser(GMX(n) + i, 13);
					printf("─");
					setCurser(GMX(n) + i, 17);
					printf("─");
				}
				setCurser(GMX(n) + i, 7);
				printf("─");
				setCurser(GMX(n) + i, 43);
				printf("─");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GMX(n), 7 + i);
				printf("│");
				setCurser(GMX(n) + 40, 7 + i);
				printf("│");
			}
			setCurser(GMX(n), 7); printf("┌");
			setCurser(GMX(n) + 40, 7); printf("┐");
			setCurser(GMX(n), 43); printf("└");
			setCurser(GMX(n) + 40, 43); printf("┘");
		}
		for (int i = 0; i < 23; i++) {
			setCurser(78 + i, 45);
			printf("─");
			setCurser(78 + i, 47);
			printf("─");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(78, 45 + i);
			printf("│");
			setCurser(100, 45 + i);
			printf("│");
		}
		setCurser(78, 45); printf("┌");
		setCurser(100, 45); printf("┐");
		setCurser(78, 47); printf("└");
		setCurser(100, 47); printf("┘");
		setCurser(88, 46); printf("BACK");

		if (currentCurser < 4) {
			for (int i = 0; i < 40; i++) {
				setCurser(GMX(currentCurser - 1) + i, 7);
				printf("━");
				setCurser(GMX(currentCurser - 1) + i, 43);
				printf("━");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GMX(currentCurser - 1), 7 + i);
				printf("┃");
				setCurser(GMX(currentCurser - 1) + 40, 7 + i);
				printf("┃");
			}
			setCurser(GMX(currentCurser - 1), 7); printf("┏");
			setCurser(GMX(currentCurser - 1) + 40, 7); printf("┓");
			setCurser(GMX(currentCurser - 1), 43); printf("┗");
			setCurser(GMX(currentCurser - 1) + 40, 43); printf("┛");
		}
		else {
			for (int i = 0; i < 23; i++) {
				setCurser(78 + i, 45);
				printf("━");
				setCurser(78 + i, 47);
				printf("━");
			}
			for (int i = 0; i < 3; i++) {
				setCurser(78, 45 + i);
				printf("┃");
				setCurser(100, 45 + i);
				printf("┃");
			}
			setCurser(78, 45); printf("┏");
			setCurser(100, 45); printf("┓");
			setCurser(78, 47); printf("┗");
			setCurser(100, 47); printf("┛");
			setCurser(88, 46); printf("BACK");
		}
	}
	return currentCurser;
}

int GMX(int displayNumber) {
	switch (displayNumber) {
	case 0: return 15;  break;
	case 1: return 70; break;
	case 2: return 125; break;
	}
}

// Large Record Menu

void printRecordMode(void) {
	for (int i = 0; i < 149; i++) {
		setCurser(i + 16, 5);
		printf("─");
	}
	setCurser(130, 4);
	printf("기록을 확인할 게임 모드를 선택하세요");

	for (int n = 0; n < 3; n++) {
		for (int i = 0; i < 40; i++) {
			if (i > 4 && i < 37) {
				setCurser(GMX(n) + i, 13);
				printf("─");
				setCurser(GMX(n) + i, 17);
				printf("─");
			}
			setCurser(GMX(n) + i, 7);
			printf("─");
			setCurser(GMX(n) + i, 43);
			printf("─");
		}
		for (int i = 0; i < 37; i++) {
			setCurser(GMX(n), 7 + i);
			printf("│");
			setCurser(GMX(n) + 40, 7 + i);
			printf("│");
		}
		setCurser(GMX(n), 7); printf("┌");
		setCurser(GMX(n) + 40, 7); printf("┐");
		setCurser(GMX(n), 43); printf("└");
		setCurser(GMX(n) + 40, 43); printf("┘");
	}
	for (int i = 0; i < 23; i++) {
		setCurser(78 + i, 45);
		printf("─");
		setCurser(78 + i, 47);
		printf("─");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(78, 45 + i);
		printf("│");
		setCurser(100, 45 + i);
		printf("│");
	}
	setCurser(78, 45); printf("┌");
	setCurser(100, 45); printf("┐");
	setCurser(78, 47); printf("└");
	setCurser(100, 47); printf("┘");
	setCurser(88, 46); printf("BACK");

	setCurser(GMX(0) + 16, 11); printf("SINGLE MODE");
	setCurser(GMX(1) + 16, 11); printf("MULTI MODE");
	setCurser(GMX(2) + 18, 11); printf("AI MODE");

	setCurser(GMX(0) + 11, 15); printf("SINGLE MODE 기록 확인");
	setCurser(GMX(1) + 12, 15); printf("MULTI MODE 기록 확인");
	setCurser(GMX(2) + 13, 15); printf("AI MODE 기록 확인");
}


// Game Result
void printGameResult(struct rank rank, char* player1, int* baseballNumber1, char* player2, int* baseballNumber2, char* winner, int isLogin) {
	removeArea(22, 158, 6, 39);
	cursorView(FALSE);

	// Player1 (LEFT)
	setCurser(22, 6);
	printf("%s", player1);
	setCurser(22, 7);
	for (int i = 0; i < 136; i++) {
		printf("─");
	}
	setCurser(22, 8);
	for (int i = 0; i < rank.baseballLength; i++) {
		printf("%d", baseballNumber1[i]);
	}

	if (rank.mode != SINGLEMODE) {
		// Player2 (RIGHT)
		setCurser(22, 12);
		printf("%s", isLogin ? player2 : "NON-LOGIN PLAYER");
		setCurser(22, 13);
		for (int i = 0; i < 136; i++) {
			printf("─");
		}
		setCurser(22, 14);
		for (int i = 0; i < rank.baseballLength; i++) {
			printf("%d", baseballNumber2[i]);
		}
	}

	// Result
	setCurser(22, 31);
	printf("RESULT");
	setCurser(22, 32);
	for (int i = 0; i < 136; i++) {
		printf("─");
	}
	setCurser(22, 33);
	switch (rank.mode) {
	case SINGLEMODE: printf("게임모드: SINGLE MODE %d자리", rank.baseballLength); break;
	case MULTIMODE: printf("게임모드: SINGLE MODE %d자리", rank.baseballLength); break;
	case AIMODE:
		switch (rank.aiDifficulty) {
		case EASY: printf("게임모드: AI MODE - EASY %d자리", rank.baseballLength); break;
		case NORMAL: printf("게임모드: AI MODE - NORMAL %d자리", rank.baseballLength); break;
		case HARD: printf("게임모드: AI MODE - HARD %d자리", rank.baseballLength); break;
		case EXTREAM: printf("게임모드: AI MODE - EXTREAM %d자리", rank.baseballLength); break;
		}
	}
	setCurser(22, 34);
	printf("플레이어: %s VS %s", player1, isLogin ? player2 : "NON-LOGIN PLAYER");

	setCurser(22, 36);
	printf("게임승자: %s", !isLogin && !strcmp(winner, "NULL") ? "NON-LOGIN PLAYER" : winner);
	setCurser(22, 37);
	printf("걸린시간: %d분 %d초", rank.recordTime.minute, rank.recordTime.second);
	setCurser(22, 38);
	printf("시도횟수: %d번", rank.tryCount);
	setCurser(22, 39);
	printf("게임날짜: %d년 %d월 %d일, %d시 %d분", rank.realTime.tm_year + 1900, rank.realTime.tm_mon + 1, rank.realTime.tm_mday, rank.realTime.tm_hour, rank.realTime.tm_min);
}

void printPracticeModeForm(int mode, int aiDifficulty ,int baseballLength) {
	// Basic Form
	for (int i = 0; i < 180; i++) {
		if (i < 20 || i > 170) {
			setCurser(i, 3);
			printf("─");
		}
		else {
			setCurser(i, 4);
			printf("─");
		}
		if (i < 20 || i > 159) {
			setCurser(i, 7);
			printf("─");
			setCurser(i, 38);
			printf("─");
		}
		setCurser(i, 5);
		printf("─");
		setCurser(i, 40);
		printf("─");
	}
	for (int i = 6; i < 40; i++) {
		setCurser(20, i);
		printf("│");
		setCurser(159, i);
		printf("│");
	}
	setCurser(20, 5); printf("┌");
	setCurser(159, 5); printf("┐");
	setCurser(20, 40); printf("└");
	setCurser(159, 40); printf("┘");

	setCurser(20, 3); printf("┐");
	setCurser(20, 4); printf("└");
	setCurser(170, 3); printf("┌");
	setCurser(170, 4); printf("┘");
	
	// Game's Mode
	setCurser(1, 4);
	if (!aiDifficulty) {
		switch (mode) {
		case SINGLEMODE: printf("SINGLE MODE"); break;
		case MULTIMODE: printf("MULTI MODE"); break;
		}
	}
	else {
		switch (aiDifficulty) {
		case EASY: printf("AI MODE - EASY"); break;
		case NORMAL: printf("AI MODE - NORMAL"); break;
		case HARD: printf("AI MODE - HARD"); break;
		case EXTREAM: printf("AI MODE - EXTREAM"); break;
		}
	}

	// Game's Baseball Length
	setCurser(173, 4);
	printf("%2d자리", baseballLength);
}

void printSignUpModeForm(void) {
	setCurser(MENUX, MENUY);
	printf("▶     ID:");
	setCurser(MENUX, MENUY + 1);
	printf("▷     PW:");
	setCurser(MENUX, MENUY + 2);
	printf("▷PW 확인:");
}

void printLoginModeForm(void) {
	setCurser(MENUX, MENUY);
	printf("▶ID:");
	setCurser(MENUX, MENUY + 1);
	printf("▷PW:");
}

void printOkButton(int x, int y) {
	setCurser(x, y);
	for (int i = 0; i < 23; i++) {
		setCurser(x + i, y);
		printf("━");
		setCurser(x + i, y + 2);
		printf("━");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(x, y + i);
		printf("┃");
		setCurser(x + 22, y + i);
		printf("┃");
	}
	setCurser(x, y); printf("┏");
	setCurser(x + 22, y); printf("┓");
	setCurser(x, y + 2); printf("┗");
	setCurser(x + 22, y + 2); printf("┛");
	setCurser(x + 11, y + 1); printf("OK");
}

void printRankBoardForm(int mode, int length, int aiDifficulty) {

	setCurser(87, 3);
	printf("RANKING");
	setCurser(20, 6);
	for (int i = 0; i < 140; i++) {
		printf("─");
	}
	if (mode != MULTIMODE) {
		setCurser(22, 7); printf("RANK");
		setCurser(30, 7); printf("ID");
		setCurser(44, 7); printf("TRY COUNT");
		setCurser(60, 7); printf("RECORD TIME");
		setCurser(140, 7); printf("DATE");
	}
	else {
		setCurser(22, 7); printf("ID");
		setCurser(54, 7); printf("WINNER");
		setCurser(70, 7); printf("RECORD TIME");
		setCurser(140, 7); printf("DATE");
	}

	setCurser(20, 8);
	for (int i = 0; i < 140; i++) {
		printf("─");
	}
	setCurser(20, 31);
	for (int i = 0; i < 140; i++) {
		printf("─");
	}

	char MODE[10], DIFFICULTY[10];
	switch (mode) {
	case SINGLEMODE: strcpy_s(MODE, sizeof(MODE), "SINGLE"); break;
	case MULTIMODE: strcpy_s(MODE, sizeof(MODE), "MULTY"); break;
	case AIMODE: strcpy_s(MODE, sizeof(MODE), "AI"); break;
	}
	switch (aiDifficulty) {
	case FALSE: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "NULL"); break;
	case EASY: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "EASY"); break;
	case NORMAL: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "NORMAL"); break;
	case HARD: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "HARD"); break;
	case EXTREAM: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "EXTREAM"); break;
	}

	setCurser(20, 5);
	if (aiDifficulty == 0) {
		printf("%2d자리 %s MODE ", length, MODE);
	}
	else {
		printf("%2d자리 %s MODE %s", length, MODE, DIFFICULTY);
	}
}

void printUserName(int mode, char* ID1, char* ID2, int isLogin) {
	switch (mode) {
	case SINGLEMODE: 
		setCurser(161, 6);
		isLogin ? printf("%s", ID1) : printf("NON-LOGIN PLAYER");
		break;
	case MULTIMODE:
		setCurser(161, 6);
		printf("%s", ID1);
		setCurser(1, 6);
		printf("%s", ID2);
		break;
	case AIMODE:
		setCurser(161, 6);
		isLogin ? printf("%s", ID1) : printf("NON-LOGIN PLAYER");
		setCurser(1, 6);
		printf("AI");
		break;
	}
}

void printUserInputArea(int mode, int isMyTurn) {
	if (mode != MULTIMODE) {
		for (int i = 0; i < 40; i++) {
			setCurser(70 + i, 41);
			printf("─");
			setCurser(70 + i, 49);
			printf("─");
			if (i > 4 && i < 36) {
				setCurser(70 + i, 48);
				printf("─");
			}
		}
		for (int i = 0; i < 8; i++) {
			setCurser(70, 42 + i);
			printf("│");
			setCurser(109, 42 + i);
			printf("│");
		}
		setCurser(70, 41); printf("┌");
		setCurser(70, 49); printf("└");
		setCurser(109, 41); printf("┐");
		setCurser(109, 49); printf("┘");
	}
	else {
		
	}
}

int getInputX(int baseballLength) {
	return 90 - (baseballLength / 2);
}

void printArrow(int direction) {
	removeArea(68, 69, 45, 45);
	removeArea(111, 112, 45, 45);
	switch (direction) {
	case LEFT:
		setCurser(68, 45);
		printf("◀");
		break;
	case RIGHT:
		setCurser(111, 45);
		printf("▶");
		break;
	}
}