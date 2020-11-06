#include<stdio.h>
#include<stdlib.h>

void reverse(char* str,int size) {
	int i = 0;
	char ch = 0;
	while ((str+i)<(str+size-i)) {
		ch = *(str+i);
		*(str+i) = *(str+size-i);
		*(str + size - i) = ch;
		i++;
	}
}

int main(){
	char arr[] = "!mhz evol i";
	int size = sizeof(arr) / sizeof(arr[0]) - 2;
	//printf("%d\n", size);
	reverse(arr,size);
	printf("%s", arr);
	return 0;
}