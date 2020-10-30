#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//■

//定义两个数组，一个是显示的用户界面；一个是系统随机生成好的，用来进行比较的。
int arr[11][11] = { 0 };
int arr0[9][9] = { 0 };

//给arr0展示数组赋初值
void setArr0() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            arr0[i][j] = 9;
        }
    }
}

//显示用户界面
void setShow(int sign) {
    printf("■  ");
    for (int n = 1; n < 10; n++) {
        printf("%-4d", n);
    }
    int num = 10;
    if (sign == 0) {
        num--;
    }
    //用户找到十个地雷，那么就将自动翻开所有区域，若仍有地雷，则失败
    if (num == 0) {
        int bomb = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (arr0[i][j] == 10) {
                    bomb++;
                    break;
                }
            }
            break;
        }
        if (bomb == 0) {
            printf("恭喜你，成功找到全部地雷！\n");
        }
        else {
            printf("未排查完地雷了！\n");
            printf("游戏结束！\n");
        }
        exit(0);
    }
    printf("\t\t\t%d\n", num);
    for (int i = 0; i < 9; i++) {
        printf("%-4d", i + 1);
        for (int j = 0; j < 9; j++) {
            printf("%-4d", arr0[i][j]);
        }
        printf("\n");
    }
}

//用来生成坐标
int setXY() {
    int n = rand() % 9 + 1;
    return n;
}

//用随机数生成一个9*9含有10个地雷的系统数组
void setMap() {
    int n = 0;
    while (n < 10) {
        int x = setXY();
        int y = setXY();
        if (arr[x][y] == 0) {
            arr[x][y] = 10;
            n++;
        }
    }
    /*for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            printf("%-4d", arr[i][j]);
            if (j == 10) {
                printf("\n");
            }
        }
    }*/
}

//在系统给定的数组中标记数字，即每个格子周围的一圈有多少个地雷
void setSign() {
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (arr[i][j] != 10) {
                int n = 0;
                for (int a = i - 1; a <= i + 1; a++) {
                    for (int b = j - 1; b <= j + 1; b++) {
                        if (arr[a][b] == 10) {
                            n++;
                        }
                    }
                }
                arr[i][j] = n;
            }
        }
    }
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            printf("%-4d", arr[i][j]);
            if (j == 10) {
                printf("\n");
            }
        }
    }
}

//本程序中，最难的地方在于，若用户选到空白的地方，如何展示一片相连的区域，在查阅过资料之后，得到可以使用递归函数来解决
//解决方法来自于CSDN上Jether大佬的一篇博客——扫雷游戏设计原理
void accept(int x, int y) {
    if (arr[x][y] != 0) {
        return 0;
    }
    if (arr[x][y] == 0) {
        if (x == 1 && y == 1) {
            for (int i = 0; i <= 1; i++) {
                for (int j =0; j <=1; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+2);
                }
            }
        }
        else if (x == 9 && y == 9) {
            for (int i = 7; i <= 8; i++) {
                for (int j = 7; j <= 8; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        if (x == 1 && y == 9) {
            for (int i = 0; i <= 1; i++) {
                for (int j = 7; j <= 8; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else if (x == 9 && y == 1) {
            for (int i = 7; i <= 8; i++) {
                for (int j = 0; j <= 1; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else if (x == 1) {
            for (int i = 0; i <= 1; i++) {
                for (int j = y-2; j <= y; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else if (y == 1) {
            for (int i = x-2; i <= x; i++) {
                for (int j = 0; j <= 1; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else if (y == 9) {
            for (int i = x-2; i <= x; i++) {
                for (int j = 7; j <= 8; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else if(1<x<9&&1<y<9){
            for (int i = x - 2; i <= x; i++) {
                for (int j = y - 2; j <= y; j++) {
                    arr0[i][j] = arr[i + 1][j + 1];
                    //accept(i+1, j+1);
                }
            }
        }
        else {
            return 0;
        }
    }
}

//由于才疏学浅，不会使用光标，所以就只能让用户输入数组来进行游玩
void inPut() {
    while (1) {
        printf("输入坐标：");
        int x = 0;
        int y = 0;
        /*int* p = &x;
        int* q = &y;*/
        int z = 0;
        scanf("%d %d %d", &x, &y, &z);
        if (z == 11) {
            arr0[x - 1][y - 1] = 11;
            system("cls");
            setShow(0);
        }
        else {
            if (arr[x][y] == 10) {
                printf("踩到地雷了！\n");
                printf("游戏结束！\n");
                break;
            }
            else if ((arr[x][y] != 10) && (arr[x][y] != 0)) {
                arr0[x - 1][y - 1] = arr[x][y];
                system("cls");
                setShow(1);
            }
            else {
                accept(x, y);
                system("cls");
                setShow(1);
            }
        }
    }
}

int main() {
    srand(time(0));
    setArr0();
    setShow(1);
    setMap();
    setSign();
    inPut();
    return 0;
}
