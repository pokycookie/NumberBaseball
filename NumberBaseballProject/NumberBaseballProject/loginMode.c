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
	printf("��");
	setCurser(MENUX, MENUY + 1);
	printf("��");

	setCurser(MENUX + 6, MENUY + 1);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	removeArea(MENUX, MENUX + 100, MENUY, MENUY + 1);

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		setCurser(MENUX - 6, MENUY);
		printf("�α����� ���������� ó���Ǿ����ϴ�.");
		printOkButton(MENUX - 2, MENUY + 2);
		selectColumnMenu(MENUX - 2, MENUY + 2, 1);
		mainMenuMode(USER.ID, TRUE);
		END = TRUE;
	}
	else if (authCode == 1) {
		setCurser(MENUX - 1, MENUY);
		printf("�߸��� ��й�ȣ�Դϴ�.");
	}
	else {
		setCurser(MENUX - 3, MENUY);
		printf("�������� �ʴ� ���̵��Դϴ�.");
	}
	if (!END) {
		printOkButton(MENUX - 2, MENUY + 2);
		selectColumnMenu(MENUX - 2, MENUY + 2, 1);
	}
}