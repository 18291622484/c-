#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

const char* myStrstr(const char* str1,const char* str2) {
	// �����޷���֤�����ߴ���һ��ɶ���Ĳ���. ���缫������´���һ���Ƿ���ַ. 
	// ����Ҫ�����ô����ܱȽϽ�׳. 
	// Ӧ���ں�������ڴ����϶��ڲ����Ϸ��Ե�У��
	// ��ν�� �п� ֻ�� "��ʤ����" �Ĳ���. �����ܴӸ����Ͻ������Ƿ�����������. 
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	//����һ�����飬��������Դ�������ַ���Ŀ�������г���λ�õ��±�
	//��������ʡȥһЩ����Ҫ���ж�
	char ch = *str2;
	//printf("%c\n", ch);
	int arr[MAX] = { 0 };
	int flag = 0;
	int num = strlen(str1);
	for (int i = 0; i<num; i++) {
		if (str1[i] == ch) {
			arr[flag] = i;
			flag++;
		}
	}arr[flag] = -1;

	/*int i = 0;
	for (i = 0; arr[i] != -1; i++) {
		printf("%d ", arr[i]);
	}printf("%d\n",arr[i]);*/

	//���бȽ�
	for (int i = 0; arr[i] != -1; i++) {
		int j = arr[i];
		char* red = str2;
		while (str1[j] == *red
			&& str1[j] != '\0' 
			&& *red != '\0') {
			j++;
			red++;
		}
		if (*red == '\0') {
			return str1+arr[i];
		}
	}
	return NULL;
}

int main() {
	char name1[] = "mabaoguobuyaoliannianqingrenbujiangwude";
	char name2[] = "buyaolian";
	char* ret=myStrstr(name1, name2);
	for (int i = 0; i<strlen(name2); i++) {
		printf("%c", ret[i]);
	}printf("\n");
	return 0;
}