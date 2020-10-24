#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
    int a = 0;
    int b = 0;
    int t = 0;
    int yushu = 1;
    if (a < b) {
        t = a; a = b; b = t;
    }
    printf("请输入两个数\n");
    scanf("%d %d", &a, &b);
    while (yushu != 0) {
        if (a % b != 0) {
            yushu = a % b;
            a = b;
            b = yushu;
        }
        else {
            printf("最大公约数为：%d\n", b);
            break;
        }
    }
    return 0;
}