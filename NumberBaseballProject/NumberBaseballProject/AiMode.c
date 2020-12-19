#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"
#include "define.h"

void AiMode(char* ID, int isLogin, int baseballLength, int aiDifficulty) {
	struct player player1; player1.tryCount = 0;
	static struct AI AI; AI.tryCount = 0;

	int limit;
	int turn = 1; // 1: Player, 2: AI
	int lose = FALSE;
	int startTime, endTime;
	
	system("cls");
	printPracticeModeForm(AIMODE, aiDifficulty, baseballLength);
	printUserName(AIMODE, ID, isLogin);
	printUserInputArea(AIMODE, FALSE);

	AI.possibilityCount = makeAllPossibilityArr(AI.possibilityArr, baseballLength);
	limit = AI.possibilityCount;

	// Set Player's Baseball Number
	setCurser(80, 42);
	printf("당신의 숫자를 정하세요");

	while (TRUE) {
		if (lose) break;
		cursorView(TRUE);
		setCurser(getInputX(baseballLength), 47);
		if (getCurrentNumber(player1.baseballNumber, baseballLength, 0)) {
			switch (makeGameMenu()) {
			case 1: break;
			case 2: lose = TRUE; break;
			}
		}
		else {
			break;
		}
		removeArea(22, 159, 6, 39);
		setCurser(80, 42);
		printf("당신의 숫자를 정하세요");
		removeArea(75, 105, 47, 47);
	}
	removeArea(72, 107, 42, 42);

	getBaseballNumber(AI.baseballNumber, baseballLength);

	startTime = clock();

	// Game Start
	while (TRUE) {
		if (turn == 1) {
			setCurser(82, 42);
			printf("숫자를 입력하세요");
			removeArea(75, 105, 47, 47);
			while (TRUE) {
				if (lose) break;
				cursorView(TRUE);
				setCurser(getInputX(baseballLength), 47);
				if (getCurrentNumber(player1.currentNumber, baseballLength, 0)) {
					switch (makeGameMenu()) {
					case 1: removeArea(22, 158, 6, 39); break;
					case 2: lose = TRUE; removeArea(22, 158, 6, 39); break;
					}
				}
				else {
					break;
				}
				setCurser(82, 42);
				printf("숫자를 입력하세요");
				removeArea(75, 105, 47, 47);
			}
			if (!lose) {
				player1.checkedData = checkData(player1.currentNumber, AI.baseballNumber, baseballLength);
				player1.tryCount++;
				removeArea(22, 158, 6, 39);
				printResult(player1.checkedData.strike, player1.checkedData.ball, player1.checkedData.out, baseballLength);
				storeData(player1.rememberedData, player1.currentNumber, baseballLength, player1.checkedData, player1.tryCount);
				printRememberedData(player1.rememberedData, baseballLength, player1.tryCount, 2);
				setCurser(161, 39);
				printf("TRY: %d", player1.tryCount);
			}
			if (player1.checkedData.strike == baseballLength) {
				lose = FALSE;
				break;
			}
			if (lose) {
				break;
			}
		}
		else {
			Sleep(1000);
			cursorView(FALSE);
			getNextNumber(AI.currentNumber, AI.possibilityArr, AI.possibilityCount, AI.tryCount, baseballLength);
			AI.previousData.resultData = checkData(AI.currentNumber, player1.baseballNumber, baseballLength);
			AI.tryCount++;
			removeArea(22, 158, 6, 39);
			printResult(AI.previousData.resultData.strike, AI.previousData.resultData.ball, AI.previousData.resultData.out, baseballLength);
			storeData(AI.rememberedData, AI.currentNumber, baseballLength, AI.previousData.resultData, AI.tryCount);
			printRememberedData(AI.rememberedData, baseballLength, AI.tryCount, 1);
			copyIntArray(AI.currentNumber, baseballLength, AI.previousData.baseballNumber, baseballLength);
			AI.possibilityCount = getPossibilityArr(AI.possibilityArr, AI.possibilityCount, AI.previousData, baseballLength, aiDifficulty, limit);
			if (AI.previousData.resultData.strike == baseballLength) {
				lose = TRUE;
				break;
			}
		}
		turn = toggleTurn(turn);
		cursorView(FALSE);
		removeArea(75, 105, 47, 47);
		removeArea(71, 108, 42, 42);
	}

	endTime = clock();
	struct time recordTime = convertTimeUnit((endTime - startTime) / 1000);

	struct rank rank;
	rank.mode = AIMODE, rank.baseballLength = baseballLength, rank.aiDifficulty = 3, rank.tryCount = player1.tryCount, rank.recordTime = recordTime;

	time_t now = time(NULL);
	localtime_s(&rank.realTime, &now);
	
	setCurser(80, 42);
	printf("게임이 종료되었습니다");
	removeArea(75, 105, 43, 48);
	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);

	rankMode(ID, lose ? FALSE : isLogin, rank);

	cursorView(FALSE);
}