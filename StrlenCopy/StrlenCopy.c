#include<stdio.h>
#include<stdlib.h>

int StrlenCopy1(char arr[]) {
	if (arr[0] == '\0') {
		return 0;
	}
	else {
		return 1+StrlenCopy1(arr + 1);
	}
}

int StrlenCopy2(char arr[]) {
	int count = 0;
	for (int i = 0; arr[i] != '\0'; i++) {
		count++;
	}
	return count;
}

int main() {
	char arr[] = "ilovey";
	int num1 = StrlenCopy1(arr);
	int num2 = StrlenCopy2(arr);
	printf("%d %d\n", num1, num2);
	return 0;
}