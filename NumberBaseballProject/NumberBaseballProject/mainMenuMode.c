#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"

int mainMenuMode(char *ID, int isLogin) {
	Initial:
	printMainMenu();
	switch (selectColumnMenu(90, 24, 3)) {
	case 1:
		CASE1:
		printMode();
		switch (selectColumnMenu(90, 24, 4)) {
		case 1:
			// Practice Mode
			if (practiceMode(ID) == 0) {
				system("cls");
			}
			else {
				goto CASE1;
			}
			break;
		case 2:
			// Multiplay Mode
			if (multiMode() == 0) {
				Sleep(1000);
				system("cls");
			}
			else {
				goto CASE1;
			}
			break;
		case 3:
			// A.I Mode
			if (AiMode(ID) == 0) {
				system("cls");
			}
			else {
				goto CASE1;
			}
			break;
		case 4:
			goto Initial;
		}
		break;
	case 2:
		printHelp();
		switch (selectColumnMenu(90, 24, 1)) {
		case 1:
			goto Initial;
			break;
		}
		break;
	case 3:
		break;
	}
}