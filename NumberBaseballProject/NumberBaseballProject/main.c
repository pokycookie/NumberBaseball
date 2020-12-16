#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void main(void) {
	initialDesign();

	Initial:
	printLogin();
	printMainLogo(0, 0);
	switch (selectColumnMenu(90, 44, 4)) {
	case 1:
		// Login
		system("cls");
		loginMode();
		goto Initial;
		break;
	case 2:
		// Sign Up
		system("cls");
		signUpMode();
		goto Initial;
		break;
	case 3:
		// Non-Login
		system("cls");
		mainMenuMode("NULL", FALSE);
		goto Initial;
		break;
	case 4:
		system("cls");
		break;
	}
}