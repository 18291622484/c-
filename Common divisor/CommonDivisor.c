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
    printf("������������\n");
    scanf("%d %d", &a, &b);
    while (yushu != 0) {
        if (a % b != 0) {
            yushu = a % b;
            a = b;
            b = yushu;
        }
        else {
            printf("���Լ��Ϊ��%d\n", b);
            break;
        }
    }
    return 0;
}