#include<stdio.h>
#include<stdlib.h>

char* myStrcat(char* str1,const char* str2) {
	//�����Ϸ��Լ���
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	int num = 0;
	while (str1[num] != '\0') {
		num++;
	}
	//printf("%d\n", num);
	char* ret = str1;
	int i = 0;
	for (i = 0; str2[i] != '\0'; i++) {
		str1[num + i] = str2[i];
	}
	str1[num + i] = '\0';
	return ret;
}

int main() {
	//ע�⣬һ��Ҫ��Ŀ������Ŀռ������㹻�󣬲�Ȼ����ֵͼ�����
	char name1[1024] = "mabaoguo";
	char name2[] = "bujiangwude";
	myStrcat(name1, name2);
	printf("%s\n", name1);
	return 0;
}