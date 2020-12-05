#include <stdio.h>
#include <conio.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

void inputID(char *ID) {
	int count = 0;
	int temp;

	while (1) {
		temp = _getch();
		if (temp == 0 || temp == 0xE0) {
			temp = _getch();
		}
		else if (((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57)) && count < 9) {
			ID[count] = temp;
			printf("%c", temp);
			count++;
		}
		else if (temp == ENTER) {
			ID[count] = '\0';
			break;
		}
		else if (temp == BACKSPACE && count > 0) {
			printf("\b \b");
			count--;
		}
	}
}

void inputPW(char* PW) {
	int count = 0;
	int temp;

	while (1) {
		temp = _getch();
		if (temp == 0 || temp == 0xE0) {
			temp = _getch();
		}
		else if (((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57) 
				|| temp == 95 || temp == 64 || temp == 33 || temp == 45 || (temp >= 35 && temp <= 38)) && count < 14) {
			PW[count] = temp;
			printf("*");
			count++;
		}
		else if (temp == ENTER) {
			PW[count] = '\0';
			break;
		}
		else if (temp == BACKSPACE && count > 0) {
			printf("\b \b");
			count--;
		}
	}
}

void updateAuthDB(FILE *AuthDB, char *ID, char *PW) {
	if (fopen_s(&AuthDB, "AuthDB.dat", "a") == 0) {
		fprintf(AuthDB, "ID: %s - PW: %s\n", ID, PW);
		fclose(AuthDB);
	}
}