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
	printf("��");
	setCurser(90, 45);
	printf("��");

	setCurser(96, 45);
	cursorView(1);
	inputPW(USER.PW);
	cursorView(0);

	setCurser(90, 47);

	int authCode = authenticateUser(AuthDB, USER.ID, USER.PW);
	if (authCode == 0) {
		printf("�α����� ���������� ó���Ǿ����ϴ�.");
		Sleep(200);
		mainMenuMode(USER.ID, TRUE);
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