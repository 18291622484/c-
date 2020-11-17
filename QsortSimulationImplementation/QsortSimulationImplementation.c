#include<stdio.h>
#include<stdlib.h>


int cmpup(int* a, int* b) {
	return *a - *b;
}
int cmpdown(int* a, int* b) {
	return *b - *a;
}

void myBubble(void* base, size_t size, size_t num, int (*CMP)(const void*, const void*)) {
	//ʹ��char���Խ���һ���ֽ�һ���ֽڵļӼ���ֻҪ�����Ӧ����������ֽڴ�С
	//�Ϳ���ʵ�֣�ͨ���������͵�ð������
	char* st = (char*)base;
	//������ʱ���������飬���Ŀռ�Ҫ�㹻�󣬲�Ҫpia����Ҫ��ֹ�������
	char tmp[16];
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (CMP(st+j*size,st+(j+1)*size) > 0) {
				//memcpy(void* destin,void* source,unsigned n)��������Դsource�п���n���ֽڵ�Ŀ��destin��
				//��֪��������������ͣ��Ϳ���ʹ��memcpy������Ȼ��������������ֽڴ�С��������Ӧ���ֽ�
				memcpy(tmp, st+j*size, size);
				memcpy(st+j * size, st+(j + 1) * size, size);
				memcpy(st+(j + 1) * size, tmp, size);
			}
		}
	}
}

int main() {
	int arr[10] = { 56,23,48,51,27,19,36,67,92,40 };
	int size = sizeof(arr[0]);
	int num = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	//��������
	myBubble(arr, size,num, cmpup);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	//��������
	myBubble(arr, size, num, cmpdown);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	return 0;
}