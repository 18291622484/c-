#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//本题有很多变形，例如三个瓶子换一瓶汽水，四个瓶子换一瓶汽水等等
#define Exchange 2

int DrinkingProblem(int bottle) {
	int ret = bottle;
	while (bottle >= Exchange) {
		ret += bottle / Exchange;
		bottle = bottle / Exchange + bottle % Exchange;
	}
	return ret;
}

int main() {
	//让用户输入用多少钱来买汽水
	printf("输入钱数：");
	int money = 0;
	scanf("%d", &money);
	int ret = DrinkingProblem(money);
	printf("%d\n", ret);
	return 0;
}