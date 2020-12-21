#include <stdio.h>
#include <Windows.h>
#include "declareFunction.h"
#include "define.h"

void helpMode(void) {
	int temp;
	int page = 1;
	int change = TRUE;

	system("cls");
	for (int i = 0; i < 170; i++) {
		setCurser(5 + i, 2);
		printf("─");
		setCurser(5 + i, 45);
		printf("─");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	setCurser(5, 47); printf("◀이전");
	setCurser(169, 47); printf("다음▶");

	while (TRUE) {
		if (change) {
			removeOneLine(1);
			removeArea(0, 180, 3, 44);
			switch (page) {
			case 1:
				setCurser(5, 1);
				printf("[기본적인 조작법]");

				setCurser(8, 4);
				printf("[메뉴 선택]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 6);
				printf("모든 메뉴는 화살표를 이용해 이동할 수 있습니다.");
				setCurser(8, 7);
				printf("원하는 메뉴를 선택하기 위해서는 ENTER나 SPACE BAR를 사용하면 됩니다.");
				setCurser(8, 8);
				printf("숫자야구 게임 도중 포기하고 싶다면, ESC를 사용하여 게임 내 메뉴를 이용하시면 됩니다.");

				setCurser(8, 12);
				printf("[로그인]");
				setCurser(7, 13);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 14);
				printf("본 게임은 비로그인 상태로도 플레이가 가능하지만, 가급적 로그인을 하는것을 추천합니다.");
				setCurser(8, 15);
				printf("로그인 시, 게임 중 자신의 ID를 닉네임으로 사용할 수 있으며, 자신의 기록을 게임상에 남길 수 있습니다.");
				setCurser(8, 16);
				printf("비로그인 시, 해당 랭킹기능은 사용할 수 없습니다.");

				setCurser(8, 20);
				printf("[회원가입]");
				setCurser(7, 21);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 22);
				printf("아이디가 없으신 분들께서는 회원가입 메뉴를 통해 쉽게 회원가입을 할 수 있습니다.");
				setCurser(8, 23);
				printf("아이디는 숫자와 영문자만을 이용한 최대 10자리 조합으로 사용할 수 있으며, 다른 사람과 중복되지 않아야 합니다.");
				setCurser(8, 24);
				printf("비밀번호는 영문자와 숫자 그리고 (_, @, !, -, #, $, %%, &)의 특수기호를 이용해 생성할 수 있습니다.");

				break;
			case 2:
				setCurser(5, 1);
				printf("[숫자야구 게임방법]");

				setCurser(8, 4);
				printf("[게임의 목표]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 6);
				printf("숫자야구 게임은 정해진 자릿수만큼의 무작위 숫자조합을 서로 정하여, 상대의 숫자조합을 먼저 알아내는것이 목적인 게임입니다.");
				setCurser(8, 7);
				printf("숫자의 조합은 마음대로 설정하되 서로 겹치는 수가 있어서는 안되며, 이 게임에서 0은 제일 처음에 올 수 있습니다.");
				setCurser(8, 8);
				printf("플레이어는 서로 상대의 수를 예상하여, 숫자조합을 정해 상대에게 공격을 가할 수 있습니다.");
				setCurser(8, 9);
				printf("공격을 받은 플레이어는 상대에게 자신의 숫자조합과 공격받은 숫자조합을 비교하여 힌트를 알려주어야 합니다.");

				setCurser(8, 13);
				printf("[숫자야구 힌트]");
				setCurser(7, 14);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 15);
				printf("숫자야구의 힌트는 야구와 비슷하게 STRIKE, BALL, OUT으로 나뉩니다.");
				setCurser(8, 16);
				printf("해당 힌트는 상대가 공격한 숫자조합과 자신의 숫자조합을 자릿수별로 비교하여 결정됩니다.");
				setCurser(8, 17);
				printf("STRIKE는 숫자의 종류와 그 자릿수가 모두 일치할때 입니다.");
				setCurser(8, 18);
				printf("BALL은 숫자의 종류는 맞지만 그 자릿수가 틀릴때 입니다.");
				setCurser(8, 19);
				printf("OUT은 숫자의 종류가 하나도 맞지 않을때 입니다.");

				setCurser(8, 23);
				printf("[실제 예시]");
				setCurser(7, 24);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 25);
				printf("자신의 수가 159일때, 상대가 019라고 공격했다고 가정합시다.");
				setCurser(8, 26);
				printf("이때 상대에게 알려줘야하는 힌트는 1STRIKE 1BALL 입니다.");
				setCurser(8, 27);
				printf("상대의 0은 자신의 숫자조합에 없으므로 신경쓰지 않습니다.");
				setCurser(8, 28);
				printf("상대의 1은 자신의 숫자조합에 있는 수이지만, 그 위치가 틀리므로 BALL 입니다.");
				setCurser(8, 29);
				printf("상대의 9는 자신의 숫자조합에 있는 수이면서, 그 위치도 맞으믜로 STRIKE 입니다.");

				setCurser(8, 33);
				printf("[여러 예시들]");
				setCurser(7, 34);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 35);
				printf("1234인 상대에게 1324로 공격: 2S 2B");
				setCurser(8, 36);
				printf("7634인 상대에게 1205로 공격: OUT");
				setCurser(8, 37);
				printf("3745인 상대에게 5437로 공격: 0S 4B");
				setCurser(8, 38);
				printf("1734인 상대에게 1045로 공격: 1S 1B");

				break;
			case 3:
				setCurser(5, 1);
				printf("[게임 모드 소개]");

				setCurser(8, 4);
				printf("[SINGLE MODE]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 6);
				printf("혼자서 연습할 수 있는 모드입니다.");
				setCurser(8, 7);
				printf("원하는 자릿수를 선택한 후 게임을 시작하면, 컴퓨터가 해당 자릿수만큼의 랜덤한 숫자조합을 만들어 줍니다.");
				setCurser(8, 8);
				printf("컴퓨터의 숫자조합을 유추하여 게임을 클리어하는것이 목표입니다.");
				setCurser(8, 9);
				printf("해당 모드의 랭킹은 시도횟수가 적을수록 상위권에 위치하게 되며, 시도횟수가 같을경우 승리시간이 적게 걸릴수록 상위권에 위치하게 됩니다.");

				setCurser(8, 13);
				printf("[MULTI MODE]");
				setCurser(7, 14);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 15);
				printf("친구와 대전할 수 있는 모드입니다. 본 모드는 반드시 로그인이 필요하며, 대전하는 상대도 로그인이 필요합니다.");
				setCurser(8, 16);
				printf("서로의 조합을 정한 뒤, 서로의 숫자조합을 예측하여 먼저 맞추는 쪽이 승리합니다.");

				setCurser(8, 20);
				printf("[AI MODE]");
				setCurser(7, 21);
				for (int i = 0; i < 140; i++) {
					printf("─");
				}
				setCurser(8, 22);
				printf("AI와 대전할 수 있는 모드입니다.");
				setCurser(8, 23);
				printf("랜덤으로 정해진 AI의 숫자조합을 예측하여 AI보다 먼저 맞추어야 승리합니다.");
				setCurser(8, 24);
				printf("승리할 경우에만 랭킹에 등록될 수 있으며, SINGLE 모드와 동일한 조건으로 순위가 결정됩니다.");
				setCurser(8, 25);
				printf("해당 모드의 AI난이도는 EASY, NORMAL, HARD가 있으며, 난이도가 매우 높습니다.");

				break;
			}
		}
		change = FALSE;

		temp = arrowControl();
		if (temp == LEFT && page > 1) {
			page--;
			change = TRUE;
		}
		else if (temp == RIGHT && page < 3) {
			page++;
			change = TRUE;
		}
		else if (temp == 0) {
			break;
		}
	}
}