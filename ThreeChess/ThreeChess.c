#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_ROW 3
#define MAX_COL 3

//初始化数组
void setFace(arr);
//打印用户界面
void youShow(arr);
//用户输入
void youInit(arr);
//判定输赢
char isWinJudge(arr);
void isWin(char ch);
//电脑输入
void comInit(arr);
//判定输赢
char isWinJudge(arr);
void isWin(char ch);

int meun() {
    printf("********************\n");
    printf("*****1.开始游戏*****\n");
    printf("********************\n");
    printf("*****0.结束游戏*****\n");
    printf("********************\n");
    printf("请输入你的选择：");
    int choose = 0;
    scanf("%d", &choose);
    return choose;
}

void setFace(char arr[MAX_ROW][MAX_COL]) {
    for (int r = 0; r < MAX_ROW; r++) {
        for (int c = 0; c < MAX_COL; c++) {
            arr[r][c] = ' ';
        }
    }
}

void youShow(char arr[MAX_ROW][MAX_COL]) {
    for (int c = 0; c < MAX_COL; c++) {
        printf("   %d ", c);
    }
    printf("\n");
    for (int r = 0; r < MAX_ROW; r++) {
        printf(" +---+---+---+\n");
        printf("%d", r);
        for (int c = 0; c < MAX_COL; c++) {
            printf("| %c ", arr[r][c]);
        }
        printf("|\n");
    }
    printf(" +---+---+---+\n");
}

void youInit(char arr[MAX_ROW][MAX_COL]) {
    while (1) {
        system("cls");
        youShow(arr);
        printf("请输入你选择的坐标：");
        int r = 0, c = 0;
        scanf("%d %d", &r, &c);
        if (0 <= r < MAX_ROW
            && 0 <= c < MAX_COL
            && arr[r][c] == ' ') {
            arr[r][c] = 'x';
            system("cls");
            youShow(arr);
            break;
        }
        else {
            printf("您输入有误，请重输!\n");
            Sleep(1000);
            system("cls");
        }
    }
}

void comInit(char arr[MAX_ROW][MAX_COL]) {
    srand((unsigned)time(0));
    while (1) {
        int r = rand() % MAX_ROW;
        int c = rand() % MAX_COL;
        if (arr[r][c] != ' ') {
            continue;
        }
        else {
            arr[r][c] = 'o';
            break;
        }
    }
    system("cls");
    youShow(arr);
}

char isWinJudge(char arr[MAX_ROW][MAX_COL]) {
    for (int r = 0; r < MAX_ROW; r++) {
        if (arr[r][0] != ' '
            && arr[r][0] == arr[r][1]
            && arr[r][0] == arr[r][2]) {
            return arr[r][0];
        }
    }
    for (int c = 0; c < MAX_COL; c++) {
        if (arr[0][c] != ' '
            && arr[0][c] == arr[1][c]
            && arr[0][c] == arr[2][c]) {
            return arr[0][c];
        }
    }
    if (arr[0][0] != ' '
        && arr[0][0] == arr[1][1]
        && arr[0][0] == arr[2][2]) {
        return arr[0][0];
    }
    if (arr[2][0] != ' '
        && arr[2][0] == arr[1][1]
        && arr[2][0] == arr[0][2]) {
        return arr[2][0];
    }
    
    for (int r = 0; r < MAX_ROW; r++) {
        for (int c = 0; c < MAX_COL; c++) {
            if (arr[r][c] == ' ') {
                return 'n';
            }
        }
    }
    return 'y';
}

void isWin(char ch) {
    if (ch == 'x') {
        printf("玩家胜！\n");
    }
    if (ch == 'o') {
        printf("你是sb！\n");
    }
    if (ch == 'y') {
        printf("你还是sb！\n");
    }
}

void game() {
    char arr[MAX_ROW][MAX_COL];
    //初始化数组
    setFace(arr);
    //打印用户界面
    //youShow(arr);
    while (1) {
        //用户输入
        youInit(arr);
        //判定输赢
        if (isWinJudge(arr) != 'n') {
            isWin(isWinJudge(arr));
            break;
        }
        //电脑输入
        comInit(arr);
        //判定输赢
        if (isWinJudge(arr) != 'n') {
            isWin(isWinJudge(arr));
            break;
        }
   }
}

int main() {
    while (1) {
        int choose = meun();
        if (choose == 1) {
            system("cls");
            game();
            break;
        }
        else if (choose == 0) {
            break;
        }
        else {
            printf("您输入有误，请重输!");
            Sleep(2000);
            system("cls");
        }
    }
    return 0;
}
