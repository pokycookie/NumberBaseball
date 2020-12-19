#include <stdio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void setGameOptionMode(int gameMode, char* ID, int isLogin) {
	int baseballLength;
	int aiDifficulty = HARD;
	int END = FALSE;

	system("cls");
	printGameOption(gameMode);
	if (gameMode != AIMODE) {
		switch (selectGameOption()) {
		case 1: baseballLength = 3; break;
		case 2: baseballLength = 4; break;
		case 3: baseballLength = 5; break;
		case 4:
			setCurser(137, 40);
			printf("숫자야구 자릿수를 설정하세요: ");
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
			setCurser(137, 40);
			printf("숫자야구 자릿수를 설정하세요: ");
			cursorView(TRUE);
			baseballLength = getBaseballLength();

			removeArea(137, 169, 40, 40);
			setCurser(142, 40);
			printf("AI 난이도를 설정하세요");
			selectAiDifficulty();

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
		case MULTIMODE: multiMode(baseballLength); break;
		case AIMODE: AiMode(ID, isLogin, baseballLength, aiDifficulty); break;
		}
	}
}