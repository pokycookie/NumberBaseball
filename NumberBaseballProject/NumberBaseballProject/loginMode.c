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
	printf("��");
	setCurser(MENUX, MENUY + 1);
	printf("��");

	setCurser(MENUX + 6, MENUY + 1);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	removeArea(MENUX, MENUX + 100, MENUY, MENUY + 1);

	setCurser(MENUX - 2, MENUY);
	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		printf("�α����� ���������� ó���Ǿ����ϴ�.");
		mainMenuMode(USER.ID, TRUE);
	}
	else if (authCode == 1) {
		printf("�߸��� ��й�ȣ�Դϴ�.");
	}
	else {
		printf("�������� �ʴ� ���̵��Դϴ�.");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);
}