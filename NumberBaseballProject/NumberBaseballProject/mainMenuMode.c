#include <stdio.h>
#include <Windows.h>
#include "declareMode.h"
#include "declareFunction.h"
#include "define.h"

void mainMenuMode(char *ID, int isLogin) {
	int END = FALSE;

	while (TRUE) {
	system("cls");
	printMode();
	printMainLogo(0, 0);
		switch (selectColumnMenu(MENUX, MENUY, 5)) {
		case 1: setGameOptionMode(SINGLEMODE, ID, isLogin); break;
		case 2: setGameOptionMode(MULTIMODE, ID, isLogin); break;
		case 3: setGameOptionMode(AIMODE, ID, isLogin);  break;
		case 4: printHelp(); selectColumnMenu(MENUX, MENUY, 1); break;
		case 5: END = TRUE; break;
		}
		if(END) break;
	}
}