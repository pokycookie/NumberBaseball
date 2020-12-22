#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void multiMode(int baseballLength, char *ID1, char* ID2) {
	struct player player1; player1.tryCount = 0;
	struct player player2; player2.tryCount = 0;

	for (int i = 0; i < 10; i++) {
		player1.baseballNumber[i] = 0;
		player2.baseballNumber[i] = 0;
	}
	
	int turn = 1;
	int lose = FALSE; int goToMain = FALSE;
	int winner = 1; // 1: player1, 2: player2
	int startTime, endTime;

	system("cls");
	printPracticeModeForm(MULTIMODE, FALSE, baseballLength);
	printUserName(MULTIMODE, ID2, ID1, TRUE);
	printUserInputArea(SINGLEMODE, FALSE);

	// Set Player's Baseball Number
	setCurser(80, 42);
	printf("당신의 숫자를 정하세요");
	printArrow(LEFT);

	while (TRUE) {
		if (lose || goToMain) break;
		cursorView(TRUE);
		setCurser(getInputX(baseballLength), 47);
		if (getCurrentNumber(player1.baseballNumber, baseballLength, TRUE)) {
			switch (makeGameMenu()) {
			case 1: break;
			case 2: lose = TRUE; break;
			case 3: goToMain = TRUE; removeArea(22, 158, 6, 39); break;
			}
		}
		else {
			break;
		}
		removeArea(22, 158, 6, 39);
		setCurser(80, 42);
		printf("당신의 숫자를 정하세요");
		removeArea(75, 105, 47, 47);
	}
	removeArea(72, 107, 42, 42);
	removeArea(75, 105, 47, 47);

	setCurser(80, 42);
	printf("당신의 숫자를 정하세요");
	printArrow(RIGHT);

	while (TRUE) {
		if (lose || goToMain) break;
		cursorView(TRUE);
		setCurser(getInputX(baseballLength), 47);
		if (getCurrentNumber(player2.baseballNumber, baseballLength, TRUE)) {
			switch (makeGameMenu()) {
			case 1: break;
			case 2: lose = TRUE; break;
			case 3: goToMain = TRUE; removeArea(22, 158, 6, 39); break;
			}
		}
		else {
			break;
		}
		removeArea(22, 158, 6, 39);
		setCurser(80, 42);
		printf("당신의 숫자를 정하세요");
		removeArea(75, 105, 47, 47);
	}
	removeArea(72, 107, 42, 42);
	removeArea(75, 105, 47, 47);


	startTime = clock();

	// Game Start
	while (!goToMain) {
		if (turn == 1) {
			setCurser(82, 42);
			printf("숫자를 입력하세요");
			printArrow(LEFT);
			removeArea(75, 105, 47, 47);
			while (TRUE) {
				if (lose || goToMain) break;
				setCurser(getInputX(baseballLength), 47);
				cursorView(TRUE);
				if (getCurrentNumber(player1.currentNumber, baseballLength, 0)) {
					switch (makeGameMenu()) {
					case 1: removeArea(22, 158, 6, 39); break;
					case 2: lose = TRUE; removeArea(22, 158, 6, 39); break;
					case 3: goToMain = TRUE; removeArea(22, 158, 6, 39); break;
					}
				}
				else {
					break;
				}
				setCurser(82, 42);
				printf("숫자를 입력하세요");
				removeArea(75, 105, 47, 47);
				cursorView(FALSE);
			}
			if (!lose && !goToMain) {
				player1.checkedData = checkData(player1.currentNumber, player2.baseballNumber, baseballLength);
				player1.tryCount++;
				removeArea(22, 158, 6, 39);
				printResult(player1.checkedData.strike, player1.checkedData.ball, player1.checkedData.out, baseballLength);
				storeData(player1.rememberedData, player1.currentNumber, baseballLength, player1.checkedData, player1.tryCount);
				printRememberedData(player1.rememberedData, baseballLength, player1.tryCount, 1);
				setCurser(1, 39);
				printf("TRY: %d", player1.tryCount);
			}
			if (player1.checkedData.strike == baseballLength) {
				winner = 1;
				break;
			}
			if(lose){
				winner = 2;
				break;
			}
			cursorView(FALSE);
		}
		else {
			setCurser(82, 42);
			printf("숫자를 입력하세요");
			printArrow(RIGHT);
			removeArea(75, 105, 47, 47);
			while (TRUE) {
				if (lose || goToMain) break;
				setCurser(getInputX(baseballLength), 47);
				cursorView(TRUE);
				if (getCurrentNumber(player2.currentNumber, baseballLength, 0)) {
					switch (makeGameMenu()) {
					case 1: removeArea(22, 158, 6, 39); break;
					case 2: lose = TRUE; removeArea(22, 158, 6, 39); break;
					case 3: goToMain = TRUE; removeArea(22, 158, 6, 39); break;
					}
				}
				else {
					break;
				}
				setCurser(82, 42);
				printf("숫자를 입력하세요");
				removeArea(75, 105, 47, 47);
				cursorView(FALSE);
			}
			if (!lose && !goToMain) {
				player2.checkedData = checkData(player2.currentNumber, player1.baseballNumber, baseballLength);
				player2.tryCount++;
				removeArea(22, 158, 6, 39);
				printResult(player2.checkedData.strike, player2.checkedData.ball, player2.checkedData.out, baseballLength);
				storeData(player2.rememberedData, player2.currentNumber, baseballLength, player2.checkedData, player2.tryCount);
				printRememberedData(player2.rememberedData, baseballLength, player2.tryCount, 2);
				setCurser(161, 39);
				printf("TRY: %d", player2.tryCount);
			}
			if (player2.checkedData.strike == baseballLength) {
				winner = 2;
				break;
			}
			if (lose) {
				winner = 1;
				break;
			}
			cursorView(FALSE);
		}
		turn = toggleTurn(turn);
	}
	// Game Finish
	removeArea(68, 69, 45, 45);
	removeArea(111, 112, 45, 45);

	endTime = clock();
	struct time recordTime = convertTimeUnit((endTime - startTime) / 1000);

	struct rank rank;
	rank.mode = MULTIMODE, rank.baseballLength = baseballLength, rank.aiDifficulty = 0, rank.tryCount = player1.tryCount, rank.recordTime = recordTime;

	time_t now = time(NULL);
	localtime_s(&rank.realTime, &now);

	if (!goToMain) {
		// Print Game Result
		printGameResult(rank, ID1, player1.baseballNumber, ID2, player2.baseballNumber, winner == 1 ? ID1 : ID2, TRUE);

		// Save DB
		FILE* RankDB = NULL;
		setRankDB(RankDB, rank);
		updateMulitRankDB(RankDB, ID1, ID2, winner == 1 ? ID1 : ID2, rank);

		// OK Button
		setCurser(80, 42);
		printf("게임이 종료되었습니다");
		removeArea(75, 105, 43, 48);
		printOkButton(MENUX - 2, MENUY + 2);
		selectColumnMenu(MENUX - 2, MENUY + 2, 1);
	}

	cursorView(FALSE);
}