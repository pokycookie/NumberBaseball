#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>
#include "structure.h"
#include "declareFunction.h"
#include "define.h"

void getBaseballNumber(int* numberArr, int length) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < length; i++) {
		int check = 0;
		int randomNumber = rand() % 10;

		if (i > 0) {
			for (int j = 0; j < i; j++) {
				if (numberArr[j] == randomNumber) {
					i--;
					check = 1;
					break;
				}
			}
		}
		if (check == 0) {
			numberArr[i] = randomNumber;
		}
	}
}

int getRandomNumber(int min, int max) {
	srand((unsigned int)time(NULL));
	int randomNumber = rand() / 10;
	if (randomNumber < min) {
		randomNumber = min;
	}
	else if (randomNumber >= max) {
		randomNumber = max - 1;
	}
	return randomNumber;
}

int getBaseballLength(void) {
	int count = 0;
	char tempNumber[3];
	
	setCurser(90, 24);
	printf("¢ºSet Baseball Length: ");
	while (1) {
		char temp = _getch();
		if (count == 0 && temp > 48 && temp <= 57) {
			tempNumber[count] = temp;
			printf("%c", temp);
			count++;
		}
		else if (count == 1 && tempNumber[count - 1] == 49 && temp == 48) {
			tempNumber[count] = temp;
			printf("%c", temp);
			count++;
		}
		if (temp == 8 && count > 0) {
			printf("\b \b");
			count--;
		}
		if (temp == 13 && count > 0) {
			printf("\n");
			break;
		}
	}
	tempNumber[count] = '\0';

	int result = atoi(tempNumber);

	return result;
}

void getCurrentNumber(int* currentNumber, int length, int option) {
	// Option 0: Default, 1: Secret

	int count = 0;

	while (1) {
		int check = 0;
		char temp = _getch();
		if (temp >= 48 && temp <= 57) {
			for (int i = 0; i < count; i++) {
				if (toInt(temp) == currentNumber[i]) {
					check = 1;
					break;
				}
			}
		}
		else {
			check = 1;
		}
		if (count >= length)
			check = 1;
		if (temp == 8 && count > 0) {
			printf("\b \b");
			count--;
		}
		if (temp == 13 && count == length) {
			printf("\n");
			break;
		}
		if (check == 0) {
			currentNumber[count] = toInt(temp);
			if (option == 1) {
				printf("*");
			}
			else {
				printf("%d", currentNumber[count]);
			}
			count++;
		}
	}
}

struct resultData checkData(int* currentNumber, int* baseballNumber, int length) {
	struct resultData checkedData = { 0, 0, 0 };

	for (int i = 0; i < length; i++) {
		if (baseballNumber[i] == currentNumber[i]) {
			checkedData.strike += 1;
		}
		else {
			for (int j = 0; j < length; j++) {
				if (baseballNumber[j] == currentNumber[i])
					checkedData.ball += 1;
			}
		}
	}
	if (checkedData.strike == 0 && checkedData.ball == 0)
		checkedData.out = 1;

	return checkedData;
}

void storeData(struct rememberedData *storedData, int *currentNumber, int baseballLength, struct resultData currentData, int tryCount) {
	if (tryCount <= 30) {
		storedData[tryCount - 1].resultData = currentData;
		for (int i = 0; i < baseballLength; i++) {
			storedData[tryCount - 1].baseballNumber[i] = currentNumber[i];
		}
	}
	else {
		for (int i = 0; i < 29; i++) {
			storedData[i] = storedData[i + 1];
		}
		storedData[29].resultData = currentData;
		for (int i = 0; i < baseballLength; i++) {
			storedData[29].baseballNumber[i] = currentNumber[i];
		}
	}
}

void printRememberedData(struct rememberedData *storedData, int baseballLength, int tryCount, int player) {
	cursorView(0);
	for (int i = 0; i < (tryCount <= 30 ? tryCount : 30); i++) {
		removeArea(player == 1 ? 1 : 172, player == 1 ? 29 : 200, 6 + i, 6 + i);
		setCurser(player == 1 ? 1 : 172, 6 + i);
		for (int j = 0; j < baseballLength; j++) {
			printf("%d", storedData[i].baseballNumber[j]);
		}
		setCurser(player == 1 ? 20 : 190, 6 + i);
		if (storedData[i].resultData.out == 1) {
			printf("OUT");
		}
		else if (storedData[i].resultData.strike == baseballLength) {
			printf("WIN");
		}
		else {
			printf("%dS %dB", storedData[i].resultData.strike, storedData[i].resultData.ball);
		}
	}
	cursorView(1);
}

void printResult(int strike, int ball, int out, int length) {
	if (strike == length) {
		// PRINT WIN
	}
	else if (out == 1) {
		printLargeNumber('O', 1);
	}
	else {
		strike = toChar(strike);
		ball = toChar(ball);

		printLargeNumber(strike, 1);
		Sleep(200);
		printLargeNumber('S', 2);
		Sleep(200);
		printLargeNumber(ball, 3);
		Sleep(200);
		printLargeNumber('B', 4);
	}
}

int baseballNumberFilter(int* baseballNumber, int baseballLength) {
	for (int i = 0; i < baseballLength - 1; i++) {
		for (int j = i + 1; j < baseballLength; j++) {
			if (baseballNumber[i] == baseballNumber[j]) {
				return FALSE;
			}
		}
	}
	return TRUE;
}

int compareResultData(struct resultData A, struct resultData B) {
	if (A.strike == B.strike && A.ball == B.ball && A.out == B.out) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int toggleTurn(int turn) {
	if (turn == 1) {
		return 2;
	}
	else {
		return 1;
	}
}


// Char <=> Int
int toInt(char character) {
	switch (character) {
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case '0': return 0;
	}
}

char toChar(int integer) {
	switch (integer) {
	case 1: return '1';
	case 2: return '2';
	case 3: return '3';
	case 4: return '4';
	case 5: return '5';
	case 6: return '6';
	case 7: return '7';
	case 8: return '8';
	case 9: return '9';
	case 0: return '0';
	}
}


// Array
int checkNumberInArray(int number, int* arr, int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		if (number == arr[i]) return TRUE;
	}
	return FALSE;
}

void copyIntArray(int* copiedArray, int copiedArraySize, int* resultArray, int resultArraySize) {
	// Initailize
	for (int i = 0; i < resultArraySize; i++) {
		resultArray[i] = 0;
	}

	// Copy
	for (int i = 0; i < copiedArraySize; i++) {
		resultArray[i] = copiedArray[i];
	}
}