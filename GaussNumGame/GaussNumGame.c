#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<windows.h>



int menu() {

	printf("********************\n");

	printf("*****1.开始游戏*****\n");

	printf("********************\n");

	printf("*****0.退出游戏*****\n");

	printf("********************\n");

	printf("请输入你的选择:");

	int choose = 0;

	scanf("%d", &choose);

	return choose;

}



void game() {

	srand(time(0));

	int randNum = rand() % 100 + 1;

	while (1) {

		printf("请输入一个数（1-100）：\n");

		int num = 0;

		scanf("%d", &num);

		if (num == randNum) {

			printf("恭喜你，猜对了！\n");

			Sleep(3000);

			break;

		}

		else if (num < randNum) {

			printf("猜低了！\n");

		}

		else if (num > randNum) {

			printf("猜高了！\n");

		}

	}

}



int again() {

	system("cls");

	printf("是否继续游玩？请选择：\n");

	printf("1——是\n2——否\n");

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

					printf("输入有误！请重输：\n");

					Sleep(1000);

					continue;
				}
			}
		}
		else if (choose == 0) {
		_1:
			printf("游戏结束！\n");
			break;
		}
		else {
			system("cls");
			printf("输入有误，请重输！\n");
			Sleep(1000);
		}
	}
	return 0;
}