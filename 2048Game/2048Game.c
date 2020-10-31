#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//�������2����4
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

//������������x����
int setX() {
    int x = rand() % 4;
    //printf("%d\n", x);
    return x;
}
//������������y����
int setY() {
    int y = rand() % 4;
    //printf("%d\n", y);
    return y;
}

//����һ��������������ͼ
int arr[4][4] = { 0 };
//����һ�����飬������ÿһ�β���֮�������Ƚϣ����ޱ仯�������������
int arr0[4][4] = { 0 };

//�Ƚ����飬����ǰ��������Ƿ���ȣ�����ȣ��������������������ȣ�����������
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

//�ж��Ƿ���������Ϊ�������
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

//�ж��Ƿ������2048����
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

//��ÿ�β���ǰ�����鱣�浽arr0��
void give() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            arr0[i][j] = arr[i][j];
        }
    }
}

//����һ��4*4����������������
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
//����5֮��Ĳ���***************************
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
    //ͨ��ѭ�����ı�֮��������ӡ�����������ڿհ�λ�ã�Ϊ��ĵط������������2��4
    while (1) {
        if (isHave_2048() == 1) {
            printf("��ϲ��ɹ��ˣ�\n");
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
//����2֮��Ĳ���***************************
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
    //ͨ��ѭ�����ı�֮��������ӡ�����������ڿհ�λ�ã�Ϊ��ĵط������������2��4
    while (1) {
        if (isHave_2048() == 1) {
            printf("��ϲ��ɹ��ˣ�\n");
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
//����1֮��Ĳ���***************************
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
    //ͨ��ѭ�����ı�֮��������ӡ�����������ڿհ�λ�ã�Ϊ��ĵط������������2��4
    while (1) {
        if (isHave_2048() == 1) {
            printf("��ϲ��ɹ��ˣ�\n");
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
//����3֮��Ĳ���***************************
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
    //ͨ��ѭ�����ı�֮��������ӡ�����������ڿհ�λ�ã�Ϊ��ĵط������������2��4
    while (1) {
        if (isHave_2048() == 1) {
            printf("��ϲ��ɹ��ˣ�\n");
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

//�Ӽ����������ַ�����Ϸ�����ķ�Ӧ
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

//�˵�����
int menu() {
    printf("********************\n");
    printf("*****1.��ʼ��Ϸ*****\n");
    printf("********************\n");
    printf("*****0.������Ϸ*****\n");
    printf("********************\n");
    printf("���������ѡ��");
    int choose = 0;
    scanf("%d", &choose);
    //getchar();
    return choose;
}



//������Ϸ�����Ĺ���
void game() {
    system("cls");
    setMap();
    Input();
    //Sleep(3000);
}

//������Ϸ���Ƿ񷵻ز˵�
int again() {
    while (1) {
        printf("�Ƿ�������棿\n");
        printf("1--yes\n0--no\n");
        int choose = 0;
        scanf("%d", &choose);
        if (choose == 1) {
        }
        else if (choose == 0) {
            system("cls");
        }
        else {
            printf("�������������䣡\n");
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
                printf("�Ƿ�������棿\n");
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
                    printf("�������������䣡\n");
                    Sleep(3000);
                    system("cls");
                }
            }
        }
        else if (choose == 0) {
            break;
        }
        else {
            printf("�������������䣡\n");
            Sleep(3000);
            system("cls");
        }
    }
_1:
    return 0;
}