#include<stdio.h>
#include<stdlib.h>

int main() {
    int num = 0;
    for (int i = 1; i <= 100; i++) {
        if (i / 10 == 9) {
            num++;
            if (i % 10 == 9) {
                num++;
            }
        }
        else if (i % 10 == 9) {
            num++;
        }
    }
    printf("一共有 %d 个9\n", num);
    return 0;
}