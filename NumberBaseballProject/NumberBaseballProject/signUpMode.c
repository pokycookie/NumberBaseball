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
	printf("��");
	setCurser(MENUX, MENUY + 1);
	printf("��");

	setCurser(MENUX + 11, MENUY + 1);
	cursorView(TRUE);
	inputPW(USER.PW);
	cursorView(FALSE);

	setCurser(MENUX, MENUY + 1);
	printf("��");
	setCurser(MENUX, MENUY + 2);
	printf("��");

	setCurser(MENUX + 11, MENUY + 2);
	cursorView(TRUE);
	inputPW(verifyPW);
	cursorView(FALSE);

	removeArea(MENUX, MENUX + 100, MENUY, MENUY + 2);

	
	if (strcmp(USER.PW, verifyPW) == 0 && checkUsedID(AuthDB, USER.ID)) {
		setCurser(MENUX - 6, MENUY);
		printf("ȸ�������� ���������� ó���Ǿ����ϴ�.");
		updateAuthDB(AuthDB, USER.ID, USER.PW);
	}
	else if(strcmp(USER.PW, verifyPW) != 0) {
		setCurser(MENUX - 6, MENUY);
		printf("��й�ȣ�� ���� ��ġ���� �ʽ��ϴ�.");
	}
	else if (!checkUsedID(AuthDB, USER.ID)) {
		setCurser(MENUX - 4, MENUY);
		printf("�ش� ID�� �̹� ������Դϴ�.");
	}
	else {
		printf("�˼����� �����Դϴ�.");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);
}