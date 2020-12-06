#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"

void loginMode(void) {
	struct auth USER;

	FILE* AuthDB = NULL;

	printLoginModeForm();

	setCurser(96, 24);
	cursorView(1);
	inputID(USER.ID);
	cursorView(0);

	setCurser(90, 24);
	printf("��");
	setCurser(90, 25);
	printf("��");

	setCurser(96, 25);
	cursorView(1);
	inputPW(USER.PW);
	cursorView(0);

	setCurser(90, 26);

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		printf("�α����� ���������� ó���Ǿ����ϴ�.");
		Sleep(200);
		mainMenuMode();
	}
	else if (authCode == 1) {
		printf("�߸��� ��й�ȣ�Դϴ�.");
		Sleep(200);
	}
	else {
		printf("�������� �ʴ� ���̵��Դϴ�.");
		Sleep(200);
	}
}