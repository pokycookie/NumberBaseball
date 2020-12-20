#include <stdio.h>
#include <Windows.h>
#include "structure.h"
#include "declareFunction.h"
#include "define.h"

void recordMode(char* ID, int isLogin, int gameMode, int baseballLength, int aiDifficulty) {
	FILE* RankDB = NULL;
	struct rank rank;
	rank.baseballLength = baseballLength; rank.aiDifficulty = aiDifficulty; rank.mode = gameMode;

	system("cls");
	cursorView(FALSE);
	printRankBoardForm(rank.mode, rank.baseballLength, rank.aiDifficulty);

	if (isLogin) {
		setRankDB(RankDB, rank);
		findRankDBByID(RankDB, ID, rank);
	}

	if (!isLogin) {
		setColor(12, 15);
		setCurser(20, 33);
		printf("※비로그인 상태에서는 랭킹을 확인할 수 없습니다.");
		setColor(0, 15);
	}

	Sleep(500);
	printOkButton(MENUX - 2, MENUY);
	selectColumnMenu(MENUX - 2, MENUY, 1);
}