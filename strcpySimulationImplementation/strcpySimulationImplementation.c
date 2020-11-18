#include<stdio.h>
#include<stdlib.h>

char* myStrcpy(char* str1, const char* str2) {
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	char* str = str1;
	while (*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str;
}

int main() {
	char name1[1024] = "mabaoguodashihahaha";
	char name2[] = "mabaoguogoushi123456789";
	printf("%s\n", name1);
	printf("%s\n", myStrcpy(name1, name2));
	return 0;
}