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
			printf("��");
		}
		setCurser(x, y + currentCurser - 1);
		printf("��");
	}
	return currentCurser;
}

int makeGameMenu() {
	removeArea(22, 158, 6, 39);
	cursorView(FALSE);
	
	// Print Form
	setCurser(61, 12);
	for (int i = 0; i < 59; i++) {
		printf("��");
	}
	setCurser(61, 33);
	for (int i = 0; i < 59; i++) {
		printf("��");
	}
	for (int i = 0; i < 20; i++) {
		setCurser(60, 13 + i);
		printf("��");
		setCurser(120, 13 + i);
		printf("��");
	}
	setCurser(60, 12); printf("��");
	setCurser(120, 12); printf("��");
	setCurser(60, 33); printf("��");
	setCurser(120, 33); printf("��");

	// Print Menu
	setCurser(MENUX + 5, 14);
	printf("������ϱ�");
	setCurser(MENUX + 5, 15);
	printf("�������ϱ�");
	
	return selectColumnMenu(MENUX + 5, 14, 2);
}

// Print Large Number
void printLargeNumber(char character, int displayNumber) {
	cursorView(FALSE);
	switch (character){
	case '1':
		setColor(8, 7);
		setCurser(LNX(displayNumber) + 29, 9);
		printf("��");
		for (int i = 0; i < 26; i++) {
			setCurser(LNX(displayNumber) + 27, 10 + i);
			printf("����");
		}
		setCurser(LNX(displayNumber) + 29, 36);
		printf("��");
		break;
	case '2':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 27, 12 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 3, 24 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case '3':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 27, 12 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case '4':
		setColor(8, 7);
		for (int i = 0; i < 12; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("�������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("����");
		}
		break;
	case '5':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 3, 12 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case '6':
		setColor(8, 7);
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("����");
		}
		break;
	case '7':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("����");
		}
		break;
	case '8':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case '9':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 12; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case '0':
		setColor(8, 7);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 27, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		break;
	case 'S':
		setColor(6, 15);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����������������");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 3, 12 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		setCurser(LNX(displayNumber) + 3, 9); printf("  ");
		setCurser(LNX(displayNumber) + 31, 9); printf("  ");
		setCurser(LNX(displayNumber) + 9, 12); printf("��");
		setCurser(LNX(displayNumber) + 27, 12); printf("����");
		setCurser(LNX(displayNumber) + 29, 13); printf("���");
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 31, 14 + i);
			printf("��");
		}
		setCurser(LNX(displayNumber) + 9, 20); printf("��");
		setCurser(LNX(displayNumber) + 31, 21); printf("  ");
		setCurser(LNX(displayNumber) + 3, 23); printf("  ");
		setCurser(LNX(displayNumber) + 25, 24); printf("��");
		setCurser(LNX(displayNumber) + 25, 33); printf("��");
		setCurser(LNX(displayNumber) + 31, 36); printf("  ");
		setCurser(LNX(displayNumber) + 3, 36); printf("  ");
		setCurser(LNX(displayNumber) + 3, 33); printf("����");
		setCurser(LNX(displayNumber) + 3, 32); printf("���");
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 29 + i);
			printf("��");
		}
		break;
	case 'B':
		setColor(6, 15);
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("�������������");
			setCurser(LNX(displayNumber) + 3, 21 + i);
			printf("����������������");
			setCurser(LNX(displayNumber) + 3, 34 + i);
			printf("����������������");
		}
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(displayNumber) + 3, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 9; i++) {
			setCurser(LNX(displayNumber) + 21, 12 + i);
			printf("����");
		}
		for (int i = 0; i < 10; i++) {
			setCurser(LNX(displayNumber) + 27, 24 + i);
			printf("����");
		}
		break;
	case 'O':
		setColor(6, 15);
		// O
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 7, 9 + i);
			printf("�����������������");
			setCurser(LNX(1) + 7, 34 + i);
			printf("�����������������");
		}
		for (int i = 0; i < 22; i++) {
			setCurser(LNX(1) + 7, 12 + i);
			printf("����");
			setCurser(LNX(1) + 33, 12 + i);
			printf("����");
		}
		// U
		for (int i = 0; i < 28; i++) {
			setCurser(LNX(1) + 53, 9 + i);
			printf("����");
			setCurser(LNX(1) + 79, 9 + i);
			printf("����");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 59, 34 + i);
			printf("�����������");
		}
		// T
		for (int i = 0; i < 3; i++) {
			setCurser(LNX(1) + 99, 9 + i);
			printf("������������������");
		}
		for (int i = 0; i < 25; i++) {
			setCurser(LNX(1) + 113, 12 + i);
			printf("����");
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
	printf("���α���");
	setCurser(MENUX, MENUY + 1);
	printf("��ȸ������");
	setCurser(MENUX, MENUY + 2);
	printf("����α���");
	setCurser(MENUX, MENUY + 3);
	printf("��Exit");
}

void printMode(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("��Single Mode");
	setCurser(MENUX, MENUY + 1);
	printf("��Multi Mode");
	setCurser(MENUX, MENUY + 2);
	printf("��A.I Mode");
	setCurser(MENUX, MENUY + 3);
	printf("��HELP");
	setCurser(MENUX, MENUY + 4);
	printf("��LOGOUT");
}

void printHelp(void) {
	system("cls");
	setCurser(70, 20);
	printf("���ھ߱� ���� �� ����");
	setCurser(MENUX, MENUY);
	printf("��Back");
}

void printBaseballLength(void) {
	system("cls");
	setCurser(MENUX, MENUY);
	printf("��Easy");
	setCurser(MENUX, MENUY + 1);
	printf("��Normal");
	setCurser(MENUX, MENUY + 2);
	printf("��Hard");
	setCurser(MENUX, MENUY + 3);
	printf("�����������");
	setCurser(MENUX, MENUY + 4);
	printf("��Back");
}

void printGameOption(int gameMode) {
	for (int i = 0; i < 165; i++) {
		setCurser(i + 7, 5);
		printf("��");
	}

	setCurser(7, 4);
	switch (gameMode) {
	case SINGLEMODE: printf("SINGLE MODE"); break;
	case MULTIMODE: printf("MULTI MODE"); break;
	case AIMODE: printf("AI MODE"); break;
	}
	setCurser(150, 4);
	printf("���� �ɼ��� �����ϼ���");

	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 41; i++) {
			if (i > 4 && i < 37) {
				setCurser(GOX(n) + i, 13);
				printf("��");
				if (gameMode != AIMODE) {
					setCurser(GOX(n) + i, 17);
					printf("��");
				}
				else {
					setCurser(GOX(n) + i, 18);
					printf("��");
				}
			}
			setCurser(GOX(n) + i, 7);
			printf("��");
			setCurser(GOX(n) + i, 43);
			printf("��");
		}
		for (int i = 0; i < 37; i++) {
			setCurser(GOX(n), 7 + i);
			printf("��");
			setCurser(GOX(n) + 40, 7 + i);
			printf("��");
		}
		setCurser(GOX(n), 7); printf("��");
		setCurser(GOX(n) + 40, 7); printf("��");
		setCurser(GOX(n), 43); printf("��");
		setCurser(GOX(n) + 40, 43); printf("��");
	}

	for (int i = 0; i < 23; i++) {
		setCurser(78 + i, 45);
		printf("��");
		setCurser(78 + i, 47);
		printf("��");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(78, 45 + i);
		printf("��");
		setCurser(100, 45 + i);
		printf("��");
	}
	setCurser(78, 45); printf("��");
	setCurser(100, 45); printf("��");
	setCurser(78, 47); printf("��");
	setCurser(100, 47); printf("��");
	setCurser(88, 46); printf("BACK");

	setCurser(25, 11); printf("EASY");
	setCurser(66, 11); printf("NORMAL");
	setCurser(109, 11); printf("HARD");
	setCurser(148, 11); printf("����� ����");
	
	setCurser(20, 15); printf("���ھ߱� 3�ڸ�");
	setCurser(62, 15); printf("���ھ߱� 4�ڸ�");
	setCurser(104, 15); printf("���ھ߱� 5�ڸ�");
	setCurser(142, 15); printf("���ھ߱� �ڸ��� ����");

	if (gameMode == AIMODE) {
		setCurser(20, 16); printf("�ΰ����� EASY");
		setCurser(62, 16); printf("�ΰ����� NORMAL");
		setCurser(104, 16); printf("�ΰ����� HARD");
		setCurser(146, 16); printf("�ΰ����� ����");

		setCurser(16, 20); printf("���ھ߱� �ʱ��ڿ� �Դϴ�.");
		setCurser(8, 22); printf("���ھ߱��� ó�� ���ϴºв� ��õ�մϴ�.");

		setCurser(58, 20); printf("���ھ߱� �߱��ڿ� �Դϴ�.");
		setCurser(52, 22); printf("���ھ߱��� �ͼ��Ѻв� ��õ�մϴ�.");

		setCurser(99, 20); printf("���ھ߱� ����ڿ� �Դϴ�.");
		setCurser(96, 22); printf("���ھ߱� ������� ��õ�մϴ�.");

		setCurser(144, 20); printf("����� ���� �Դϴ�.");
		setCurser(138, 22); printf("���ھ߱� �ڸ����� �ΰ�������");
		setCurser(144, 23); printf("�����Ӱ� �����ϼ���");

		for (int i = 0; i < 32; i++) {
			setCurser(137 + i ,38);
			printf("��");
		}
	}
	else {
		setCurser(16, 19); printf("���ھ߱� �ʱ��ڿ� �Դϴ�.");
		setCurser(8, 21); printf("���ھ߱��� ó�� ���ϴºв� ��õ�մϴ�.");

		setCurser(58, 19); printf("���ھ߱� �߱��ڿ� �Դϴ�.");
		setCurser(52, 21); printf("���ھ߱��� �ͼ��Ѻв� ��õ�մϴ�.");

		setCurser(99, 19); printf("���ھ߱� ����ڿ� �Դϴ�.");
		setCurser(96, 21); printf("���ھ߱� ������� ��õ�մϴ�.");

		setCurser(144, 19); printf("����� ���� �Դϴ�.");
		setCurser(134, 21); printf("���ھ߱� �ڸ����� �����Ӱ� �����ϼ���");

		for (int i = 0; i < 32; i++) {
			setCurser(137 + i, 38);
			printf("��");
		}
	}
}

int selectGameOption(void) {
	int currentCurser = 1;

	for (int i = 0; i < 41; i++) {
		setCurser(GOX(0) + i, 7);
		printf("��");
		setCurser(GOX(0) + i, 43);
		printf("��");
	}
	for (int i = 0; i < 37; i++) {
		setCurser(GOX(0), 7 + i);
		printf("��");
		setCurser(GOX(0) + 40, 7 + i);
		printf("��");
	}
	setCurser(GOX(0), 7); printf("��");
	setCurser(GOX(0) + 40, 7); printf("��");
	setCurser(GOX(0), 43); printf("��");
	setCurser(GOX(0) + 40, 43); printf("��");

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
					printf("��");
				}
				setCurser(GOX(n) + i, 7);
				printf("��");
				setCurser(GOX(n) + i, 43);
				printf("��");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GOX(n), 7 + i);
				printf("��");
				setCurser(GOX(n) + 40, 7 + i);
				printf("��");
			}
			setCurser(GOX(n), 7); printf("��");
			setCurser(GOX(n) + 40, 7); printf("��");
			setCurser(GOX(n), 43); printf("��");
			setCurser(GOX(n) + 40, 43); printf("��");
		}

		for (int i = 0; i < 23; i++) {
			setCurser(78 + i, 45);
			printf("��");
			setCurser(78 + i, 47);
			printf("��");
		}
		for (int i = 0; i < 3; i++) {
			setCurser(78, 45 + i);
			printf("��");
			setCurser(100, 45 + i);
			printf("��");
		}
		setCurser(78, 45); printf("��");
		setCurser(100, 45); printf("��");
		setCurser(78, 47); printf("��");
		setCurser(100, 47); printf("��");
		setCurser(88, 46); printf("BACK");

		if (currentCurser < 5) {
			for (int i = 0; i < 41; i++) {
				setCurser(GOX(currentCurser - 1) + i, 7);
				printf("��");
				setCurser(GOX(currentCurser - 1) + i, 43);
				printf("��");
			}
			for (int i = 0; i < 37; i++) {
				setCurser(GOX(currentCurser - 1), 7 + i);
				printf("��");
				setCurser(GOX(currentCurser - 1) + 40, 7 + i);
				printf("��");
			}
			setCurser(GOX(currentCurser - 1), 7); printf("��");
			setCurser(GOX(currentCurser - 1) + 40, 7); printf("��");
			setCurser(GOX(currentCurser - 1), 43); printf("��");
			setCurser(GOX(currentCurser - 1) + 40, 43); printf("��");
		}
		else {
			for (int i = 0; i < 23; i++) {
				setCurser(78 + i, 45);
				printf("��");
				setCurser(78 + i, 47);
				printf("��");
			}
			for (int i = 0; i < 3; i++) {
				setCurser(78, 45 + i);
				printf("��");
				setCurser(100, 45 + i);
				printf("��");
			}
			setCurser(78, 45); printf("��");
			setCurser(100, 45); printf("��");
			setCurser(78, 47); printf("��");
			setCurser(100, 47); printf("��");
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

int selectAiDifficulty(void) {
	int currentCurser = EASY;

	setCurser(148, 42);
	printf("��  EASY  ��");

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
		case EASY: setCurser(148, 42); printf("��  EASY  ��"); break;
		case NORMAL: setCurser(148, 42); printf("�� NORMAL ��"); break;
		case HARD: setCurser(148, 42); printf("��  HARD  ��"); break;
		}
	}
	return currentCurser;
}

void printPracticeModeForm(int mode, int aiDifficulty ,int baseballLength) {
	// Basic Form
	for (int i = 0; i < 180; i++) {
		if (i < 20 || i > 170) {
			setCurser(i, 3);
			printf("��");
		}
		else {
			setCurser(i, 4);
			printf("��");
		}
		if (i < 20 || i > 159) {
			setCurser(i, 7);
			printf("��");
			setCurser(i, 38);
			printf("��");
		}
		setCurser(i, 5);
		printf("��");
		setCurser(i, 40);
		printf("��");
	}
	for (int i = 6; i < 40; i++) {
		setCurser(20, i);
		printf("��");
		setCurser(159, i);
		printf("��");
	}
	setCurser(20, 5); printf("��");
	setCurser(159, 5); printf("��");
	setCurser(20, 40); printf("��");
	setCurser(159, 40); printf("��");

	setCurser(20, 3); printf("��");
	setCurser(20, 4); printf("��");
	setCurser(170, 3); printf("��");
	setCurser(170, 4); printf("��");
	
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
	printf("%2d�ڸ�", baseballLength);
}

void printSignUpModeForm(void) {
	setCurser(MENUX, MENUY);
	printf("��     ID:");
	setCurser(MENUX, MENUY + 1);
	printf("��     PW:");
	setCurser(MENUX, MENUY + 2);
	printf("��PW Ȯ��:");
}

void printLoginModeForm(void) {
	setCurser(MENUX, MENUY);
	printf("��ID:");
	setCurser(MENUX, MENUY + 1);
	printf("��PW:");
}

void printOkButton(int x, int y) {
	setCurser(x, y);
	for (int i = 0; i < 23; i++) {
		setCurser(x + i, y);
		printf("��");
		setCurser(x + i, y + 2);
		printf("��");
	}
	for (int i = 0; i < 3; i++) {
		setCurser(x, y + i);
		printf("��");
		setCurser(x + 22, y + i);
		printf("��");
	}
	setCurser(x, y); printf("��");
	setCurser(x + 22, y); printf("��");
	setCurser(x, y + 2); printf("��");
	setCurser(x + 22, y + 2); printf("��");
	setCurser(x + 11, y + 1); printf("OK");
}

void printRankBoardForm(int mode, int length, int aiDifficulty) {

	setCurser(87, 3);
	printf("RANKING");
	setCurser(20, 6);
	for (int i = 0; i < 140; i++) {
		printf("��");
	}
	setCurser(22, 7); printf("RANK");
	setCurser(30, 7); printf("ID");
	setCurser(44, 7); printf("Try Count");
	setCurser(60, 7); printf("Record Time");
	setCurser(140, 7); printf("DATE");

	setCurser(20, 8);
	for (int i = 0; i < 140; i++) {
		printf("��");
	}
	setCurser(20, 31);
	for (int i = 0; i < 140; i++) {
		printf("��");
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
		printf("%2d�ڸ� %s MODE ", length, MODE);
	}
	else {
		printf("%2d�ڸ� %s MODE %s", length, MODE, DIFFICULTY);
	}
}

void printUserName(int mode, char* ID, int isLogin) {
	switch (mode) {
	case SINGLEMODE: 
		setCurser(161, 6);
		isLogin ? printf("%s", ID) : printf("NON-LOGIN PLAYER");
		break;
	case MULTIMODE: break;
	case AIMODE:
		setCurser(161, 6);
		isLogin ? printf("%s", ID) : printf("NON-LOGIN PLAYER");
		setCurser(1, 6);
		printf("AI");
		break;
	}
}

void printUserInputArea(int mode, int isMyTurn) {
	if (mode != MULTIMODE) {
		for (int i = 0; i < 40; i++) {
			setCurser(70 + i, 41);
			printf("��");
			setCurser(70 + i, 49);
			printf("��");
			if (i > 4 && i < 36) {
				setCurser(70 + i, 48);
				printf("��");
			}
		}
		for (int i = 0; i < 8; i++) {
			setCurser(70, 42 + i);
			printf("��");
			setCurser(109, 42 + i);
			printf("��");
		}
		setCurser(70, 41); printf("��");
		setCurser(70, 49); printf("��");
		setCurser(109, 41); printf("��");
		setCurser(109, 49); printf("��");
	}
	else {
		
	}
}

int getInputX(int baseballLength) {
	return 90 - (baseballLength / 2);
}