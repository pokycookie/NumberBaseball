#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareFunction.h"
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
	printf("WWWWWWWWWWWWWWWL      E####WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEL      tWWWWWWWWWWWWWWW");
	setCurser(x, y + 3);
	printf("WWWWWWWWWWWWW#    .WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#            DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE:    #WWWWWWWWWWWWW");
	setCurser(x, y + 4);
	printf("WWWWWWWWWWWWWj    #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#          ;DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE    iWWWWWWWWWWWWW");
	setCurser(x, y + 5);
	printf("WWWWWWWWWWWW    ;KWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKL          KEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEj    WWWWWWWWWWWW");
	setCurser(x, y + 6);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t          i#WWWWWWWWWWWWWWK.          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 7);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                    #WWWWWWWWWW#          DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 8);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWG                        fWWWWWWWWWW#          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 9);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                            WWWWWWWWWWWE        ,EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 10);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                              #WWWWWWWWWW:        KDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 11);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                WWWWWWWWWWWW          EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 12);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                ,WWWWWWWWWWWW#        DDEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 13);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                  WWWWWWWWWWWWK#        EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 14);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#t                                    WWWWWWWWWWWWWWWt      ;DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 15);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                        WWWWWWWWWWWWWWWW        KEEEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 16);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWK,                                        WWWWWWWWWWWWWWWWW#        DEEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 17);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                              #WWWWWWWWWWWWWWWWWWWW#      EDEEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 18);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWD                              WWWWWWWWWWWWWWWWWWWWWWKG      EEEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 19);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                ########################      ;KEEEEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 20);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWKW                                                    ####          EEEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 21);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW##                                                              :EEEEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 22);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                jDEEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 23);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                  jEEEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 24);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                      DEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 25);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWt                                                                        EEEEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 26);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                            KEEEEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 27);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                .EEEEEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 28);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWW:    .WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWL                                                                                  jEEEEEEEDG    WWWWWWWWWWWW");
	setCurser(x, y + 29);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWi        ,WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      DEEEEEDG    WWWWWWWWWWWW");
	setCurser(x, y + 30);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                                                      tDEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 31);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWW            #WWWWWWWWWWWWWWWWWWWWWWWWWWWWE                                                                                        GEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 32);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWK        EWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW;                                                                                        iEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 33);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                          EEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 34);
	printf("WWWWWWWWWWWW    fWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        ;DEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 35);
	printf("WWWWWWWWWWWW    LWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                        EEEEEEEG    WWWWWWWWWWWW");
	setCurser(x, y + 36);
	printf("WWWWWWWWWWWW    ;WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                                                                                      EEEEEEEEEt    WWWWWWWWWWWW");
	setCurser(x, y + 37);
	printf("WWWWWWWWWWWWWt    #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW###D                                                              KEEEEEEEEEEEEEEEEEEEEEEE    ;WWWWWWWWWWWWW");
	setCurser(x, y + 38);
	printf("WWWWWWWWWWWWW#      #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#                                                              KEEEEEEEEEEEEEEEEEEEEEE:    #WWWWWWWWWWWWW");
	setCurser(x, y + 39);
	printf("WWWWWWWWWWWWWWWL      G#######################################################                                                            WEEEEEEEEEEEEEEEEEEL      fWWWWWWWWWWWWWWW");
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
	printf("▷Exit");
}

void printMode(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("▶Single Mode");
	setCurser(MENUX, MENUY + 1);
	printf("▷Multi Mode");
	setCurser(MENUX, MENUY + 2);
	printf("▷A.I Mode");
	setCurser(MENUX, MENUY + 3);
	printf("▷HELP");
	setCurser(MENUX, MENUY + 4);
	printf("▷LOGOUT");
}

void printHelp(void) {
	system("cls");
	setCurser(70, 20);
	printf("숫자야구 도움말 들어갈 예정");
	setCurser(MENUX, MENUY);
	printf("▶Back");
}

void printBaseballLength(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("▶Easy");
	setCurser(MENUX, MENUY + 1);
	printf("▷Normal");
	setCurser(MENUX, MENUY + 2);
	printf("▷Hard");
	setCurser(MENUX, MENUY + 3);
	printf("▷사용자지정");
	setCurser(MENUX, MENUY + 4);
	printf("▷Back");
}

void printFreeBaseballSetting(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("▶Set Baseball Length");
	setCurser(MENUX, MENUY + 1);
	printf("▷Back");
}

void printPracticeModeForm(void) {
	for (int i = 0; i < 180; i++) {
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
	printf("▶OK");
}

void printRankBoardForm(int mode, int length, int aiDifficulty) {

	setCurser(87, 4);
	printf("RANKING");
	setCurser(20, 6);
	for (int i = 0; i < 140; i++) {
		printf("-");
	}
	setCurser(22, 7); printf("RANK");
	setCurser(30, 7); printf("ID");
	setCurser(44, 7); printf("Try Count");
	setCurser(60, 7); printf("Record Time");
	setCurser(140, 7); printf("DATE");

	setCurser(20, 8);
	for (int i = 0; i < 140; i++) {
		printf("-");
	}
	setCurser(20, 31);
	for (int i = 0; i < 140; i++) {
		printf("-");
	}

	char MODE[10], DIFFICULTY[10];
	switch (mode) {
	case 1: strcpy_s(MODE, sizeof(MODE), "SINGLE"); break;
	case 2: strcpy_s(MODE, sizeof(MODE), "MULTY"); break;
	case 3: strcpy_s(MODE, sizeof(MODE), "AI"); break;
	}
	switch (aiDifficulty) {
	case 0: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "NULL"); break;
	case 1: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "EASY"); break;
	case 2: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "NORMAL"); break;
	case 3: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "HARD"); break;
	case 4: strcpy_s(DIFFICULTY, sizeof(DIFFICULTY), "EXTREAM"); break;
	}

	setCurser(20, 5);
	if (aiDifficulty == 0) {
		printf("%2d자리 %s MODE ", length, MODE);
	}
	else {
		printf("%2d자리 %s MODE %s", length, MODE, DIFFICULTY);
	}
}