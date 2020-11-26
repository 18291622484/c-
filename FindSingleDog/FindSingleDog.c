#include<stdio.h>
#include<stdlib.h>

//方法1                            1,2,5,9,3,5,3,8,1,9
void FindSingleDog(int* arr,int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				if (j != size - 1) {
					arr[j] = arr[size - 1];
				}
				size--;
				flag++;
				break;
			}
		}
		if (flag == 0) {
			printf("%d\n", arr[i]);
		}
	}
}
//方法2
void FindSingleDog1(int* arr, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = 0;
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
	/*for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}printf("\n");*/
	int flag = 0;
	for (int i = 0; i < size - 1; ) {
		if (arr[i] == arr[i + 1]) {
			i += 2;
		}
		else {
			printf("%d\n", arr[i]);
			i++;
			flag++;
		}
		if (flag == 2) {
			return;
		}
	}
}

int main() {
	int arr[] = { 1,2,5,9,3,5,3,1,9,6,13,7,6,8,13,7};
	int arr1[] = { 1,2,5,9,3,5,3,1,9,6,13,7,6,8,13,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	printf("第一种方法结果：\n");
	FindSingleDog(arr, size);
	printf("第二种方法结果：\n");
	FindSingleDog1(arr1, size1);
	return 0;
}