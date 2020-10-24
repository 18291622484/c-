#include<stdio.h>
#include<stdlib.h>

int main() {
    for (int i = 100; i <= 200; i++) {
        int n = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                n++;
                break;
            }
        }
        if (n == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}