#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��

//�����������飬һ������ʾ���û����棻һ����ϵͳ������ɺõģ��������бȽϵġ�
int arr[11][11] = { 0 };
int arr0[9][9] = { 0 };

//��arr0չʾ���鸳��ֵ
void setArr0() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            arr0[i][j] = 9;
        }
    }
}

//��ʾ�û�����
void setShow(int sign) {
    printf("��  ");
    for (int n = 1; n < 10; n++) {
        printf("%-4d", n);
    }
    int num = 10;
    if (sign == 0) {
        num--;
    }
    //�û��ҵ�ʮ�����ף���ô�ͽ��Զ������������������е��ף���ʧ��
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
            printf("��ϲ�㣬�ɹ��ҵ�ȫ�����ף�\n");
        }
        else {
            printf("δ�Ų�������ˣ�\n");
            printf("��Ϸ������\n");
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

//������������
int setXY() {
    int n = rand() % 9 + 1;
    return n;
}

//�����������һ��9*9����10�����׵�ϵͳ����
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

//��ϵͳ�����������б�����֣���ÿ��������Χ��һȦ�ж��ٸ�����
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

//�������У����ѵĵط����ڣ����û�ѡ���հ׵ĵط������չʾһƬ�����������ڲ��Ĺ�����֮�󣬵õ�����ʹ�õݹ麯�������
//�������������CSDN��Jether���е�һƪ���͡���ɨ����Ϸ���ԭ��
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

//���ڲ���ѧǳ������ʹ�ù�꣬���Ծ�ֻ�����û�������������������
void inPut() {
    while (1) {
        printf("�������꣺");
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
                printf("�ȵ������ˣ�\n");
                printf("��Ϸ������\n");
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
