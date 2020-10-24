#include<stdio.h>
#include<stdlib.h>

int main() {

	int arr[] = { 1,2,3,4,5,6,7 };//查找6

	int left = 0;

	int right = sizeof(arr) / sizeof(arr[0]) - 1;

	//printf("%d\n", right);

	int toFind = 6;

	while (left <= right) {

		int mid = (left + right) / 2;

		if (arr[mid] > toFind) {

			right = mid - 1;

		}

		else if (arr[mid] < toFind) {

			left = mid + 1;

		}

		else {

			printf("下标为%d\n", mid);

			break;

		}

	}

	if (left > right) {

		printf("未找到\n");

	}

	return 0;

}