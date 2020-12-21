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
		printf("��");
		setCurser(5 + i, 45);
		printf("��");
	}

	printOkButton(MENUX - 2, MENUY + 2);
	setCurser(5, 47); printf("������");
	setCurser(169, 47); printf("������");

	while (TRUE) {
		if (change) {
			removeOneLine(1);
			removeArea(0, 180, 3, 44);
			switch (page) {
			case 1:
				setCurser(5, 1);
				printf("[�⺻���� ���۹�]");

				setCurser(8, 4);
				printf("[�޴� ����]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 6);
				printf("��� �޴��� ȭ��ǥ�� �̿��� �̵��� �� �ֽ��ϴ�.");
				setCurser(8, 7);
				printf("���ϴ� �޴��� �����ϱ� ���ؼ��� ENTER�� SPACE BAR�� ����ϸ� �˴ϴ�.");
				setCurser(8, 8);
				printf("���ھ߱� ���� ���� �����ϰ� �ʹٸ�, ESC�� ����Ͽ� ���� �� �޴��� �̿��Ͻø� �˴ϴ�.");

				setCurser(8, 12);
				printf("[�α���]");
				setCurser(7, 13);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 14);
				printf("�� ������ ��α��� ���·ε� �÷��̰� ����������, ������ �α����� �ϴ°��� ��õ�մϴ�.");
				setCurser(8, 15);
				printf("�α��� ��, ���� �� �ڽ��� ID�� �г������� ����� �� ������, �ڽ��� ����� ���ӻ� ���� �� �ֽ��ϴ�.");
				setCurser(8, 16);
				printf("��α��� ��, �ش� ��ŷ����� ����� �� �����ϴ�.");

				setCurser(8, 20);
				printf("[ȸ������]");
				setCurser(7, 21);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 22);
				printf("���̵� ������ �е鲲���� ȸ������ �޴��� ���� ���� ȸ�������� �� �� �ֽ��ϴ�.");
				setCurser(8, 23);
				printf("���̵�� ���ڿ� �����ڸ��� �̿��� �ִ� 10�ڸ� �������� ����� �� ������, �ٸ� ����� �ߺ����� �ʾƾ� �մϴ�.");
				setCurser(8, 24);
				printf("��й�ȣ�� �����ڿ� ���� �׸��� (_, @, !, -, #, $, %%, &)�� Ư����ȣ�� �̿��� ������ �� �ֽ��ϴ�.");

				break;
			case 2:
				setCurser(5, 1);
				printf("[���ھ߱� ���ӹ��]");

				setCurser(8, 4);
				printf("[������ ��ǥ]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 6);
				printf("���ھ߱� ������ ������ �ڸ�����ŭ�� ������ ���������� ���� ���Ͽ�, ����� ���������� ���� �˾Ƴ��°��� ������ �����Դϴ�.");
				setCurser(8, 7);
				printf("������ ������ ������� �����ϵ� ���� ��ġ�� ���� �־�� �ȵǸ�, �� ���ӿ��� 0�� ���� ó���� �� �� �ֽ��ϴ�.");
				setCurser(8, 8);
				printf("�÷��̾�� ���� ����� ���� �����Ͽ�, ���������� ���� ��뿡�� ������ ���� �� �ֽ��ϴ�.");
				setCurser(8, 9);
				printf("������ ���� �÷��̾�� ��뿡�� �ڽ��� �������հ� ���ݹ��� ���������� ���Ͽ� ��Ʈ�� �˷��־�� �մϴ�.");

				setCurser(8, 13);
				printf("[���ھ߱� ��Ʈ]");
				setCurser(7, 14);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 15);
				printf("���ھ߱��� ��Ʈ�� �߱��� ����ϰ� STRIKE, BALL, OUT���� �����ϴ�.");
				setCurser(8, 16);
				printf("�ش� ��Ʈ�� ��밡 ������ �������հ� �ڽ��� ���������� �ڸ������� ���Ͽ� �����˴ϴ�.");
				setCurser(8, 17);
				printf("STRIKE�� ������ ������ �� �ڸ����� ��� ��ġ�Ҷ� �Դϴ�.");
				setCurser(8, 18);
				printf("BALL�� ������ ������ ������ �� �ڸ����� Ʋ���� �Դϴ�.");
				setCurser(8, 19);
				printf("OUT�� ������ ������ �ϳ��� ���� ������ �Դϴ�.");

				setCurser(8, 23);
				printf("[���� ����]");
				setCurser(7, 24);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 25);
				printf("�ڽ��� ���� 159�϶�, ��밡 019��� �����ߴٰ� �����սô�.");
				setCurser(8, 26);
				printf("�̶� ��뿡�� �˷�����ϴ� ��Ʈ�� 1STRIKE 1BALL �Դϴ�.");
				setCurser(8, 27);
				printf("����� 0�� �ڽ��� �������տ� �����Ƿ� �Ű澲�� �ʽ��ϴ�.");
				setCurser(8, 28);
				printf("����� 1�� �ڽ��� �������տ� �ִ� ��������, �� ��ġ�� Ʋ���Ƿ� BALL �Դϴ�.");
				setCurser(8, 29);
				printf("����� 9�� �ڽ��� �������տ� �ִ� ���̸鼭, �� ��ġ�� �����޷� STRIKE �Դϴ�.");

				setCurser(8, 33);
				printf("[���� ���õ�]");
				setCurser(7, 34);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 35);
				printf("1234�� ��뿡�� 1324�� ����: 2S 2B");
				setCurser(8, 36);
				printf("7634�� ��뿡�� 1205�� ����: OUT");
				setCurser(8, 37);
				printf("3745�� ��뿡�� 5437�� ����: 0S 4B");
				setCurser(8, 38);
				printf("1734�� ��뿡�� 1045�� ����: 1S 1B");

				break;
			case 3:
				setCurser(5, 1);
				printf("[���� ��� �Ұ�]");

				setCurser(8, 4);
				printf("[SINGLE MODE]");
				setCurser(7, 5);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 6);
				printf("ȥ�ڼ� ������ �� �ִ� ����Դϴ�.");
				setCurser(8, 7);
				printf("���ϴ� �ڸ����� ������ �� ������ �����ϸ�, ��ǻ�Ͱ� �ش� �ڸ�����ŭ�� ������ ���������� ����� �ݴϴ�.");
				setCurser(8, 8);
				printf("��ǻ���� ���������� �����Ͽ� ������ Ŭ�����ϴ°��� ��ǥ�Դϴ�.");
				setCurser(8, 9);
				printf("�ش� ����� ��ŷ�� �õ�Ƚ���� �������� �����ǿ� ��ġ�ϰ� �Ǹ�, �õ�Ƚ���� ������� �¸��ð��� ���� �ɸ����� �����ǿ� ��ġ�ϰ� �˴ϴ�.");

				setCurser(8, 13);
				printf("[MULTI MODE]");
				setCurser(7, 14);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 15);
				printf("ģ���� ������ �� �ִ� ����Դϴ�. �� ���� �ݵ�� �α����� �ʿ��ϸ�, �����ϴ� ��뵵 �α����� �ʿ��մϴ�.");
				setCurser(8, 16);
				printf("������ ������ ���� ��, ������ ���������� �����Ͽ� ���� ���ߴ� ���� �¸��մϴ�.");

				setCurser(8, 20);
				printf("[AI MODE]");
				setCurser(7, 21);
				for (int i = 0; i < 140; i++) {
					printf("��");
				}
				setCurser(8, 22);
				printf("AI�� ������ �� �ִ� ����Դϴ�.");
				setCurser(8, 23);
				printf("�������� ������ AI�� ���������� �����Ͽ� AI���� ���� ���߾�� �¸��մϴ�.");
				setCurser(8, 24);
				printf("�¸��� ��쿡�� ��ŷ�� ��ϵ� �� ������, SINGLE ���� ������ �������� ������ �����˴ϴ�.");
				setCurser(8, 25);
				printf("�ش� ����� AI���̵��� EASY, NORMAL, HARD�� ������, ���̵��� �ſ� �����ϴ�.");

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