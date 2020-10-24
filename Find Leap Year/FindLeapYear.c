#include<stdio.h>
#include<stdlib.h>

int main() {
    for (int year = 1000; year <= 2000; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            printf("%d ", year);
        }
    }
    return 0;
}