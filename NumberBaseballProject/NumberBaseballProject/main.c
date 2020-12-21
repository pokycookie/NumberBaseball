#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void main(void) {
	int EXIT = FALSE;
	initialDesign();

	while (TRUE) {
		system("cls");
		printLogin();
		printMainLogo(0, 0);
		switch (selectColumnMenu(MENUX, MENUY, 5)) {
		case 1:
			// Login
			system("cls");
			loginMode();
			break;
		case 2:
			// Sign Up
			system("cls");
			signUpMode();
			break;
		case 3:
			// Non-Login
			system("cls");
			mainMenuMode("NULL", FALSE);
			break;
		case 4: helpMode(); break;
		case 5:
			system("cls");
			EXIT = TRUE;
			break;
		}
		if (EXIT == TRUE) break;
	}
}