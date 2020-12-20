#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"
#include "define.h"

void practiceMode(char* ID, int isLogin, int baseballLength) {
	int baseballNumber[10];
	int currentNumber[10];
	int tryCount = 0;
	int lose = FALSE, breakWhile = FALSE;
	int startTime, endTime;
	
	struct resultData checkedData;
	struct rememberedData rememberedData[30];

	system("cls");
	getBaseballNumber(baseballNumber, baseballLength);

	// For Debug -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	setCurser(0, 0);
	printf("Random Number: ");
	for (int i = 0; i < baseballLength; i++) {
		printf("%d", baseballNumber[i]);
	}
	// For Debug -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	
	printPracticeModeForm(SINGLEMODE, FALSE ,baseballLength);
	printUserName(SINGLEMODE, ID, isLogin);
	printUserInputArea(SINGLEMODE, FALSE);

	startTime = clock();

	while (TRUE) {
		setCurser(82, 42);
		printf("숫자를 입력하세요");
		removeArea(75, 105, 47, 47);
		while (TRUE) {
			if (lose) break;
			setCurser(getInputX(baseballLength), 47);
			cursorView(TRUE);
			if (getCurrentNumber(currentNumber, baseballLength, 0)) {
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
			cursorView(FALSE);
		}
		if (!lose) {
			checkedData = checkData(currentNumber, baseballNumber, baseballLength);
			tryCount++;
			removeArea(22, 158, 6, 39);
			printResult(checkedData.strike, checkedData.ball, checkedData.out, baseballLength);
			storeData(rememberedData, currentNumber, baseballLength, checkedData, tryCount);
			printRememberedData(rememberedData, baseballLength, tryCount, 2);
			setCurser(161, 39);
			printf("TRY: %d", tryCount);
		}
		if (checkedData.strike == baseballLength || lose)
			break;
	}

	endTime = clock();
	struct time recordTime = convertTimeUnit((endTime - startTime) / 1000);

	struct rank rank;
	rank.mode = SINGLEMODE, rank.baseballLength = baseballLength, rank.aiDifficulty = 0, rank.tryCount = tryCount, rank.recordTime = recordTime;
	
	time_t now = time(NULL);
	localtime_s(&rank.realTime, &now);
	
	printGameResult(rank, "COMPUTER", baseballNumber, ID, FALSE, lose ? "COMPUTER" : ID, isLogin);

	setCurser(80, 42);
	printf("게임이 종료되었습니다");
	removeArea(75, 105, 43, 48);
	printOkButton(MENUX - 2, MENUY + 2);
	selectColumnMenu(MENUX - 2, MENUY + 2, 1);

	rankMode(ID, lose ? FALSE : isLogin, rank);
	
	cursorView(FALSE);
}