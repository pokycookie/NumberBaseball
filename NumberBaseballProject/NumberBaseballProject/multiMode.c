#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"

void multiMode(void) {
	struct player player1; player1.tryCount = 0;
	struct player player2; player2.tryCount = 0;
	
	int baseballLength;
	int turn = 1;

	baseballLengthPoint:
	printBaseballLength();
	switch (selectColumnMenu(90, 24, 4)) {
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
	}

	system("cls");
	printPracticeModeForm();

	// Set Player's Baseball Number
	setCurser(3, 45);
	printf("Set Number: ");
	getCurrentNumber(player1.baseballNumber, baseballLength, 1);
	removeOneLine(45);

	setCurser(173, 45);
	printf("Set Number: ");
	getCurrentNumber(player2.baseballNumber, baseballLength, 1);
	removeOneLine(45);

	// Game Start
	while (1) {
		if (turn == 1) {
			removeOneLine(45);
			setCurser(3, 45);
			printf("input number: ");
			getCurrentNumber(player1.currentNumber, baseballLength, 0);
			removeArea(31, 169, 6, 39);
			player1.checkedData = checkData(player1.currentNumber, player2.baseballNumber, baseballLength);
			player1.tryCount++;
			printResult(player1.checkedData.strike, player1.checkedData.ball, player1.checkedData.out, baseballLength);
			storeData(player1.rememberedData, player1.currentNumber, baseballLength, player1.checkedData, player1.tryCount);
			printRememberedData(player1.rememberedData, baseballLength, player1.tryCount, 1);
			setCurser(1, 39);
			printf("TRY: %d", player1.tryCount);
			if (player1.checkedData.strike == baseballLength)
				break;
			cursorView(0);
		}
		else {
			removeOneLine(45);
			setCurser(173, 45);
			printf("input number: ");
			getCurrentNumber(player2.currentNumber, baseballLength, 0);
			removeArea(31, 169, 6, 39);
			player2.checkedData = checkData(player2.currentNumber, player1.baseballNumber, baseballLength);
			player2.tryCount++;
			printResult(player2.checkedData.strike, player2.checkedData.ball, player2.checkedData.out, baseballLength);
			storeData(player2.rememberedData, player2.currentNumber, baseballLength, player2.checkedData, player2.tryCount);
			printRememberedData(player2.rememberedData, baseballLength, player2.tryCount, 2);
			setCurser(171, 39);
			printf("TRY: %d", player2.tryCount);
			if (player2.checkedData.strike == baseballLength)
				break;
			cursorView(0);
		}
		turn = toggleTurn(turn);
	}
}