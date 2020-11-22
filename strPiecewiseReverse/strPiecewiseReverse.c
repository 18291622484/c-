#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//自己写的类似于strtok函数，遇到空格符，就将空格赋成'\0'，然后返回'\0'下一个的地址值
//如果遇到'\0'则直接返回一个NULL
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

//一个递归函数，将一段一段被赋上'\0'的字符串倒着输出
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
    //用户输入字符串函数，遇到回车键就结束
    //一般的输入不能满足将空格也输入
    while (c != '\n') {
        ch[i] = c;
        i++;
        scanf("%c", &c);
   }
    //printf("%s\n", ch);
    func(ch);
    return 0;
}