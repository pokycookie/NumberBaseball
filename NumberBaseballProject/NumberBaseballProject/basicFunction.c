#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "structure.h"
#include "declareFunction.h"

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

int getBaseballLength(void) {
	int count = 0;
	char tempNumber[3];

	printf("Set Number Baseball Length: ");
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

void getCurrentNumber(int* currentNumber, int length) {
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
			printf("%d", currentNumber[count]);
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

void printResult(int strike, int ball, int out, int length) {
	if (strike == length) {
		printf("You Win\n");
	}
	else if (out == 1) {
		printf("OUT!\n");
	}
	else if (strike == 0) {
		printf("%dB\n", ball);
	}
	else if (ball == 0) {
		printf("%dS\n", strike);
	}
	else {
		printf("%dS %dB\n", strike, ball);
	}
}

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