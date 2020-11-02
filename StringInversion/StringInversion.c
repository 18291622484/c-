#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int reverse_string(char* arr) {
	if (strlen(arr)<2) {
		return arr;
	}
	else {
		char ch = *arr;
		int len = strlen(arr) - 1;
		*arr = *(arr + len);
		*(arr + len) = '\0';
		reverse_string(arr + 1);
		//printf("%c", arr[0]);
		*(arr+len) = ch;
		return arr;
	}
}

int main() {
	char arr[4] = "0";
	//printf("ÇëÊäÈë×Ö·û´®¸öÊý£º\n");
	//int n = 0;
	
	//scanf("%d", &n);
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
	printf("%s\n", arr);
	return 0;
}