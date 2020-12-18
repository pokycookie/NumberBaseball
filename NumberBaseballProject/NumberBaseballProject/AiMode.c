#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"
#include "define.h"

void AiMode(char* ID, int isLogin, int baseballLength) {
	struct player player1; player1.tryCount = 0;
	static struct AI AI; AI.tryCount = 0;

	int turn = 1; // 1: Player, 2: AI
	int lose = FALSE;
	int startTime, endTime;

	system("cls");
	printPracticeModeForm();

	AI.possibilityCount = makeAllPossibilityArr(AI.possibilityArr, baseballLength);

	// Set Player's Baseball Number
	setCurser(80, 45);
	printf("당신의 숫자를 정하세요: ");

	while (TRUE) {
		if (lose) break;
		cursorView(TRUE);
		if (getCurrentNumber(player1.baseballNumber, baseballLength, 0)) {
			switch (makeGameMenu()) {
			case 1: break;
			case 2: lose = TRUE; break;
			}
		}
		else {
			break;
		}
		removeArea(21, 159, 6, 39);
		removeOneLine(45);
		setCurser(80, 45);
		printf("당신의 숫자를 정하세요: ");
	}

	getBaseballNumber(AI.baseballNumber, baseballLength);

	startTime = clock();

	// Game Start
	while (TRUE) {
		if (turn == 1) {
			removeOneLine(45);
			setCurser(80, 45);
			printf("input number: ");
			while (TRUE) {
				if (lose) break;
				cursorView(TRUE);
				if (getCurrentNumber(player1.currentNumber, baseballLength, 0)) {
					switch (makeGameMenu()) {
					case 1: removeArea(22, 158, 6, 39); break;
					case 2: lose = TRUE; break;
					}
				}
				else {
					break;
				}
				removeOneLine(45);
				setCurser(80, 45);
				printf("input number: ");
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
		}
		else {
			Sleep(1000);
			cursorView(FALSE);
			getNextNumber_prototypeAI(AI.currentNumber, AI.possibilityArr, AI.possibilityCount, AI.tryCount, baseballLength);
			AI.previousData.resultData = checkData(AI.currentNumber, player1.baseballNumber, baseballLength);
			AI.tryCount++;
			removeArea(21, 159, 6, 39);
			printResult(AI.previousData.resultData.strike, AI.previousData.resultData.ball, AI.previousData.resultData.out, baseballLength);
			storeData(AI.rememberedData, AI.currentNumber, baseballLength, AI.previousData.resultData, AI.tryCount);
			printRememberedData(AI.rememberedData, baseballLength, AI.tryCount, 1);
			copyIntArray(AI.currentNumber, baseballLength, AI.previousData.baseballNumber, baseballLength);
			AI.possibilityCount = getPossibilityArr_prototypeAI(AI.possibilityArr, AI.possibilityCount, AI.previousData, baseballLength);
			if (AI.previousData.resultData.strike == baseballLength) {
				lose = TRUE;
				break;
			}
		}
		turn = toggleTurn(turn);
	}

	endTime = clock();
	struct time recordTime = convertTimeUnit((endTime - startTime) / 1000);

	struct rank rank;
	rank.mode = AIMODE, rank.baseballLength = baseballLength, rank.aiDifficulty = 3, rank.tryCount = player1.tryCount, rank.recordTime = recordTime;

	time_t now = time(NULL);
	localtime_s(&rank.realTime, &now);
	
	printOkButton(MENUX, MENUY + 2);
	selectColumnMenu(MENUX, MENUY + 2, 1);
	rankMode(ID, lose ? FALSE : isLogin, rank);

	cursorView(FALSE);
}