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

	printLoginModeForm();

	setCurser(96, 44);
	cursorView(1);
	inputID(USER.ID);
	cursorView(0);

	setCurser(90, 44);
	printf("▷");
	setCurser(90, 45);
	printf("▶");

	setCurser(96, 45);
	cursorView(1);
	inputPW(USER.PW);
	cursorView(0);

	setCurser(90, 47);

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		printf("로그인이 정상적으로 처리되었습니다.");
		Sleep(200);
		mainMenuMode(USER.ID, TRUE);
	}
	else if (authCode == 1) {
		printf("잘못된 비밀번호입니다.");
		Sleep(200);
	}
	else {
		printf("존재하지 않는 아이디입니다.");
		Sleep(200);
	}
}