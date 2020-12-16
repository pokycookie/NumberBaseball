#include <stdio.h>
#include <conio.h>
#include <string.h>
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
	struct fileName file;
	char fileName[25];

	file = getFileName(rank);
	strcpy_s(fileName, sizeof(fileName), file.fileName);

	// Set Rank DB

	while (TRUE) {
		if (fopen_s(&RankDB, fileName, "r") == 0) {
			fclose(RankDB);
			break;
		}
		else {
			fopen_s(&RankDB, fileName, "w");
			fclose(RankDB);
			break;
		}
	}

}

void sortRankDB(FILE* RankDB, struct rank rank) {
	int count = 0;
	char fileName[25];
	static struct rankDB tempRank[10000];
	struct rankDB temp;
	struct fileName file;

	file = getFileName(rank);
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
		fclose(RankDB);
	}

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
		fclose(RankDB);
	}
}

void updateRankDB(FILE* RankDB, char* ID, struct rank rank) {
	char fileName[25];
	struct fileName file;

	file = getFileName(rank);
	strcpy_s(fileName, sizeof(fileName), file.fileName);

	if (fopen_s(&RankDB, fileName, "a") == 0) {
		fprintf(RankDB, "%s %d %d %d %d %d %d %d %d %d\n",
			ID, rank.tryCount, rank.recordTime.minute, rank.recordTime.second,
			rank.realTime.tm_year + 1900, rank.realTime.tm_mon + 1, rank.realTime.tm_mday,
			rank.realTime.tm_hour, rank.realTime.tm_min, rank.realTime.tm_sec);
		fclose(RankDB);
	}
	sortRankDB(RankDB, rank);
}

void printRankBoard(FILE* RankDB, struct rank rank) {
	char fileName[25];
	struct rankDB tempRankDB[10];
	struct fileName file;

	file = getFileName(rank);
	strcpy_s(fileName, sizeof(fileName), file.fileName);

	int count = 0;
	if (fopen_s(&RankDB, fileName, "r") == 0) {
		while (TRUE) {
			if (feof(RankDB)) break;
			fscanf_s(RankDB, "%s %d %d %d %d %d %d %d %d %d",
				tempRankDB[count].ID, sizeof(tempRankDB[count].ID), &tempRankDB[count].tryCount,
				&tempRankDB[count].recordMin, &tempRankDB[count].recordSec,
				&tempRankDB[count].realYear, &tempRankDB[count].realMonth, &tempRankDB[count].realDate, &tempRankDB[count].realHour, &tempRankDB[count].realMin, &tempRankDB[count].realSec
			);
			count++;
		}
		fclose(RankDB);
	}

	for (int i = 0; i < count - 1; i++) {
		setCurser(70, 10 + i);
		printf("ID: %s", tempRankDB[i].ID);
		setCurser(90, 10 + i);
		printf("Try Count: %d", tempRankDB[i].tryCount);
		setCurser(110, 10 + i);
		printf("%dºÐ %dÃÊ", tempRankDB[i].recordMin, tempRankDB[i].recordSec);
		setCurser(130, 10 + i);
		printf("%d/%d/%d %d:%d", tempRankDB[i].realYear, tempRankDB[i].realMonth, tempRankDB[i].realDate, tempRankDB[i].realHour, tempRankDB[i].realMin);
	}
}