#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<windows.h>



int menu() {

	printf("********************\n");

	printf("*****1.��ʼ��Ϸ*****\n");

	printf("********************\n");

	printf("*****0.�˳���Ϸ*****\n");

	printf("********************\n");

	printf("���������ѡ��:");

	int choose = 0;

	scanf("%d", &choose);

	return choose;

}



void game() {

	srand(time(0));

	int randNum = rand() % 100 + 1;

	while (1) {

		printf("������һ������1-100����\n");

		int num = 0;

		scanf("%d", &num);

		if (num == randNum) {

			printf("��ϲ�㣬�¶��ˣ�\n");

			Sleep(3000);

			break;

		}

		else if (num < randNum) {

			printf("�µ��ˣ�\n");

		}

		else if (num > randNum) {

			printf("�¸��ˣ�\n");

		}

	}

}



int again() {

	system("cls");

	printf("�Ƿ�������棿��ѡ��\n");

	printf("1������\n2������\n");

	int choose = 0;

	scanf("%d", &choose);

	return choose;

}



int main() {

	while (1) {

		system("cls");

		int choose = menu();

		if (choose == 1) {

			game();

			while (1) {

				int choose1 = again();

				if (choose1 == 2) {

					goto _1;

				}

				else if (choose1 == 1) {

					break;

				}

				else {

					printf("�������������䣺\n");

					Sleep(1000);

					continue;
				}
			}
		}
		else if (choose == 0) {
		_1:
			printf("��Ϸ������\n");
			break;
		}
		else {
			system("cls");
			printf("�������������䣡\n");
			Sleep(1000);
		}
	}
	return 0;
}