#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "declareFunction.h"
#include "structure.h"

void signUpMode(void) {
	struct auth USER;
	char verifyPW[15];

	FILE* AuthDB = NULL;

	cursorView(0);
	printSignUpModeForm();

	setCurser(101, 24);
	cursorView(1);
	inputID(USER.ID);

	cursorView(0);
	setCurser(90, 24);
	printf("¢¹");
	setCurser(90, 25);
	printf("¢º");

	setCurser(101, 25);
	cursorView(1);
	inputPW(USER.PW);

	cursorView(0);
	setCurser(90, 25);
	printf("¢¹");
	setCurser(90, 26);
	printf("¢º");

	setCurser(101, 26);
	cursorView(1);
	inputPW(verifyPW);

	setCurser(90, 30);
	if (strcmp(USER.PW, verifyPW) == 0) {
		printf("Verified!!!");
		updateAuthDB(AuthDB, USER.ID, USER.PW);
	}
	else {
		printf("Fail!!!");
	}

	Sleep(2000);
}