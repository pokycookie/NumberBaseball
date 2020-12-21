#include <stdio.h>
#include <Windows.h>
#include "structure.h"
#include "declareFunction.h"
#include "define.h"

void multiRankMode(char* ID1, char* ID2, char* winner,struct rank rank) {
	FILE* RankDB = NULL;

	system("cls");
	cursorView(FALSE);

	setRankDB(RankDB, rank);

	updateMulitRankDB(RankDB, ID1, ID2, winner, rank);

	printRankBoardForm(rank.mode, rank.baseballLength, rank.aiDifficulty);
	printRankBoard(RankDB, ID1, rank, TRUE);
	printMyRanking(RankDB, ID1, rank);

	
	setColor(12, 15);
	setCurser(20, 33);
	printf("※비로그인 상태이거나 게임에서 패배시 랭킹이 저장되지 않습니다.");
	setColor(0, 15);

	Sleep(500);
	printOkButton(MENUX - 2, MENUY);
	selectColumnMenu(MENUX - 2, MENUY, 1);
}