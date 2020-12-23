#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include "declareFunction.h"
#include "structure.h"
#include "define.h"

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
// RANK DB
//
// [FILE NAME]
// RankDB_<Mode><Baseball Length>[AI Difficulty]
// mode: Single, Multi, AI
//
// [FILE CONTENTS] - Single, Ai
// <Rank> <ID> <tryCount> <recordTime> <realTime>
//
// [FILE CONTENTS] - Multi
// <player1 ID> <player2 ID> <winner ID> <recordTime> <realTime>
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

struct fileName getFileName(struct rank rank) {
	char baseballLength[2];
	char fileName[25];

	// Set Baseball Length
	if (rank.baseballLength < 10) {
		baseballLength[0] = '0';
		baseballLength[1] = toChar(rank.baseballLength);
	}
	else {
		baseballLength[0] = '1';
		baseballLength[1] = '0';
	}

	// Set File Name
	switch (rank.mode)
	{
	case 1:
		sprintf_s(fileName, sizeof(fileName), "RankDB_Single%c%c.dat", baseballLength[0], baseballLength[1]);
		break;
	case 2:
		sprintf_s(fileName, sizeof(fileName), "RankDB_Multi%c%c.dat", baseballLength[0], baseballLength[1]);
		break;
	case 3:
		sprintf_s(fileName, sizeof(fileName), "RankDB_AI%c%c%c.dat", baseballLength[0], baseballLength[1], toChar(rank.aiDifficulty));
		break;
	default:
		break;
	}

	struct fileName file;
	strcpy_s(file.fileName, sizeof(file.fileName), fileName);
	return file;
}

void setRankDB(FILE* RankDB, struct rank rank) {
	char fileName[25];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	// Set Rank DB

	while (TRUE) {
		if (fopen_s(&RankDB, fileName, "r") == 0) {
			break;
		}
		else {
			fopen_s(&RankDB, fileName, "w");
			if (rank.mode != MULTIMODE) {
				fprintf(RankDB, "%d %s %d %d %d %d %d %d %d %d %d\n", 0, "SYSTEM", 0, 0, 0, 0, 0, 0, 0, 0, 0);
			}
			else {
				fprintf(RankDB, "%s %s %s %d %d %d %d %d %d %d %d\n", "SYSTEM", "SYSTEM", "SYSTEM", 0, 0, 0, 0, 0, 0, 0, 0);
			}
			break;
		}
	}
	_fcloseall();
}

void sortRankDB(FILE* RankDB, struct rank rank) {
	int count = 0;
	char fileName[25];
	struct rankDB tempRank[100];
	struct rankDB temp;
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);
	
	// store in tempRank
	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			if (feof(RankDB) || count > 10000) break;
			fscanf_s(RankDB, "%d %s %d %d %d %d %d %d %d %d %d",
				&tempRank[count].ranking, tempRank[count].ID, sizeof(tempRank[count].ID), &tempRank[count].tryCount,
				&tempRank[count].recordMin, &tempRank[count].recordSec,
				&tempRank[count].realYear, &tempRank[count].realMonth, &tempRank[count].realDate, &tempRank[count].realHour, &tempRank[count].realMin, &tempRank[count].realSec
			);
			fflush(RankDB);
			count++;
		}
		count--;
	}
	_fcloseall();

	// Sorting
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (tempRank[i].tryCount > tempRank[j].tryCount) {
				temp = tempRank[i];
				tempRank[i] = tempRank[j];
				tempRank[j] = temp;
			}
			else if (tempRank[i].tryCount == tempRank[j].tryCount) {
				if (tempRank[i].recordMin > tempRank[j].recordMin) {
					temp = tempRank[i];
					tempRank[i] = tempRank[j];
					tempRank[j] = temp;
				}
				else if (tempRank[i].recordMin == tempRank[j].recordMin) {
					if (tempRank[i].recordSec > tempRank[j].recordSec) {
						temp = tempRank[i];
						tempRank[i] = tempRank[j];
						tempRank[j] = temp;
					}
				}
			}
		}
	}

	// Update DB
	if (fopen_s(&RankDB, fileName, "w") == 0) {
		for (int i = 0; i < count; i++) {
			fprintf(RankDB, "%d %s %d %d %d %d %d %d %d %d %d\n",
				i + 1, tempRank[i].ID, tempRank[i].tryCount,
				tempRank[i].recordMin, tempRank[i].recordSec,
				tempRank[i].realYear, tempRank[i].realMonth, tempRank[i].realDate, tempRank[i].realHour, tempRank[i].realMin, tempRank[i].realSec
			);
			fflush(RankDB);
		}
	}
	_fcloseall();
}

void updateRankDB(FILE* RankDB, char* ID, struct rank rank) {
	char fileName[25];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "a") == 0) {
		fprintf(RankDB, "%d %s %d %d %d %d %d %d %d %d %d\n",
			0, ID, rank.tryCount, rank.recordTime.minute, rank.recordTime.second,
			rank.realTime.tm_year + 1900, rank.realTime.tm_mon + 1, rank.realTime.tm_mday,
			rank.realTime.tm_hour, rank.realTime.tm_min, rank.realTime.tm_sec);
		fflush(RankDB);
	}
	_fcloseall();
	sortRankDB(RankDB, rank);
}

void updateMulitRankDB(FILE* RankDB, char* ID1, char* ID2, char* winner, struct rank rank) {
	char fileName[25];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "a") == 0) {
		fprintf(RankDB, "%s %s %s %d %d %d %d %d %d %d %d\n",
			ID1, ID2, winner, rank.recordTime.minute, rank.recordTime.second,
			rank.realTime.tm_year + 1900, rank.realTime.tm_mon + 1, rank.realTime.tm_mday,
			rank.realTime.tm_hour, rank.realTime.tm_min, rank.realTime.tm_sec);
		fflush(RankDB);
	}
	_fcloseall();
}

void printRankBoard(FILE* RankDB, char* ID, struct rank rank, int isLogin) {
	char fileName[25];
	struct rankDB tempRankDB[21];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	int count = 0;
	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			if (feof(RankDB) || count > 20) break;
			fscanf_s(RankDB, "%d %s %d %d %d %d %d %d %d %d %d",
				&tempRankDB[count].ranking, tempRankDB[count].ID, sizeof(tempRankDB[count].ID), &tempRankDB[count].tryCount,
				&tempRankDB[count].recordMin, &tempRankDB[count].recordSec,
				&tempRankDB[count].realYear, &tempRankDB[count].realMonth, &tempRankDB[count].realDate, &tempRankDB[count].realHour, &tempRankDB[count].realMin, &tempRankDB[count].realSec
			);
			fflush(RankDB);
			if (tempRankDB[count].tryCount != 0) {
				count++;
			}
		}
	}
	_fcloseall();

	for (int i = 0; i < count - 1; i++) {
		if (isLogin && compareRankDBAndRank(tempRankDB[i], rank, ID)) setColor(10, 15);

		setCurser(23, 10 + i);
		printf("%2d", i + 1);

		setCurser(30, 10 + i);
		printf("%s", tempRankDB[i].ID);
		
		setCurser(47, 10 + i);
		printf("%3d회", tempRankDB[i].tryCount);

		setCurser(61, 10 + i);
		if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec > 9) {
			printf("%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
		}
		else if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec < 10) {
			printf("%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
		}
		else if (tempRankDB[i].recordMin < 10 && tempRankDB[i].recordSec > 9) {
			printf("0%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
		}
		else {
			printf("0%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
		}
		
		setCurser(140, 10 + i);
		printf("%4d/%2d/%2d %2d:%2d", tempRankDB[i].realYear, tempRankDB[i].realMonth, tempRankDB[i].realDate, tempRankDB[i].realHour, tempRankDB[i].realMin);

		setColor(0, 15);
		Sleep(300);
	}
}

struct rankDB findRankDB(FILE* RankDB, char* ID, struct rank rank) {
	int count = 1;
	char fileName[25];
	struct rankDB tempRankDB;
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			if (feof(RankDB)) break;
			fscanf_s(RankDB, "%d %s %d %d %d %d %d %d %d %d %d",
				&tempRankDB.ranking ,tempRankDB.ID, sizeof(tempRankDB.ID), &tempRankDB.tryCount,
				&tempRankDB.recordMin, &tempRankDB.recordSec,
				&tempRankDB.realYear, &tempRankDB.realMonth, &tempRankDB.realDate, &tempRankDB.realHour, &tempRankDB.realMin, &tempRankDB.realSec
			);
			fflush(RankDB);
			if (compareRankDBAndRank(tempRankDB, rank, ID)) {
				tempRankDB.ranking = count;
				return tempRankDB;
			}
			count++;
		}
	}
	_fcloseall();
}

void findRankDBByID(FILE* RankDB, char* ID, struct rank rank) {
	int count = 0;
	char fileName[25];
	struct rankDB tempRankDB[100];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			fflush(RankDB);
			if (feof(RankDB)) break;
			if (rank.mode != MULTIMODE) {
				fscanf_s(RankDB, "%d %s %d %d %d %d %d %d %d %d %d",
					&tempRankDB[count].ranking, tempRankDB[count].ID, sizeof(tempRankDB[count].ID), &tempRankDB[count].tryCount,
					&tempRankDB[count].recordMin, &tempRankDB[count].recordSec,
					&tempRankDB[count].realYear, &tempRankDB[count].realMonth, &tempRankDB[count].realDate, &tempRankDB[count].realHour, &tempRankDB[count].realMin, &tempRankDB[count].realSec
				);
				if (strcmp(tempRankDB[count].ID, ID) == 0) {
					count++;
				}
			}
			else {
				fscanf_s(RankDB, "%s %s %s %d %d %d %d %d %d %d %d",
					tempRankDB[count].ID, sizeof(tempRankDB[count].ID), tempRankDB[count].subID, sizeof(tempRankDB[count].subID), tempRankDB[count].winner, sizeof(tempRankDB[count].winner),
					&tempRankDB[count].recordMin, &tempRankDB[count].recordSec,
					&tempRankDB[count].realYear, &tempRankDB[count].realMonth, &tempRankDB[count].realDate, &tempRankDB[count].realHour, &tempRankDB[count].realMin, &tempRankDB[count].realSec
				);
				if (strcmp(tempRankDB[count].ID, ID) == 0 || strcmp(tempRankDB[count].subID, ID) == 0) {
					count++;
				}
			}
			fflush(RankDB);
		}
	}
	_fcloseall();

	if (rank.mode != MULTIMODE) {
		for (int i = 0; i < count; i++) {
			setCurser(23, 10 + i);
			printf("%2d", tempRankDB[i].ranking);

			setCurser(30, 10 + i);
			printf("%s", tempRankDB[i].ID);

			setCurser(47, 10 + i);
			printf("%3d회", tempRankDB[i].tryCount);

			setCurser(61, 10 + i);
			if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec > 9) {
				printf("%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec < 10) {
				printf("%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else if (tempRankDB[i].recordMin < 10 && tempRankDB[i].recordSec > 9) {
				printf("0%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else {
				printf("0%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}

			setCurser(140, 10 + i);
			printf("%4d/%2d/%2d %2d:%2d", tempRankDB[i].realYear, tempRankDB[i].realMonth, tempRankDB[i].realDate, tempRankDB[i].realHour, tempRankDB[i].realMin);

			setColor(0, 15);
			Sleep(300);
		}
	}
	else {
		for (int i = 0; i < count; i++) {
			setCurser(22, 10 + i);
			printf("%s VS %s", tempRankDB[i].ID, tempRankDB[i].subID);

			setCurser(54, 10 + i);
			printf("%s", tempRankDB[i].winner);

			setCurser(72, 10 + i);
			if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec > 9) {
				printf("%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else if (tempRankDB[i].recordMin > 9 && tempRankDB[i].recordSec < 10) {
				printf("%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else if (tempRankDB[i].recordMin < 10 && tempRankDB[i].recordSec > 9) {
				printf("0%d분 %d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}
			else {
				printf("0%d분 0%d초", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
			}

			setCurser(140, 10 + i);
			printf("%4d/%2d/%2d %2d:%2d", tempRankDB[i].realYear, tempRankDB[i].realMonth, tempRankDB[i].realDate, tempRankDB[i].realHour, tempRankDB[i].realMin);

			setColor(0, 15);
			Sleep(300);
		}
	}
}

void printMyRanking(FILE* RankDB, char* ID, struct rank rank) {
	struct rankDB myRank = findRankDB(RankDB, ID, rank);

	setColor(10, 15);

	setCurser(23, 33);
	printf("%2d", myRank.ranking - 1);

	setCurser(30, 33);
	printf("%s", myRank.ID);

	setCurser(47, 33);
	printf("%3d회", myRank.tryCount);

	setCurser(61, 33);
	if (myRank.recordMin > 9 && myRank.recordSec > 9) {
		printf("%d분 %d초", myRank.recordMin, myRank.recordSec);
	}
	else if (myRank.recordMin > 9 && myRank.recordSec < 10) {
		printf("%d분 0%d초", myRank.recordMin, myRank.recordSec);
	}
	else if (myRank.recordMin < 10 && myRank.recordSec > 9) {
		printf("0%d분 %d초", myRank.recordMin, myRank.recordSec);
	}
	else {
		printf("0%d분 0%d초", myRank.recordMin, myRank.recordSec);
	}

	setCurser(140, 33);
	printf("%4d/%2d/%2d %2d:%2d", myRank.realYear, myRank.realMonth, myRank.realDate, myRank.realHour, myRank.realMin);

	setColor(0, 15);
}