#include <stdio.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void setGameOptionMode(int gameMode, char* ID, int isLogin) {
	int baseballLength;
	int END = FALSE;

	printBaseballLength();
	switch (selectColumnMenu(MENUX, MENUY, 5)) {
	case 1: baseballLength = 3; break;
	case 2: baseballLength = 4; break;
	case 3: baseballLength = 5; break;
	case 4:
		printFreeBaseballSetting();
		switch (selectColumnMenu(MENUX, MENUY, 2)) {
		case 1:
			cursorView(1);
			baseballLength = getBaseballLength();
			break;
		case 2:
			break;
		}
		break;
	case 5:
		END = TRUE;
		break;
	}

	if (!END) {
		switch (gameMode) {
		case SINGLEMODE: practiceMode(ID, isLogin, baseballLength); break;
		case MULTIMODE: multiMode(baseballLength); break;
		case AIMODE: AiMode(ID, isLogin, baseballLength); break;
		}
	}
}