#include<stdio.h>
#include<stdlib.h>

int main() {

	int arr[] = { 1,2,3,4,5,6,7 };//����6

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

			printf("�±�Ϊ%d\n", mid);

			break;

		}

	}

	if (left > right) {

		printf("δ�ҵ�\n");

	}

	return 0;

}