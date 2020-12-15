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
// Print Logo
void printMainLogo(int x, int y) {
	setCurser(x, y + 0);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 1);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWW##::                                                                                                                                        ..##WWWWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 2);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWL      E####WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEL      tWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 3);
	printf("WWWWWWWWWWWWWWWWWWWWWWW#    .WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE:    #WWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 4);
	printf("WWWWWWWWWWWWWWWWWWWWWWWj    #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#          ;DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE    iWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 5);
	printf("WWWWWWWWWWWWWWWWWWWWWW    ;KWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKL          KEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEj    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 6);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t          i#WWWWWWWWWWWWWWK.          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 7);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                    #WWWWWWWWWW#          DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 8);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWG                        fWWWWWWWWWW#          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 9);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                            WWWWWWWWWWWE        ,EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 10);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                              #WWWWWWWWWW:        KDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 11);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                WWWWWWWWWWWW          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 12);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                ,WWWWWWWWWWWW#        DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 13);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                  WWWWWWWWWWWWK#        EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 14);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t                                    WWWWWWWWWWWWWWWt      ;DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 15);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                        WWWWWWWWWWWWWWWW        KEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 16);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWK,                                        WWWWWWWWWWWWWWWWW#        DEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 17);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                              #WWWWWWWWWWWWWWWWWWWW#      EDEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 18);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                              WWWWWWWWWWWWWWWWWWWWWWKG      EEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 19);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                ########################      ;KEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 20);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKW                                                    ####          EEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 21);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW##                                                              :EEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 22);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                jDEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 23);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                  jEEEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 24);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                      DEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 25);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                                                                        EEEEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 26);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                            KEEEEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 27);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                .EEEEEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 28);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWW:    .WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWL                                                                                  jEEEEEEEDG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 29);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWi        ,WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      DEEEEEDG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 30);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                      tDEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 31);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWWE                                                                                        GEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 32);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWK        EWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW;                                                                                        iEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 33);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                          EEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 34);
	printf("WWWWWWWWWWWWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        ;DEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 35);
	printf("WWWWWWWWWWWWWWWWWWWWWW    LWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        EEEEEEEG    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 36);
	printf("WWWWWWWWWWWWWWWWWWWWWW    ;WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      EEEEEEEEEt    WWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 37);
	printf("WWWWWWWWWWWWWWWWWWWWWWWt    #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW###D                                                              KEEEEEEEEEEEEEEEEEEEEEEE    ;WWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 38);
	printf("WWWWWWWWWWWWWWWWWWWWWWW#      #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                              KEEEEEEEEEEEEEEEEEEEEEE:    #WWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 39);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWL      G#######################################################                                                            WEEEEEEEEEEEEEEEEEEL      fWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 40);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWj                                                                                                                                                iWWWWWWWWWWWWWWWWWWWWWWWWWWW");
	setCurser(x, y + 41);
	printf("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW");
}

// Print Select Menu
void printLogin(void) {
	system("cls");
	setCurser(90, 44);
	printf("▶로그인");
	setCurser(90, 45);
	printf("▷회원가입");
	setCurser(90, 46);
	printf("▷비로그인");
	setCurser(90, 47);
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
	setCurser(90, 28);
	printf("▷Back");
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