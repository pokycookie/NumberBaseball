#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"

void mainMenuMode(void) {
	Initial:
	printMainMenu();
	switch (selectColumnMenu(90, 24, 3)) {
	case 1:
		printMode();
		switch (selectColumnMenu(90, 24, 4)) {
		case 1:
			// Practice Mode
			practiceMode();
			Sleep(1000);
			system("cls");
			break;
		case 2:
			// Multiplay Mode
			multiMode();
			Sleep(1000);
			system("cls");
			break;
		case 3:
			// A.I Mode
			system("cls");
			setCurser(90, 24);
			printf("¹Ì±¸Çö");
			Sleep(1000);
			goto Initial;
			break;
		case 4:
			break;
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