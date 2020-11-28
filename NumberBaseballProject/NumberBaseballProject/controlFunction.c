#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"

int arrowControl(void) {
	cursorView(0);
	char temp = _getch();
	if (temp == 77) {
		return 2; //Right
	}
	else if(temp == 75){
		return 1; //Left
	}
	else if (temp == 72) {
		return 3; //Up
	}
	else if (temp == 80) {
		return 4; //Down
	}
	else if (temp == 13 || temp == 32) {
		return 0; //Enter
	}
}

int selectColumnMenu(int x, int y, int count) {
	int currentCurser = 1;

	while (1) {
		int temp = arrowControl();
		if (temp == 3 && currentCurser > 1) {
			currentCurser--;
			for (int i = 0; i < count; i++) {
				setCurser(x, y + i);
				printf("▷");
			}
			setCurser(x, y - 1 + currentCurser);
			printf("▶");
		}
		else if (temp == 4 && currentCurser < count) {
			currentCurser++;
			for (int i = 0; i < count; i++) {
				setCurser(x, y + i);
				printf("▷");
			}
			setCurser(x, y - 1 + currentCurser);
			printf("▶");
		}
		else if (temp == 0) {
			break;
		}
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