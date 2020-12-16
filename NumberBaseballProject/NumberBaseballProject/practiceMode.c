#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include "declareFunction.h"
#include "declareMode.h"
#include "structure.h"

int practiceMode(char* ID) {
	int baseballNumber[10];
	int currentNumber[10];
	int baseballLength;
	int tryCount = 0;
	int startTime, endTime;
	
	struct resultData checkedData;
	struct rememberedData rememberedData[30];

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
	cursorView(1);
	getBaseballNumber(baseballNumber, baseballLength);

	setCurser(0, 0);
	printf("Random Number: ");
	for (int i = 0; i < baseballLength; i++) {
		printf("%d", baseballNumber[i]);
	}
	
	printPracticeModeForm();

	startTime = clock();

	while (1) {
		removeOneLine(45);
		setCurser(90, 45);
		printf("input number: ");
		getCurrentNumber(currentNumber, baseballLength, 0);
		removeArea(31, 169, 6, 39);
		checkedData = checkData(currentNumber, baseballNumber, baseballLength);
		tryCount++;
		printResult(checkedData.strike, checkedData.ball, checkedData.out, baseballLength);
		storeData(rememberedData, currentNumber, baseballLength, checkedData, tryCount);
		printRememberedData(rememberedData, baseballLength, tryCount, 2);
		setCurser(171, 39);
		printf("TRY: %d", tryCount);
		if (checkedData.strike == baseballLength)
			break;
	}

	endTime = clock();
	struct time recordTime = convertTimeUnit((endTime - startTime) / 1000);

	struct rank rank;
	rank.mode = 1, rank.baseballLength = baseballLength, rank.aiDifficulty = 0, rank.tryCount = tryCount, rank.recordTime = recordTime;
	
	time_t now = time(NULL);
	localtime_s(&rank.realTime, &now);

	rankMode(ID, rank);

	cursorView(FALSE);
	return 0;
}