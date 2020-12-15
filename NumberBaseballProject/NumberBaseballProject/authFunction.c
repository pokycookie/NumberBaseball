#include <stdio.h>
#include <conio.h>
#include <string.h>
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
		else if (temp == ENTER && count > 0) {
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
		else if (temp == ENTER && count > 0) {
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
		fprintf(AuthDB, "%s %s\n", ID, PW);
		fclose(AuthDB);
	}
}

int checkUsedID(FILE* AuthDB, char* ID) {
	// Return 0: Success, 1: Already Used
	char DB_ID[10];
	char DB_PW[15];
	if (fopen_s(&AuthDB, "AuthDB.dat", "r") == 0) {
		while (1) {
			if (feof(AuthDB)) break;
			fscanf_s(AuthDB, "%s %s", DB_ID, sizeof(DB_ID), DB_PW, sizeof(DB_PW));
			if (strcmp(DB_ID, ID) == 0) return 1;
		}
		fclose(AuthDB);
	}
	return 0;
}

int authenticateUser(FILE* AuthDB, char* ID, char* PW) {
	// Return 0: Auth Success, 1: Wrong PW, 2: Wrong ID

	char DB_ID[10];
	char DB_PW[15];

	if (fopen_s(&AuthDB, "AuthDB.dat", "r") == 0) {
		for (int i = 0; i < 100; i++) {
			fscanf_s(AuthDB, "%s %s", DB_ID, sizeof(DB_ID),DB_PW, sizeof(DB_PW));
			if (strcmp(ID, DB_ID) == 0) {
				if (strcmp(PW, DB_PW) == 0) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}
		fclose(AuthDB);
		return 2;
	}
}