#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�÷������ַ�����������ַ�ת��Ϊ����������������ֵ��
//ע�⣺ת��ʱ����ǰ��Ĳ��ɼ��ַ���ֱ���������ֻ��������Ųſ�ʼ��ת����
//      �������������ֻ��ַ�������ʱ('\0')�Ž���ת��������������ء�

int myAtoi(const char* str) {
	char TS[1024] = { 0 };
	char* ts = TS;
	//���÷���λ�������ж�������������������ַ������֣����ɼ��ַ�������
	//���ǰ��Ϊ���ɼ��ַ������������ֺ�flag1��++�������Ͳ���������Ĳ��ɼ��ַ�
	int flag1 = 0;
	//�ⲿѭ���ж�ǰ��� ���֡������š����ɼ��ַ�
	while ((*str > 47 && *str < 58)||((*str==43||*str==45)&&flag1==0)||(*str>=0&&*str<=32&&flag1==0)) {
		//�ڲ�ѭ���ж���������֮��� ���ɼ��ַ���������
		if ((*str > 47 && *str < 58)||((*str == 43 || *str == 45))) {
			*ts = *str;
			ts++;
			str++;
			flag1++;
		}
		else {
			str++;
		}
	}
	*ts = '\0';
	int i = 0;
	//���÷���λ������ǡ�-������ôflag�ͼ�һ
	int flag = 0;
	if (TS[i] == 45) {
		i++;
		flag++;
	}
	int ret = 0;
	while (TS[i] != '\0') {
		ret += (TS[i] - 48);
		ret *= 10;
		i++;
	}
	ret /= 10;
	//������ɸѡ����ת���ɶ�Ӧ������֮�����flag==1����ô�������ּ�ȥ�Լ��Ķ��������ɻ�ö�Ӧ���ֵĸ�ֵ
	if (flag == 1) {
		return ret - ret * 2;
	}
	//���flag==0����ô�������ת���õ�����
	return ret;
}

int main() {
	printf("����һ���ַ�����\n");
	char str[1024] = { 0 };
	int i = 0;
	char c = 0;
	scanf("%c", &c);
	while (c != '\n') {
		str[i] = c;
		scanf("%c", &c);
		i++;
	}
	printf("%s\n", str);

	int ret = myAtoi(str);
	printf("%d\n", ret);

	/*int a = atoi("  123 123jklb");
	printf("%d\n", a);*/
	return 0;
}