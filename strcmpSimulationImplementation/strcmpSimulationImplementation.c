#include<stdio.h>
#include<stdlib.h>

int myStrcmp(const char* str1,const char* str2) {
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	while (*str1 != '\0' || *str2 != '\0') {
		if (*str1 == *str2) {
			str1++;
			str2++;
		}
		else if (*str1 > * str2) {
			return 1;
		}
		else {
			return -1;
		}
	}
	if (*str1 == '\0' && *str2 == '\0') {
		return 0;
	}
	else if (*str1 == '\0' && *str2 != '\0') {
		return -1;
	}
	else{
		return 1;
	}
}

int main() {
	char name1[] = "mabaoguo";
	char name2[] = "mabaoguoa";
	int ret = myStrcmp(name1, name2);
	printf("%d\n", ret);
	return 0;
}