#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"
#include "define.h"

void loginMode(void) {
	struct auth USER;

	FILE* AuthDB = NULL;

	printMainLogo(0, 0);
	printLoginModeForm();

	setCurser(MENUX + 6, MENUY);
	cursorView(TRUE);
	inputID(USER.ID);
	cursorView(FALSE);

	setCurser(MENUX, MENUY);
	printf("▷");
	setCurser(MENUX, MENUY + 1);
	printf("▶");

	setCurser(MENUX + 6, MENUY + 1);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	removeArea(MENUX, MENUX + 100, MENUY, MENUY + 1);

	setCurser(MENUX - 2, MENUY);
	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		printf("로그인이 정상적으로 처리되었습니다.");
		mainMenuMode(USER.ID, TRUE);
	}
	else if (authCode == 1) {
		printf("잘못된 비밀번호입니다.");
	}
	else {
		printf("존재하지 않는 아이디입니다.");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);
}