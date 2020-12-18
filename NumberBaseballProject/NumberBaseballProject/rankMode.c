#include <stdio.h>
#include <Windows.h>
#include "structure.h"
#include "declareFunction.h"
#include "define.h"

void rankMode(char* ID, int isLogin, struct rank rank) {
	FILE* RankDB = NULL;

	system("cls");
	cursorView(FALSE);

	setRankDB(RankDB, rank);

	if (isLogin) updateRankDB(RankDB, ID, rank);

	printRankBoardForm(rank.mode, rank.baseballLength, rank.aiDifficulty);
	printRankBoard(RankDB, ID, rank, isLogin);
	if (isLogin) printMyRanking(RankDB, ID, rank);
	
	Sleep(500);
	printOkButton(MENUX, MENUY);
	selectColumnMenu(MENUX, MENUY, 1);
}