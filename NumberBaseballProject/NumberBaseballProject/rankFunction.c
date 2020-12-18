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
// [FILE CONTENTS]
// <ID> <tryCount> <recordTime> <realTime>
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
			break;
		}
	}
	_fcloseall();
}

void sortRankDB(FILE* RankDB, struct rank rank) {
	int count = 0;
	char fileName[25];
	static struct rankDB tempRank[10000];
	struct rankDB temp;
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);
	
	// store in tempRank
	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			if (feof(RankDB) || count > 10000) break;
			fscanf_s(RankDB, "%s %d %d %d %d %d %d %d %d %d",
				tempRank[count].ID, sizeof(tempRank[count].ID), &tempRank[count].tryCount,
				&tempRank[count].recordMin, &tempRank[count].recordSec,
				&tempRank[count].realYear, &tempRank[count].realMonth, &tempRank[count].realDate, &tempRank[count].realHour, &tempRank[count].realMin, &tempRank[count].realSec
			);
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
		}
	}

	// Update DB
	if (fopen_s(&RankDB, fileName, "w") == 0) {
		for (int i = 0; i < count; i++) {
			fprintf(RankDB, "%s %d %d %d %d %d %d %d %d %d\n",
				tempRank[i].ID, tempRank[i].tryCount,
				tempRank[i].recordMin, tempRank[i].recordSec,
				tempRank[i].realYear, tempRank[i].realMonth, tempRank[i].realDate, tempRank[i].realHour, tempRank[i].realMin, tempRank[i].realSec
			);
		}
	}
	_fcloseall();
}

void updateRankDB(FILE* RankDB, char* ID, struct rank rank) {
	char fileName[25];
	struct fileName file = getFileName(rank);

	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "a") == 0) {
		fprintf(RankDB, "%s %d %d %d %d %d %d %d %d %d\n",
			ID, rank.tryCount, rank.recordTime.minute, rank.recordTime.second,
			rank.realTime.tm_year + 1900, rank.realTime.tm_mon + 1, rank.realTime.tm_mday,
			rank.realTime.tm_hour, rank.realTime.tm_min, rank.realTime.tm_sec);
	}
	_fcloseall();
	sortRankDB(RankDB, rank);
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
			fscanf_s(RankDB, "%s %d %d %d %d %d %d %d %d %d",
				tempRankDB[count].ID, sizeof(tempRankDB[count].ID), &tempRankDB[count].tryCount,
				&tempRankDB[count].recordMin, &tempRankDB[count].recordSec,
				&tempRankDB[count].realYear, &tempRankDB[count].realMonth, &tempRankDB[count].realDate, &tempRankDB[count].realHour, &tempRankDB[count].realMin, &tempRankDB[count].realSec
			);
			count++;
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
			fscanf_s(RankDB, "%s %d %d %d %d %d %d %d %d %d",
				tempRankDB.ID, sizeof(tempRankDB.ID), &tempRankDB.tryCount,
				&tempRankDB.recordMin, &tempRankDB.recordSec,
				&tempRankDB.realYear, &tempRankDB.realMonth, &tempRankDB.realDate, &tempRankDB.realHour, &tempRankDB.realMin, &tempRankDB.realSec
			);
			if (compareRankDBAndRank(tempRankDB, rank, ID)) {
				tempRankDB.ranking = count;
				return tempRankDB;
			}
			count++;
		}
	}
	_fcloseall();
}

void printMyRanking(FILE* RankDB, char* ID, struct rank rank) {
	struct rankDB myRank = findRankDB(RankDB, ID, rank);

	setColor(10, 15);

	setCurser(23, 33);
	printf("%2d", myRank.ranking);

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