#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//随机出现2或者4
int setNum() {
    int num1 = 0;
    while (1) {
        int num = rand() % 4 + 1;
        if (num % 2 == 0) {
            num1 = num;
            break;
        }
    }
    return num1;
}

//随机生成数组的x坐标
int setX() {
    int x = rand() % 4;
    //printf("%d\n", x);
    return x;
}
//随机生成数组的y坐标
int setY() {
    int y = rand() % 4;
    //printf("%d\n", y);
    return y;
}

//定义一个数组来创建地图
int arr[4][4] = { 0 };
//定义一个数组，用来和每一次操作之后的数组比较，若无变化，不生成随机数
int arr0[4][4] = { 0 };

//比较数组，操作前与操作后是否相等，若相等，不生成随机数，若不相等，则正常进行
int compare() {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == arr0[i][j]) {
                n++;
            }
        }
    }
    return n;
}

//判断是否已填满不为零的数字
int full() {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] != 0) {
                n++;
            }
        }
    }
    return n;
}

//判断是否出现了2048数字
int isHave_2048() {
    int n = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i][j] == 2048) {
                n++;
                break;
            }
        }
    }
    return n;
}

//将每次操作前的数组保存到arr0中
void give() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr0[i][j] = arr[i][j];
        }
    }
}

//生成一个4*4的数组用来当界面
void setMap() {
    while (1) {
        system("cls");
        if (arr[setX()][setY()] == 0) {
            arr[setX()][setY()] = setNum();
            printf("---+-----+-----+-----+\n");
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d  |  ", arr[i][j]);
                    if (j == 3) {
                        printf("\n");
                    }
                }
                printf("---+-----+-----+-----+\n");
            }
            break;
        }
    }
}
//键入5之后的操作***************************
void set5() {
    for (int i = 0; i < 4; i++) {
        int n = 0;
        for (int j = 0; ; ) {
            if (arr[j][i] == 0) {
                int k = j;
                while (k < 3) {
                    arr[k][i] = arr[k + 1][i];
                    arr[k + 1][i] = 0;
                    k++;
                }
                n++;
            }
            else if (arr[j][i] != 0) {
                j++;
                n++;
            }
            if (n == 4) {
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[j][i] == arr[j + 1][i]) {
                arr[j][i] = arr[j][i] + arr[j + 1][i];
                arr[j + 1][i] = 0;
                int k = j + 1;
                while (k < 3) {
                    arr[k][i] = arr[k + 1][i];
                    arr[k + 1][i] = 0;
                    k++;
                }
            }
        }
    }
    //通过循环将改变之后的数组打印出来，并且在空白位置（为零的地方）生成随机数2或4
    while (1) {
        if (isHave_2048() == 1) {
            printf("恭喜你成功了！\n");
            break;
        }
        if ((compare() == 16) && (full() == 16)) {
            break;
        }
        else if ((compare() == 16) && (full() != 16)) {
            break;
        }
        system("cls");
        int x = setX();
        int y = setY();
        if (arr[x][y] == 0) {
            arr[x][y] = setNum();
            printf("---+-----+-----+-----+\n");
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d  |  ", arr[i][j]);
                    if (j == 3) {
                        printf("\n");
                    }
                }
                printf("---+-----+-----+-----+\n");
            }
            break;
        }
    }
}
//键入2之后的操作***************************
void set2() {
    for (int i = 0; i < 4; i++) {
        int n = 0;
        for (int j = 3; ; ) {
            if (arr[j][i] == 0 && j != 0) {
                int k = j;
                while (k > 0) {
                    arr[k][i] = arr[k - 1][i];
                    arr[k - 1][i] = 0;
                    k--;
                }
                n++;
            }
            else if (arr[j][i] != 0) {
                j--;
                n++;
            }
            if (n == 4) {
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (arr[j][i] == arr[j - 1][i]) {
                arr[j][i] = arr[j][i] + arr[j - 1][i];
                arr[j - 1][i] = 0;
                int k = j - 1;
                while (k > 0) {
                    arr[k][i] = arr[k - 1][i];
                    arr[k - 1][i] = 0;
                    k--;
                }
            }
        }
    }
    //通过循环将改变之后的数组打印出来，并且在空白位置（为零的地方）生成随机数2或4
    while (1) {
        if (isHave_2048() == 1) {
            printf("恭喜你成功了！\n");
            break;
        }
        if ((compare() == 16) && (full() == 16)) {
            break;
        }
        else if ((compare() == 16) && (full() != 16)) {
            break;
        }
        system("cls");
        int x = setX();
        int y = setY();
        if (arr[x][y] == 0) {
            arr[x][y] = setNum();
            printf("---+-----+-----+-----+\n");
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d  |  ", arr[i][j]);
                    if (j == 3) {
                        printf("\n");
                    }
                }
                printf("---+-----+-----+-----+\n");
            }
            break;
        }
    }
}
//键入1之后的操作***************************
void set1() {
    for (int i = 0; i < 4; i++) {
        int n = 0;
        for (int j = 0; ; ) {
            if (arr[i][j] == 0 && j != 3) {
                int k = j;
                while (k < 3) {
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = 0;
                    k++;
                }
                n++;
            }
            else if (arr[i][j] != 0) {
                j++;
                n++;
            }
            if (n == 4) {
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == arr[i][j + 1]) {
                arr[i][j] = arr[i][j] + arr[i][j + 1];
                arr[i][j + 1] = 0;
                int k = j + 1;
                while (k < 3) {
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = 0;
                    k++;
                }
            }
        }
    }
    //通过循环将改变之后的数组打印出来，并且在空白位置（为零的地方）生成随机数2或4
    while (1) {
        if (isHave_2048() == 1) {
            printf("恭喜你成功了！\n");
            break;
        }
        if ((compare() == 16) && (full() == 16)) {
            break;
        }
        else if ((compare() == 16) && (full() != 16)) {
            break;
        }
        system("cls");
        int x = setX();
        int y = setY();
        if (arr[x][y] == 0) {
            arr[x][y] = setNum();
            printf("---+-----+-----+-----+\n");
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d  |  ", arr[i][j]);
                    if (j == 3) {
                        printf("\n");
                    }
                }
                printf("---+-----+-----+-----+\n");
            }
            break;
        }
    }
}
//键入3之后的操作***************************
void set3() {
    for (int i = 0; i < 4; i++) {
        int n = 0;
        for (int j = 3; ; ) {
            if (arr[i][j] == 0 && j != 0) {
                int k = j;
                while (k > 0) {
                    arr[i][k] = arr[i][k - 1];
                    arr[i][k - 1] = 0;
                    k--;
                }
                n++;
            }
            else if (arr[i][j] != 0) {
                j--;
                n++;
            }
            if (n == 4) {
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            if (arr[i][j] == arr[i][j - 1]) {
                arr[i][j] = arr[i][j] + arr[i][j - 1];
                arr[i][j - 1] = 0;
                int k = j - 1;
                while (k > 0) {
                    arr[i][k] = arr[i][k - 1];
                    arr[i][k - 1] = 0;
                    k--;
                }
            }
        }
    }
    //通过循环将改变之后的数组打印出来，并且在空白位置（为零的地方）生成随机数2或4
    while (1) {
        if (isHave_2048() == 1) {
            printf("恭喜你成功了！\n");
            break;
        }
        if ((compare() == 16) && (full() == 16)) {
            break;
        }
        else if ((compare() == 16) && (full() != 16)) {
            break;
        }
        system("cls");
        int x = setX();
        int y = setY();
        if (arr[x][y] == 0) {
            arr[x][y] = setNum();
            printf("---+-----+-----+-----+\n");
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d  |  ", arr[i][j]);
                    if (j == 3) {
                        printf("\n");
                    }
                }
                printf("---+-----+-----+-----+\n");
            }
            break;
        }
    }
}

//从键盘上输入字符，游戏做出的反应
void Input() {
    while (1) {
        //Sleep(3000);
        int key = 0;
        scanf("%d", &key);
        //key = getchar();
        give();
        if (key == 5) {
            set5();
            if (isHave_2048() == 1) {
                break;
            }
            if ((compare() == 16) && (full() == 16)) {
                break;
            }
        }
        if (key == 2) {
            set2();
            if (isHave_2048() == 1) {
                break;
            }
            if ((compare() == 16) && (full() == 16)) {
                break;
            }
        }
        if (key == 1) {
            set1();
            if (isHave_2048() == 1) {
                break;
            }
            if ((compare() == 16) && (full() == 16)) {
                break;
            }
        }
        if (key == 3) {
            set3();
            if (isHave_2048() == 1) {
                break;
            }
            if ((compare() == 16) && (full() == 16)) {
                break;
            }
        }
    }
}

//菜单界面
int menu() {
    printf("********************\n");
    printf("*****1.开始游戏*****\n");
    printf("********************\n");
    printf("*****0.结束游戏*****\n");
    printf("********************\n");
    printf("请输入你的选择：");
    int choose = 0;
    scanf("%d", &choose);
    //getchar();
    return choose;
}



//进行游戏操作的过程
void game() {
    system("cls");
    setMap();
    Input();
    //Sleep(3000);
}

//结束游戏后是否返回菜单
int again() {
    while (1) {
        printf("是否继续游玩？\n");
        printf("1--yes\n0--no\n");
        int choose = 0;
        scanf("%d", &choose);
        if (choose == 1) {
        }
        else if (choose == 0) {
            system("cls");
        }
        else {
            printf("输入有误，请重输！\n");
            Sleep(3000);
            system("cls");
        }
    }
    return 0;
}

int main() {
    srand(time(0));
    while (1) {
        system("cls");
        int choose = menu();
        if (choose == 1) {
            game();
            while (1) {
                printf("是否继续游玩？\n");
                printf("1--yes\n0--no\n");
                int choose = 0;
                scanf("%d", &choose);
                if (choose == 1) {
                    break;
                }
                else if (choose == 0) {
                    system("cls");
                    goto _1;
                }
                else {
                    printf("输入有误，请重输！\n");
                    Sleep(3000);
                    system("cls");
                }
            }
        }
        else if (choose == 0) {
            break;
        }
        else {
            printf("输入有误，请重输！\n");
            Sleep(3000);
            system("cls");
        }
    }
_1:
    return 0;
}