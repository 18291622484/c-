#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int change(char* str,char* str1,char* str2,int* arr,char ch,int size) {
	int k = 0;
	while (arr[k] != -1) {
		int i = 0;
		//将原字符串中和ch相等的前面的字符旋转到最后
		for (i = 0; i < arr[k]; i++) {
			str[size + i] = str[i];
			str[size + 1 + i] = '\0';
		}
		//将旋转过后的字符与待比较的字符串进行比较，相等返回1
		if (strcmp(str+arr[k], str1)==0) {
			return 1;
		}
		//不相等则将str2中的保存的字符串赋给str，然后进行下一次循环
		else {
			k++;
			if (arr[k] == -1) {
				return 0;
			}
			else {
				strcpy(str, str2);
			}
		}
	}
}

//用来记录下带比较字符串的首字符在原字符串的哪个下标出现过
int Num(char* str, int* arr, char ch) {
	int flag = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ch) {
			arr[flag] = i;
			flag++;
		}
	}
	if (flag == 0) {
		return 1;
	}
	else {
		arr[flag] = -1;
		return 0;
	}
	/*for (int i = 0; arr[i]!=-1; i++) {
		printf("%d ", arr[i]);
	}*/
}

int main() {
	//原字符串
	char str[20] = "acbcde";
	//暂时保存系统给的字符串，用于交换比较之后，若不相等，再赋给原字符串，进行下一次交换
	char str2[20] = { 0 };
	strcpy(str2, str);
	//待比较字符串
	char str1[20] = "cdeacb";
	//用来记录下待比较字符串的首字符在原字符串的哪个下标出现过
	int arr[20] = { 0 };
	char ch = str1[0];
	if (Num(str, arr, ch)) {
		printf("不相同！\n");
		return 0;
	}
	int size = strlen(str);
	int ret=change(str,str1,str2,arr, ch, size);	
	if (ret == 0) {
		printf("不相同！\n");
	}
	else {
		printf("相同！\n");
	}
	return 0;
}



//最优解：
//其实ABCDE无论怎么旋，旋转后的所有结果，都包含在了ABCDEABCD这个字符串里了。
//所以做法很简单，只需要将原字符串再来一遍接在后面，然后找一找待查找的字符串是不是两倍原字符串的子集即可。
//int findRound(const char* src, char* find)
//{
//	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
//	strcpy(tmp, src); //先拷贝一遍
//	strcat(tmp, src); //再连接一遍
//	return strstr(tmp, find) != NULL; //看看找不找得到
//}