#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void LeftString(char* str,int size,int num) {
	int i = 0;
	for (i = 0; i < num; i++) {
		str[size+i] = str[i];
		str[size + 1 + i] = '\0';
	}
	for (int j = i; str[j] != '\0'; j++) {
		printf("%c", str[j]);
	}printf("\n");
}

int Size(char* str) {
	int ret = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		ret++;
	}
	return ret;
}

int main() {
	//可以将第一个取出，然后将后面的字符前移，然后把取出的字符放到末位，以此类推；但是较麻烦，
	//所以，我采用字符串空间只要足够大，前面交换到后面的字符就不会越界，也可以实现目的
	char str[20] = "abcde";
	int size = Size(str);
	//printf("%d", size);
	printf("%s\n", str);
	printf("输入要左旋转多少字符：");
	int num = 0;
	scanf("%d", &num);
	LeftString(str, size, num);

	//验证如果将前面的字符直接放到‘\0’的位置上
	//并且不在后面附上‘\0’那么后面会出现乱码
	/*str[9] = 'j';
	printf("%s", str);*/
	return 0;
}



//或者还有一个方法：
//先将要左旋的前三个家伙逆序（CBADEFG），然后将后半段也逆序（CBAGFED），最后整体逆序（DEFGABC）即可。
//这样只需要做数值交换即可，可以写一个函数帮我们完成局部逆序，代码如下：
//void reverse_part(char* str, int start, int end) //将字符串从start到end这一段逆序
//{
//	int i, j;
//	char tmp;
//
//	for (i = start, j = end; i < j; i++, j--)
//	{
//		tmp = str[i];
//		str[i] = str[j];
//		str[j] = tmp;
//	}
//}
//
//void leftRound(char* src, int time)
//{
//	int len = strlen(src);
//	int pos = time % len;
//	reverse_part(src, 0, pos - 1); //逆序前段
//	reverse_part(src, pos, len - 1); //逆序后段
//	reverse_part(src, 0, len - 1); //整体逆序
//}