#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

const char* myStrstr(const char* str1,const char* str2) {
	// 由于无法保证调用者传入一个啥样的参数. 比如极端情况下传入一个非法地址. 
	// 就需要尽量让代码能比较健壮. 
	// 应该在函数的入口处加上对于参数合法性的校验
	// 所谓的 判空 只是 "聊胜于无" 的操作. 并不能从根本上解决传入非法参数的问题. 
	if (str1 == NULL || str2 == NULL) {
		return NULL;
	}
	//创建一个数组，用来保存源数组首字符在目标数组中出现位置的下标
	//这样可以省去一些不必要的判定
	char ch = *str2;
	//printf("%c\n", ch);
	int arr[MAX] = { 0 };
	int flag = 0;
	int num = strlen(str1);
	for (int i = 0; i<num; i++) {
		if (str1[i] == ch) {
			arr[flag] = i;
			flag++;
		}
	}arr[flag] = -1;

	/*int i = 0;
	for (i = 0; arr[i] != -1; i++) {
		printf("%d ", arr[i]);
	}printf("%d\n",arr[i]);*/

	//进行比较
	for (int i = 0; arr[i] != -1; i++) {
		int j = arr[i];
		char* red = str2;
		while (str1[j] == *red
			&& str1[j] != '\0' 
			&& *red != '\0') {
			j++;
			red++;
		}
		if (*red == '\0') {
			return str1+arr[i];
		}
	}
	return NULL;
}

int main() {
	char name1[] = "mabaoguobuyaoliannianqingrenbujiangwude";
	char name2[] = "buyaolian";
	char* ret=myStrstr(name1, name2);
	for (int i = 0; i<strlen(name2); i++) {
		printf("%c", ret[i]);
	}printf("\n");
	return 0;
}