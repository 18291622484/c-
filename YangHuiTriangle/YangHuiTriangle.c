#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 10

//正常排列的杨辉三角
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

//不正规的杨辉三角，排列不好看
void yangHuiTriangle(int n)
{
	int data[30][30] = { 1 }; //第一行直接填好，播下种子

	int i, j;

	for (i = 1; i < n; i++) //从第二行开始填
	{
		data[i][0] = 1; //每行的第一列都没有区别，直接给1，保证不会越界。
		for (j = 1; j <= i; j++) //从第二列开始填
		{
			data[i][j] = data[i - 1][j] + data[i - 1][j - 1]; //递推方程
		}
	}

	for (i = 0; i < n; i++) //填完打印
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d ", data[i][j]);
		}
		putchar('\n');
	}
}
//稍微改进，但是排列仍旧不够好看,不过由于是一维的，所以变简单了，但是每次只能保存最后一行的数据
void yangHuiTriangle1(int n)
{
	int data[30] = { 1 };

	int i, j;
	printf("1\n"); //第一行就直接打印了
	for (i = 1; i < n; i++) //从第二行开始
	{
		for (j = i; j > 0; j--) //从后向前填，避免上一行的数据在使用前就被覆盖
		{
			data[j] += data[j - 1]; //公式同上，由于变成了一维，公式也变简单了。
		}

		for (j = 0; j <= i; j++) //这一行填完就直接打印了。
		{
			printf("%d ", data[j]);
		}
		putchar('\n');
	}
}

int main() {
	printf("请输入想要打印的行数：");
	int n = 0;
	scanf("%d", &n);
	YangHuiTriangle(n);
	print(n);
	//yangHuiTriangle(n);
	//yangHuiTriangle1(n);
	return 0;
}