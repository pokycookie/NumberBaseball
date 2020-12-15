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
	printf("▷");
	setCurser(90, 25);
	printf("▶");

	setCurser(101, 25);
	cursorView(1);
	inputPW(USER.PW);
	cursorView(0);

	setCurser(90, 25);
	printf("▷");
	setCurser(90, 26);
	printf("▶");

	setCurser(101, 26);
	cursorView(1);
	inputPW(verifyPW);
	cursorView(0);

	setCurser(90, 30);
	if ((strcmp(USER.PW, verifyPW) == 0) && checkUsedID(AuthDB, USER.ID) == 0) {
		printf("회원가입이 정상적으로 처리되었습니다.");
		updateAuthDB(AuthDB, USER.ID, USER.PW);
	}
	else if(strcmp(USER.PW, verifyPW) != 0) {
		printf("비밀번호가 서로 일치하지 않습니다.");
	}
	else if (checkUsedID(AuthDB, USER.ID) == 1) {
		printf("해당 ID는 이미 사용중입니다.");
	}
	else {
		printf("알수없는 오류입니다.");
	}

	Sleep(500);
}