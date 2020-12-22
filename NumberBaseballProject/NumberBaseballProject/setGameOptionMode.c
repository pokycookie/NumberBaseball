#include <stdio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void setGameOptionMode(int gameMode, char* ID, int isLogin) {
	int baseballLength;
	int aiDifficulty = HARD;
	int END = FALSE;
	char secondID[10];

	system("cls");
	printGameOption(gameMode);
	if (!isLogin && gameMode == MULTIMODE) {
		setCurser(18, 4);
		setColor(12, 15);
		printf("�ظ�Ƽ���� �α��λ��·θ� �̿��Ͻ� �� �ֽ��ϴ�. ���Ӹ�� ����â���� ���ư��ϴ�.");
		setColor(0, 15);
	}
	if (gameMode != AIMODE) {
		switch (selectGameOption()) {
		case 1: baseballLength = 3; break;
		case 2: baseballLength = 4; break;
		case 3: baseballLength = 5; break;
		case 4:
			setCurser(137, 39);
			printf("���ھ߱� �ڸ����� �����ϼ���: ");
			cursorView(TRUE);
			baseballLength = getBaseballLength();
			cursorView(FALSE);
			break;
		case 5:
			END = TRUE;
			break;
		}
	}
	else {
		switch (selectGameOption()) {
		case 1: baseballLength = 3; aiDifficulty = EASY; break;
		case 2: baseballLength = 4; aiDifficulty = NORMAL; break;
		case 3: baseballLength = 5; aiDifficulty = HARD; break;
		case 4:
			setCurser(137, 39);
			printf("���ھ߱� �ڸ����� �����ϼ���: ");
			cursorView(TRUE);
			baseballLength = getBaseballLength();

			removeArea(137, 169, 39, 39);
			setCurser(142, 38);
			printf("AI ���̵��� �����ϼ���");
			aiDifficulty = selectAiDifficulty(TRUE);

			cursorView(FALSE);
			break;
		case 5:
			END = TRUE;
			break;
		}
	}

	if (!END) {
		switch (gameMode) {
		case SINGLEMODE: practiceMode(ID, isLogin, baseballLength); break;
		case MULTIMODE:
			if (!isLogin) break;
			if (secondLoginMode(secondID, ID)) {
				multiMode(baseballLength, ID, secondID);
			}
			break;
		case AIMODE: AiMode(ID, isLogin, baseballLength, aiDifficulty); break;
		}
	}
}