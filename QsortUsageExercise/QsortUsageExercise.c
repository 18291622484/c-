#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define MAX_C 4

//void cmp_int(const void* _a,const void* _b) {
//	int* a = (int*)_a;
//	int* b = (int*)_b;
//	return *a - *b;//Ĭ���������뽵���򷵻�*b-*a
//}
//����Ϊ�淶д�����������������ÿ���ͨ�������

//����
int cmp_int(int* a,int* b){
	return *a - *b;//Ĭ���������뽵���򷵻�*b-*a
}
//������
int cmp_double(double* a,double* b) {
	//�ڶԸ������double�͵�һ��Ҫ����Ŀ���������ΪҪ��ʹ����������������Ļ�
	//����������ܽӽ���������ܷ���һ����С��С��������-1��С��1������cmp�ķ���ֵ��int��
	//��˻Ὣ���С������0��ϵͳ��Ϊ����ȣ�ʧȥ�˱������ڵĴ�С��ϵ
	return *a > * b ? 1 : -1;
}
//�ַ���
int cmp_char(char* a, char* b) {
	return *a - *b;
}

//�ַ�����
int cmp_str(char(* a),char(* b)) {
	return strcmp(a, b);
}

int main() {
	//����
	int arr_int[MAX] = { 1,8,6,9,7,3,2,10,4,5 };
	qsort(arr_int, MAX, sizeof(arr_int[0]), cmp_int);
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr_int[i]);
	}printf("\n");

	//������
	double arr_double[MAX] = { 1.0,8.0,6.0,9.0,7.0,3.0,2.0,10.0,4.0,5.0 };
	qsort(arr_double, MAX, sizeof(arr_double[0]), cmp_double);
	for (int i = 0; i < MAX; i++) {
		printf("%f ", arr_double[i]);
	}printf("\n");

	//�ַ���
	char arr_char[MAX] = { 'c','d','g','y','u','i','e','z','h','l' };
	qsort(arr_char, MAX, sizeof(arr_char[0]), cmp_char);
	for (int i = 0; i < MAX; i++) {
		printf("%c ", arr_char[i]);
	}printf("\n");

	//�ַ�����
	char arr_str[MAX_C][MAX_C] = { "asd","abf","bde","mny" };
	qsort(arr_str, MAX_C, sizeof(arr_str[0]), cmp_str);
	for (int i = 0; i < MAX_C; i++) {
		printf("%s ", arr_str[i]);
	}printf("\n");
	return 0;
}