#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10

//�������е��������
int arr[N][2 * N - 1] = { 0 };
void YangHuiTriangle(int n) {
	int flag = 1;
	int mid = n;
	arr[0][n] = 1;
	for (int i = 1; i < n; i++) {
		if (flag == 1) {
			for (int j = 0, k = 1; j < (i + 1) / 2; j++, k += 2) {
				arr[i][n - k] = arr[i - 1][n - k - 1] + arr[i - 1][n - k + 1];
				arr[i][n + k] = arr[i - 1][n + k - 1] + arr[i - 1][n + k + 1];
			}
		}
		if (flag == -1) {
			for (int j = 0, k = 0; j <= i / 2; j++, k += 2) {
				arr[i][n - k] = arr[i - 1][n - k - 1] + arr[i - 1][n - k + 1];
				arr[i][n + k] = arr[i - 1][n + k - 1] + arr[i - 1][n + k + 1];
			}
		}
		flag = -flag;
	}
}

void print(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n ; j++) {
			if (arr[i][j] != 0) {
				printf("%2d", arr[i][j]);
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}
}

//�������������ǣ����в��ÿ�
void yangHuiTriangle(int n)
{
	int data[30][30] = { 1 }; //��һ��ֱ����ã���������

	int i, j;

	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ��
	{
		data[i][0] = 1; //ÿ�еĵ�һ�ж�û������ֱ�Ӹ�1����֤����Խ�硣
		for (j = 1; j <= i; j++) //�ӵڶ��п�ʼ��
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1]; //���Ʒ���
		}
	}

	for (i = 0; i < n; i++) //�����ӡ
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}
}
//��΢�Ľ������������Ծɲ����ÿ�,����������һά�ģ����Ա���ˣ�����ÿ��ֻ�ܱ������һ�е�����
void yangHuiTriangle1(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n"); //��һ�о�ֱ�Ӵ�ӡ��
	for (i = 1; i < n; i++) //�ӵڶ��п�ʼ
	{
		for (j = i; j > 0; j--) //�Ӻ���ǰ�������һ�е�������ʹ��ǰ�ͱ�����
		{
			data[j] += data[j - 1]; //��ʽͬ�ϣ����ڱ����һά����ʽҲ����ˡ�
		}

		for (j = 0; j <= i; j++) //��һ�������ֱ�Ӵ�ӡ�ˡ�
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}

int main() {
	printf("��������Ҫ��ӡ��������");
	int n = 0;
	scanf("%d", &n);
	YangHuiTriangle(n);
	print(n);
	//yangHuiTriangle(n);
	//yangHuiTriangle1(n);
	return 0;
}