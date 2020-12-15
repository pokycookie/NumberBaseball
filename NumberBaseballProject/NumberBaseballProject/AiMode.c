#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"

int AiMode(void) {
	struct player player1; player1.tryCount = 0;
	static struct AI AI; AI.tryCount = 0;

	int baseballLength = 0;
	int turn = 1;

	baseballLengthPoint:
	printBaseballLength();
	switch (selectColumnMenu(90, 24, 5)) {
	case 1:
		baseballLength = 3;
		break;
	case 2:
		baseballLength = 4;
		break;
	case 3:
		baseballLength = 5;
		break;
	case 4:
		printFreeBaseballSetting();
		switch (selectColumnMenu(90, 24, 2)) {
		case 1:
			cursorView(1);
			baseballLength = getBaseballLength();
			break;
		case 2:
			goto baseballLengthPoint;
			break;
		}
		break;
	case 5:
		return 1;
		break;
	}

	system("cls");
	printPracticeModeForm();

	AI.possibilityCount = makeAllPossibilityArr(AI.possibilityArr, baseballLength);

	// Set Player's Baseball Number
	setCurser(90, 45);
	printf("Set Number: ");
	getCurrentNumber(player1.baseballNumber, baseballLength, 0);
	removeOneLine(45);

	getBaseballNumber(AI.baseballNumber, baseballLength);

	// Game Start
	while (1) {
		if (turn == 1) {
			removeOneLine(45);
			setCurser(90, 45);
			printf("input number: ");
			getCurrentNumber(player1.currentNumber, baseballLength, 0);
			removeArea(31, 169, 6, 39);
			player1.checkedData = checkData(player1.currentNumber, AI.baseballNumber, baseballLength);
			player1.tryCount++;
			printResult(player1.checkedData.strike, player1.checkedData.ball, player1.checkedData.out, baseballLength);
			storeData(player1.rememberedData, player1.currentNumber, baseballLength, player1.checkedData, player1.tryCount);
			printRememberedData(player1.rememberedData, baseballLength, player1.tryCount, 2);
			setCurser(171, 39);
			printf("TRY: %d", player1.tryCount);
			if (player1.checkedData.strike == baseballLength)
				break;
			cursorView(0);
		}
		else {
			Sleep(1000);
			getNextNumber_prototypeAI(AI.currentNumber, AI.possibilityArr, AI.possibilityCount, AI.tryCount, baseballLength);
			removeArea(31, 169, 6, 39);
			AI.previousData.resultData = checkData(AI.currentNumber, player1.baseballNumber, baseballLength);
			AI.tryCount++;
			printResult(AI.previousData.resultData.strike, AI.previousData.resultData.ball, AI.previousData.resultData.out, baseballLength);
			storeData(AI.rememberedData, AI.currentNumber, baseballLength, AI.previousData.resultData, AI.tryCount);
			printRememberedData(AI.rememberedData, baseballLength, AI.tryCount, 1);
			copyIntArray(AI.currentNumber, baseballLength, AI.previousData.baseballNumber, baseballLength);
			AI.possibilityCount = getPossibilityArr_prototypeAI(AI.possibilityArr, AI.possibilityCount, AI.previousData, baseballLength);
			if (AI.previousData.resultData.strike == baseballLength)
				break;
			cursorView(0);
		}
		turn = toggleTurn(turn);
	}
	return 0;
	cursorView(0);
}