#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int reverse_string(char* arr) {
	if (arr[0] == '\0') {
		return 0;
	}
	else {
		reverse_string(arr + 1);
		printf("%c", arr[0]);
		return 0;
	}
}

int main() {
	char arr[10] = "0";
	printf("ÇëÊäÈë×Ö·û´®¸öÊı£º\n");
	int n = 0;
	scanf("%d", &n);
	printf("ÇëÊäÈë×Ö·û´®£º\n");

	/*for (int i = 0; i < n; i++) {
		scanf("%c", &arr[i]);
	}*/

	scanf("%s", arr);

	/*for (int i = 0; i < n; i++) {
		printf("%c", arr[i]);
	}*/

	//printf("%s", arr);
	//char arr[] = "yevoli";
	reverse_string(arr);
	return 0;
}