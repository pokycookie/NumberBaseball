#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"
#include "define.h"

void loginMode(void) {
	struct auth USER;
	int END = FALSE;

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

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		setCurser(MENUX - 6, MENUY);
		printf("로그인이 정상적으로 처리되었습니다.");
		printOkButton(MENUX - 2, MENUY + 2);
		selectColumnMenu(MENUX - 2, MENUY + 2, 1);
		mainMenuMode(USER.ID, TRUE);
		END = TRUE;
	}
	else if (authCode == 1) {
		setCurser(MENUX - 1, MENUY);
		printf("잘못된 비밀번호입니다.");
	}
	else {
		setCurser(MENUX - 3, MENUY);
		printf("존재하지 않는 아이디입니다.");
	}
	if (!END) {
		printOkButton(MENUX - 2, MENUY + 2);
		selectColumnMenu(MENUX - 2, MENUY + 2, 1);
	}
}

int secondLoginMode(char* secondID, char* currentID) {
	struct auth USER;
	int result = FALSE;

	FILE* AuthDB = NULL;

	system("cls");
	printMainLogo(0, 0);

	setCurser(MENUX - 6, MENUY - 1);
	printf("[대전할 상대는 로그인을 해주세요]");
	
	setCurser(MENUX - 2, MENUY + 1);
	printf("▶ID:");
	setCurser(MENUX - 2, MENUY + 2);
	printf("▷PW:");
	
	setCurser(MENUX + 4, MENUY + 1);
	cursorView(TRUE);
	inputID(USER.ID);
	cursorView(FALSE);

	setCurser(MENUX - 2, MENUY + 1);
	printf("▷");
	setCurser(MENUX - 2, MENUY + 2);
	printf("▶");

	setCurser(MENUX + 4, MENUY + 2);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	removeOneLine(MENUY + 1);
	removeOneLine(MENUY + 2);

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (strcmp(USER.ID, currentID) == 0) {
		setCurser(MENUX - 6, MENUY);
		printf("현재 로그인한 아이디와 동일합니다.");
		result = FALSE;
	}
	else {
		if (authCode == 0) {
			setCurser(MENUX - 6, MENUY);
			printf("로그인이 정상적으로 처리되었습니다.");
			strcpy_s(secondID, 10 * sizeof(char), USER.ID);
			result = TRUE;
		}
		else if (authCode == 1) {
			setCurser(MENUX - 1, MENUY);
			printf("잘못된 비밀번호입니다.");
			result = FALSE;
		}
		else {
			setCurser(MENUX - 3, MENUY);
			printf("존재하지 않는 아이디입니다.");
			result = FALSE;
		}
	}

	removeOneLine(MENUY - 1);
	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);

	return result;
}