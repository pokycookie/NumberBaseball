#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void getNextNumber(int* result, int possibilityArr[][10], int possibilityCount, int tryCount, int baseballLength) {
	int randNumber[10];
	struct resultData resultData;

	if (tryCount == 0) {
		getBaseballNumber(result, baseballLength);
	}
	else {
		copyIntArray(possibilityArr[getRandomNumber(0, possibilityCount - 1)], baseballLength, result, baseballLength);
	}
}

int getPossibilityArr(int possibilityArr[][10], int possibilityCount, struct rememberedData previousData, int baseballLength, int aiDifficulty, int limit) {
	int count = 0;
	static int temp[10000000][10];
	
	if (baseballLength != 1) {
		for (int i = 0; i < possibilityCount; i++) {
			if (compareResultData(checkData(possibilityArr[i], previousData.baseballNumber, baseballLength), previousData.resultData)) {
				copyIntArray(possibilityArr[i], baseballLength, temp[count], baseballLength);
				count++;
			}
		}

		for (int i = 0; i < count; i++) {
			copyIntArray(temp[i], baseballLength, possibilityArr[i], baseballLength);
		}

		switch (aiDifficulty)
		{
		case EASY:
			if (count < (limit / 2 - 1) && count > 10) {
				count *= 2;
			}
			else {
				count += 10;
			}
			break;
		case NORMAL:
			if (count < (limit / 1.5 - 1) && count > 10) {
				count *= 1.5;
			}
			else {
				count += 1;
			}
			break;
		}
	}
	else {
		for (int i = 0; i < possibilityCount; i++) {
			if (previousData.baseballNumber[0] != possibilityArr[i][0]) {
				temp[i][0] = possibilityArr[i][0];
				count++;
			}
		}

		for (int i = 0; i < count; i++) {
			possibilityArr[i][0] = temp[i][0];
		}
	}

	removeArea(0, 19, 39, 39);
	setCurser(0, 39);
	double percent = (1 / (double)count) * 100;
	printf("WIN PERCENT: %.2f%%", percent);

	return count;
}

int makeAllPossibilityArr(int possibilityArr[][10], int baseballLength) {
	int number[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int count = 0;

	if (baseballLength != 1) {
		for (int arr = 0; arr < 3628800; arr++) {
			for (int i = 0; i < baseballLength; i++) {
				if (i == baseballLength - 1) {
					number[i]++;
					if (number[i] == 10) {
						number[i] = 0;
						number[i - 1]++;
						for (int j = i - 1; j > 0; j--) {
							if (number[j] == 10) {
								number[j] = 0;
								number[j - 1]++;
							}
						}
					}
				}
			}
			for (int i = 0; i < baseballLength; i++) {
				possibilityArr[arr][i] = number[i];
			}
			if (baseballNumberFilter(possibilityArr[arr], baseballLength) == FALSE) {
				arr--;
				count--;
			}
			if (possibilityArr[arr][0] == 10) break;
			count++;
		}
	}
	else {
		for (int arr = 0; arr < 10; arr++) {
			possibilityArr[arr][0] = arr;
		}
		count = 10;
	}

	return count;
}