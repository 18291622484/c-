#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void LeftString(char* str,int size,int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		str[size+i] = str[i];
		str[size + 1 + i] = '\0';
	}
	for (int j = i; str[j] != '\0'; j++) {
		printf("%c", str[j]);
	}printf("\n");
}

int Size(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		ret++;
	}
	return ret;
}

int main() {
	//���Խ���һ��ȡ����Ȼ�󽫺�����ַ�ǰ�ƣ�Ȼ���ȡ�����ַ��ŵ�ĩλ���Դ����ƣ����ǽ��鷳��
	//���ԣ��Ҳ����ַ����ռ�ֻҪ�㹻��ǰ�潻����������ַ��Ͳ���Խ�磬Ҳ����ʵ��Ŀ��
	char str[20] = "abcde";
	int size = Size(str);
	//printf("%d", size);
	printf("%s\n", str);
	printf("����Ҫ����ת�����ַ���");
	int num = 0;
	scanf("%d", &num);
	LeftString(str, size, num);

	//��֤�����ǰ����ַ�ֱ�ӷŵ���\0����λ����
	//���Ҳ��ں��渽�ϡ�\0����ô������������
	/*str[9] = 'j';
	printf("%s", str);*/
	return 0;
}



//���߻���һ��������
//�Ƚ�Ҫ������ǰ�����һ�����CBADEFG����Ȼ�󽫺���Ҳ����CBAGFED���������������DEFGABC�����ɡ�
//����ֻ��Ҫ����ֵ�������ɣ�����дһ��������������ɾֲ����򣬴������£�
//void reverse_part(char* str, int start, int end) //���ַ�����start��end��һ������
//{
//	int i, j;
//	char tmp;
//
//	for (i = start, j = end; i < j; i++, j--)
//	{
//		tmp = str[i];
//		str[i] = str[j];
//		str[j] = tmp;
//	}
//}
//
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len;
//	reverse_part(src, 0, pos - 1); //����ǰ��
//	reverse_part(src, pos, len - 1); //������
//	reverse_part(src, 0, len - 1); //��������
//}