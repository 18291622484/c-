#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//用法：将字符串里的数字字符转化为整形数。返回整形值。
//注意：转化时跳过前面的不可见字符，直到遇上数字或正负符号才开始做转换，
//      而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。

int myAtoi(const char* str) {
	char TS[1024] = { 0 };
	char* ts = TS;
	//设置符号位，用来判定这样的情况：不见可字符，数字，不可见字符，数字
	//如果前面为不可见字符，在遇到数字后，flag1就++，这样就不会进入后面的不可见字符
	int flag1 = 0;
	//外部循环判定前面的 数字、正负号、不可见字符
	while ((*str > 47 && *str < 58)||((*str==43||*str==45)&&flag1==0)||(*str>=0&&*str<=32&&flag1==0)) {
		//内部循环判定出现数字之后的 不可见字符、正负号
		if ((*str > 47 && *str < 58)||((*str == 43 || *str == 45))) {
			*ts = *str;
			ts++;
			str++;
			flag1++;
		}
		else {
			str++;
		}
	}
	*ts = '\0';
	int i = 0;
	//设置符号位，如果是‘-’，那么flag就加一
	int flag = 0;
	if (TS[i] == 45) {
		i++;
		flag++;
	}
	int ret = 0;
	while (TS[i] != '\0') {
		ret += (TS[i] - 48);
		ret *= 10;
		i++;
	}
	ret /= 10;
	//将数字筛选出来转换成对应的整形之后，如果flag==1，那么就让数字减去自己的二倍，即可获得对应数字的负值
	if (flag == 1) {
		return ret - ret * 2;
	}
	//如果flag==0，那么正常输出转化好的数字
	return ret;
}

int main() {
	printf("输入一串字符串：\n");
	char str[1024] = { 0 };
	int i = 0;
	char c = 0;
	scanf("%c", &c);
	while (c != '\n') {
		str[i] = c;
		scanf("%c", &c);
		i++;
	}
	printf("%s\n", str);

	int ret = myAtoi(str);
	printf("%d\n", ret);

	/*int a = atoi("  123 123jklb");
	printf("%d\n", a);*/
	return 0;
}