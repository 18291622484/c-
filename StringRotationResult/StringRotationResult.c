#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int change(char* str,char* str1,char* str2,int* arr,char ch,int size) {
	int k = 0;
	while (arr[k] != -1) {
		int i = 0;
		//��ԭ�ַ����к�ch��ȵ�ǰ����ַ���ת�����
		for (i = 0; i < arr[k]; i++) {
			str[size + i] = str[i];
			str[size + 1 + i] = '\0';
		}
		//����ת������ַ�����Ƚϵ��ַ������бȽϣ���ȷ���1
		if (strcmp(str+arr[k], str1)==0) {
			return 1;
		}
		//�������str2�еı�����ַ�������str��Ȼ�������һ��ѭ��
		else {
			k++;
			if (arr[k] == -1) {
				return 0;
			}
			else {
				strcpy(str, str2);
			}
		}
	}
}

//������¼�´��Ƚ��ַ��������ַ���ԭ�ַ������ĸ��±���ֹ�
int Num(char* str, int* arr, char ch) {
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) {
			arr[flag] = i;
			flag++;
		}
	}
	if (flag == 0) {
		return 1;
	}
	else {
		arr[flag] = -1;
		return 0;
	}
	/*for (int i = 0; arr[i]!=-1; i++) {
		printf("%d ", arr[i]);
	}*/
}

int main() {
	//ԭ�ַ���
	char str[20] = "acbcde";
	//��ʱ����ϵͳ�����ַ��������ڽ����Ƚ�֮��������ȣ��ٸ���ԭ�ַ�����������һ�ν���
	char str2[20] = { 0 };
	strcpy(str2, str);
	//���Ƚ��ַ���
	char str1[20] = "cdeacb";
	//������¼�´��Ƚ��ַ��������ַ���ԭ�ַ������ĸ��±���ֹ�
	int arr[20] = { 0 };
	char ch = str1[0];
	if (Num(str, arr, ch)) {
		printf("����ͬ��\n");
		return 0;
	}
	int size = strlen(str);
	int ret=change(str,str1,str2,arr, ch, size);	
	if (ret == 0) {
		printf("����ͬ��\n");
	}
	else {
		printf("��ͬ��\n");
	}
	return 0;
}



//���Ž⣺
//��ʵABCDE������ô������ת������н��������������ABCDEABCD����ַ������ˡ�
//���������ܼ򵥣�ֻ��Ҫ��ԭ�ַ�������һ����ں��棬Ȼ����һ�Ҵ����ҵ��ַ����ǲ�������ԭ�ַ������Ӽ����ɡ�
//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //��һ�������ռ佫ԭ�ַ�����������ԭ�ַ���
//	strcpy(tmp, src); //�ȿ���һ��
//	strcat(tmp, src); //������һ��
//	return strstr(tmp, find) != NULL; //�����Ҳ��ҵõ�
//}