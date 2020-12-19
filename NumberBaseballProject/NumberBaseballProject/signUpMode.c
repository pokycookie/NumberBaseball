#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void signUpMode(void) {
	struct auth USER;
	char verifyPW[15];

	FILE* AuthDB = NULL;

	cursorView(0);
	printMainLogo(0, 0);
	printSignUpModeForm();

	setCurser(MENUX + 11, MENUY);
	cursorView(TRUE);
	inputID(USER.ID);
	cursorView(FALSE);

	setCurser(MENUX, MENUY);
	printf("▷");
	setCurser(MENUX, MENUY + 1);
	printf("▶");

	setCurser(MENUX + 11, MENUY + 1);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	setCurser(MENUX, MENUY + 1);
	printf("▷");
	setCurser(MENUX, MENUY + 2);
	printf("▶");

	setCurser(MENUX + 11, MENUY + 2);
	cursorView(TRUE);
	inputPW(verifyPW);
	cursorView(FALSE);

	removeArea(MENUX, MENUX + 100, MENUY, MENUY + 2);

	
	if (strcmp(USER.PW, verifyPW) == 0 && checkUsedID(AuthDB, USER.ID)) {
		setCurser(MENUX - 6, MENUY);
		printf("회원가입이 정상적으로 처리되었습니다.");
		updateAuthDB(AuthDB, USER.ID, USER.PW);
	}
	else if(strcmp(USER.PW, verifyPW) != 0) {
		setCurser(MENUX - 6, MENUY);
		printf("비밀번호가 서로 일치하지 않습니다.");
	}
	else if (!checkUsedID(AuthDB, USER.ID)) {
		setCurser(MENUX - 4, MENUY);
		printf("해당 ID는 이미 사용중입니다.");
	}
	else {
		printf("알수없는 오류입니다.");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);
}