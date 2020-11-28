#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "define.h"

int arrowControl(void) {
	cursorView(0);
	int temp = _getch();
	if (temp == 0 || temp == 0xE0) {
		temp = _getch();
		switch (temp) {
		case LEFT:
			return LEFT; //Left
			break;
		case RIGHT:
			return RIGHT; //Right
			break;
		case UP:
			return UP; //Up
			break;
		case DOWN:
			return DOWN; //Down
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

void printMainMenu(void) {
	system("cls");
	setCurser(90, 24);
	printf("▶Game Start");
	setCurser(90, 25);
	printf("▷Help");
	setCurser(90, 26);
	printf("▷Exit");
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
	printf("▶back");
}