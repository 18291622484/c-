#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ڱ�������Ԫ��ǰ�������У�������������Ԫ�أ���ô�Ͳ��ؽ�����
int judge(int arr[],int i,int k) {
	for (; k < i; k++) {
		if (arr[k] == arr[i]) {
			return 0;
		}
	}
	return 1;
}

int StringRank(int arr[],int k,int n) {
	if (k == n) {
		for (int i = 0; i <= n; i++) {
			printf("%d", arr[i]);
		}
		printf("  ");
	}
	else {
		for (int i = k; i <= n; i++) {
			if (judge(arr, i, k) == 1) {
				int t = 0;
				t = arr[i]; arr[i] = arr[k]; arr[k] = t;
				StringRank(arr, k + 1, n);
				t = arr[i]; arr[i] = arr[k]; arr[k] = t;
			}
			
		}
	}
}

int main() {
	/*char arr[10] = { 0 };
	printf("����Ҫ������ַ���������\n");
	int n = 0;
	scanf("%d", &n);
	getchar();
	printf("����һ���ַ�����\n");
	for (int i = 0; i < n; i++) {
		scanf("%c", &arr[i]);
	}*/


	/*for (int i = 0; i < n; i++) {
		printf("%c", arr[i]);
	}*/


	int arr[] = { 1,2,3,3 };

	StringRank(arr,0,3);
	return 0;
}