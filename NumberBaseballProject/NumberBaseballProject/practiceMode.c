#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"

void practiceMode(void) {
	system("cls");
	cursorView(1);

	int baseballNumber[10];
	int baseballLength = getBaseballLength();
	int currentNumber[10];
	int tryCount = 0;
	struct resultData checkedData;

	getBaseballNumber(baseballNumber, baseballLength);

	printf("\nRandom Number: ");
	for (int i = 0; i < baseballLength; i++) {
		printf("%d", baseballNumber[i]);
	}
	printf("\n\n");

	while (1) {
		printf("input number: ");
		getCurrentNumber(currentNumber, baseballLength);
		checkedData = checkData(currentNumber, baseballNumber, baseballLength);
		printResult(checkedData.strike, checkedData.ball, checkedData.out, baseballLength);
		tryCount++;
		printf("try: %d\n\n", tryCount);
		if (checkedData.strike == baseballLength)
			break;
	}
	cursorView(0);
}