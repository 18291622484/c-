#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* myStrncpy(char* destin, const char* source, size_t num) {
	if (destin == NULL || source == NULL) {
		return NULL;
	}
	int i = 0;
	int j = 0;
	for (; i < num; i++) {
		if (source[j] == '\0') {
			destin[i] = '0';
		}
		else {
			destin[i] = source[i];
			j++;
		}
	}
	destin[j] = '\0';
	return destin;
}

int main() {
	printf("�������ַ�����");
	char str1[1024] = { 0 };
	scanf("%s", str1);
	printf("������Ҫ�������ַ�����");
	char str2[1024] = { 0 };
	scanf("%s", str2);
	printf("����Ҫ���������ַ���");
	size_t num = 0;
	scanf("%d", &num);
	myStrncpy(str1, str2, num);

	//strncpy(str1, str2, num);
	printf("%s\n", str1);
	return 0;
}