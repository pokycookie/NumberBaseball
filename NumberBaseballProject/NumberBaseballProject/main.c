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
		// Login
		loginMode();
		goto Initial;
		break;
	case 2:
		// Sign Up
		signUpMode();
		goto Initial;
		break;
	case 3:
		// Non-Login
		mainMenuMode();
		goto Initial;
		break;
	case 4:
		system("cls");
		break;
	}
}