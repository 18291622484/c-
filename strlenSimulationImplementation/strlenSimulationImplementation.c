#include<stdio.h>
#include<stdlib.h>

size_t myStrlen(const char* str) {
	if (str == NULL) {
		return NULL;
	}
	size_t ret = 0;
	while (*str != '\0') {
		str++;
		ret++;
	}
	return ret;
}

int main() {
	char name[] = "mabaoguobujiangwude";
	int ret = myStrlen(name);
	printf("%d\n", ret);
	return 0;
}