#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�Լ�д��������strtok�����������ո�����ͽ��ո񸳳�'\0'��Ȼ�󷵻�'\0'��һ���ĵ�ֵַ
//�������'\0'��ֱ�ӷ���һ��NULL
char* mystrtok(char* str) {
    while (1) {
        if (*str == ' ') {
            *str = '\0';
            return str+1;
        }
        else if (*str == '\0') {
            return NULL;
        }
        str++;
    }
}

//һ���ݹ麯������һ��һ�α�����'\0'���ַ����������
int func(char* str) {
    if (str == NULL) {
        return 0;
    }
    char* p = str;
    str = mystrtok(str);
    func(str);
    printf("%s ", p);
    return 0;
}

int main() {
    char ch[100] = { 0 };
    int i = 0;
    char c = 0;
    scanf("%c", &c);
    //�û������ַ��������������س����ͽ���
    //һ������벻�����㽫�ո�Ҳ����
    while (c != '\n') {
        ch[i] = c;
        i++;
        scanf("%c", &c);
   }
    //printf("%s\n", ch);
    func(ch);
    return 0;
}