#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* myStrncat(char* destin, const char* source, size_t num) {
	if (destin == NULL || source == NULL) {
		return NULL;
	}
	int i = 0;
	while (destin[i] != '\0') {
		i++;
	}
	for (int k = 0; k < num; k++, i++) {
		if (source[k]!='\0') {
			destin[i] = source[k];
		}
		else {
			destin[i] = '\0';
			return destin;
		}
	}
}

int main() {
	printf("ÇëÊäÈë×Ö·û´®£º");
	char str1[1024] = { 0 };
	scanf("%s", str1);
	printf("ÇëÊäÈëÆ´½Ó×Ö·û´®£º");
	char str2[1024] = { 0 };
	scanf("%s", str2);
	printf("ÊäÈëÒªÆ´½Ó¼¸¸ö×Ö·û£º");
	size_t num = 0;
	scanf("%d", &num);
	myStrncat(str1, str2, num);

	//strncat(str1, str2, num);
	printf("%s\n", str1);
	return 0;
}