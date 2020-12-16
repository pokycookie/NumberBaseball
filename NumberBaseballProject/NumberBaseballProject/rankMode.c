#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "structure.h"
#include "declareFunction.h"
#include "define.h"

void rankMode(char* ID, struct rank rank) {
	FILE* RankDB = NULL;

	system("cls");
	cursorView(FALSE);

	setRankDB(RankDB, rank);
	updateRankDB(RankDB, ID, rank);

	printRankBoard(RankDB, rank);

	printOkButton(90, 40);
	selectColumnMenu(90, 40, 1);
}