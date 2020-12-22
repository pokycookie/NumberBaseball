#include <stdio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void mainMenuMode(char *ID, int isLogin) {
	int END1 = FALSE;
	int END2 = FALSE;
	int baseballLength;
	int aiDifficulty;

	while (TRUE) {
		system("cls");
		printMode();
		printMainLogo(0, 0);
		switch (selectColumnMenu(MENUX, MENUY, 4)) {
		case 1: 
			while (TRUE) {
				system("cls");
				printGameMode();
				switch (selectGameMode()) {
				case 1: setGameOptionMode(SINGLEMODE, ID, isLogin); break;
				case 2: setGameOptionMode(MULTIMODE, ID, isLogin); break;
				case 3: setGameOptionMode(AIMODE, ID, isLogin); break;
				case 4: END2 = TRUE; break;
				}
				if (END2) break;
			}
			break;
		case 2:
			while (TRUE) {
				system("cls");
				printRecordMode();
				switch (selectGameMode()) {
				case 1:
					setCurser(22, 39);
					printf("확인할 자릿수를 설정하세요: ");
					cursorView(TRUE);
					baseballLength = getBaseballLength();
					cursorView(FALSE);
					recordMode(ID, isLogin, SINGLEMODE, baseballLength, FALSE);
					break;
				case 2:
					setCurser(77, 39);
					printf("확인할 자릿수를 설정하세요: ");
					cursorView(TRUE);
					baseballLength = getBaseballLength();
					cursorView(FALSE);
					recordMode(ID, isLogin, MULTIMODE, baseballLength, FALSE);
					break;
				case 3:
					setCurser(132, 39);
					printf("확인할 자릿수를 설정하세요: ");
					cursorView(TRUE);
					baseballLength = getBaseballLength();
					removeArea(131, 164, 39, 39);
					setCurser(132, 38);
					printf("확인할 AI 난이도를 설정하세요");
					aiDifficulty = selectAiDifficulty(FALSE);
					recordMode(ID, isLogin, AIMODE, baseballLength, aiDifficulty);
					cursorView(FALSE);
					break;
				case 4: END2 = TRUE; break;
				}
				if (END2) break;
				}
			break;
		case 3: helpMode(); break;
		case 4: END1 = TRUE; break;
		}
		if(END1) break;
	}
}