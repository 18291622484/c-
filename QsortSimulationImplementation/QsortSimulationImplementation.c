#include<stdio.h>
#include<stdlib.h>


int cmpup(int* a, int* b) {
	return *a - *b;
}
int cmpdown(int* a, int* b) {
	return *b - *a;
}

void myBubble(void* base, size_t size, size_t num, int (*CMP)(const void*, const void*)) {
	//使用char可以进行一个字节一个字节的加减，只要传入对应数组的类型字节大小
	//就可以实现，通用数组类型的冒泡排序
	char* st = (char*)base;
	//用来临时交换的数组，个的空见要足够大，不要pia气，要防止意外出现
	char tmp[16];
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (CMP(st+j*size,st+(j+1)*size) > 0) {
				//memcpy(void* destin,void* source,unsigned n)函数，从源source中拷贝n个字节到目标destin中
				//不知道传入数组的类型，就可以使用memcpy函数，然后根据输入类型字节大小，拷贝对应的字节
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
	//升序排序
	myBubble(arr, size,num, cmpup);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	//降序排序
	myBubble(arr, size, num, cmpdown);
	for (int i = 0; i < num; i++) {
		printf("%d ", arr[i]);
	}printf("\n");
	return 0;
}