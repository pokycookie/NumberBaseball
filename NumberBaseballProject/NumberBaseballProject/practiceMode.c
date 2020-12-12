#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"

void practiceMode(void) {
	int baseballNumber[10];
	int currentNumber[10];
	int baseballLength;
	int tryCount = 0;

	struct resultData checkedData;
	struct rememberedData rememberedData[30];

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
	cursorView(1);
	getBaseballNumber(baseballNumber, baseballLength);

	/*
	printf("\nRandom Number: ");
	for (int i = 0; i < baseballLength; i++) {
		printf("%d", baseballNumber[i]);
	}
	printf("\n\n");
	*/
	
	printPracticeModeForm();
	while (1) {
		removeOneLine(45);
		setCurser(90, 45);
		printf("input number: ");
		getCurrentNumber(currentNumber, baseballLength);
		removeArea(31, 169, 6, 39);
		checkedData = checkData(currentNumber, baseballNumber, baseballLength);
		tryCount++;
		printResult(checkedData.strike, checkedData.ball, checkedData.out, baseballLength);
		storeData(rememberedData, currentNumber, baseballLength, checkedData, tryCount);
		printRememberedData(rememberedData, baseballLength, tryCount);
		setCurser(171, 39);
		printf("TRY: %d\n\n", tryCount);
		if (checkedData.strike == baseballLength)
			break;
	}
	cursorView(0);
}