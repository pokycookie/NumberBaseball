#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"

void main(void) {
	initialDesign();

	Initial:
	system("cls");
	printLogin();
	switch (selectColumnMenu(90, 24, 4)) {
	case 1:
		system("cls");
		printf("로그인");
		break;
	case 2:
		system("cls");
		printf("회원가입");
		break;
	case 3:
		printMainMenu();
		switch (selectColumnMenu(90, 24, 3)) {
		case 1:
			printMode();
			switch (selectColumnMenu(90, 24, 4)) {
			case 1:
				practiceMode();
				Sleep(2000);
				system("cls");
				goto Initial;
				break;
			case 2:
				system("cls");
				printf("Multi Mode");
				break;
			case 3:
				system("cls");
				printf("A.I Mode");
				break;
			case 4:
				goto Initial;
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
			goto Initial;
			break;
		}
		break;
	case 4:
		system("cls");
		break;
	}
}