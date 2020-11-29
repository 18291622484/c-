#include<stdio.h>
//在32位系统下：
//要拿出奇数位则需要&01010101010101010101010101010101  也就是十六进制的0x55555555
//要拿出偶数位则需要&10101010101010101010101010101010  也就是十六进制的0xaaaaaaaa
//最终将得到的结果相加也就是 |（或） 起来
#define change(num) (((num) & 0x55555555) << 1 | ((num) & 0xaaaaaaaa) >> 1)

int main() {
	int n = 914;
	int arr[32] = { 0 };
	//将914的二进制排列打印出来
	for (int i = 31; i >= 0; i--, n = n >> 1) {
		arr[i] = n & 1;
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
	int num = change(914);
	//将914进行奇数偶数位互换之后的二进制排列打印出来
	for (int i = 31; i >= 0; i--, num = num >> 1) {
		arr[i] = num & 1;
	}
	for (int i = 0; i < 32; i++) {
		printf("%d", arr[i]);
	}
	return 0;
}