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

	setCurser(101, 44);
	cursorView(1);
	inputID(USER.ID);
	cursorView(0);

	setCurser(90, 44);
	printf("��");
	setCurser(90, 45);
	printf("��");

	setCurser(101, 45);
	cursorView(1);
	inputPW(USER.PW);
	cursorView(0);

	setCurser(90, 45);
	printf("��");
	setCurser(90, 46);
	printf("��");

	setCurser(101, 46);
	cursorView(1);
	inputPW(verifyPW);
	cursorView(0);

	setCurser(90, 48);
	if ((strcmp(USER.PW, verifyPW) == 0) && checkUsedID(AuthDB, USER.ID) == 0) {
		printf("ȸ�������� ���������� ó���Ǿ����ϴ�.");
		updateAuthDB(AuthDB, USER.ID, USER.PW);
	}
	else if(strcmp(USER.PW, verifyPW) != 0) {
		printf("��й�ȣ�� ���� ��ġ���� �ʽ��ϴ�.");
	}
	else if (checkUsedID(AuthDB, USER.ID) == 1) {
		printf("�ش� ID�� �̹� ������Դϴ�.");
	}
	else {
		printf("�˼����� �����Դϴ�.");
	}

	Sleep(500);
}