#include<stdio.h>
#include<stdlib.h>

int compare(int a, int b) {
    if (a >= b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {

    int x = 0;
    int y = 0;

    printf("������������\n");

    scanf_s("%d %d", &x, &y);

    printf("�����Ϊ%d\n", compare(x, y));

    return 0;

}