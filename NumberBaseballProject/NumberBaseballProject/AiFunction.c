#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void getNextNumber_prototypeAI(int* result, int possibilityArr[][10], int possibilityCount, int tryCount, int baseballLength) {
	int randNumber[10];
	struct resultData resultData;

	if (tryCount == 0) {
		getBaseballNumber(result, baseballLength);
	}
	else {
		copyIntArray(possibilityArr[getRandomNumber(0, possibilityCount)], baseballLength, result, baseballLength);
	}
}

int getPossibilityArr_prototypeAI(int possibilityArr[][10], int possibilityCount, struct rememberedData previousData, int baseballLength) {
	int count = 0;
	static int temp[100000][10];
	for (int i = 0; i < possibilityCount; i++) {
		if (compareResultData(checkData(possibilityArr[i], previousData.baseballNumber, baseballLength), previousData.resultData) == TRUE) {
			copyIntArray(possibilityArr[i], baseballLength, temp[count], baseballLength);
			count++;
		}
	}
	for (int i = 0; i < possibilityCount; i++) {
		copyIntArray(temp[i], baseballLength, possibilityArr[i], baseballLength);
	}
	removeOneLine(1);
	setCurser(0, 1);
	printf("Number of Case: %d", count);
	return count;
}

int makeAllPossibilityArr(int possibilityArr[][10], int baseballLength) {
	int number[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int count = 0;

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
	setCurser(0,0);
	printf("CACULATE FINISH: %d", count);

	return count;
}