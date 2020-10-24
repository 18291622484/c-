#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void compare(int a, int b, int c) {
    for (int i = 0; i < 3; i++) {
        int t = 0;
        if (a < b) {
            t = a; a = b; b = t;
        }
        else if (b < c) {
            t = b; b = c; c = t;
        }
        else if (a < c) {
            t = a; a = c; c = t;
        }
    }
    printf("%d %d %d\n", a, b, c);
}
int main() {
    int x = 0;
    int y = 0;
    int z = 0;
    printf("请输入三个数\n");
    scanf("%d %d %d", &x, &y, &z);
    compare(x, y, z);
    return 0;
}