#include<stdio.h>
#include<stdlib.h>

//A说：不是我
//B说：是C
//C说：是D
//D说：C在胡说

void isMurderer() {
	//每个人都默认为好人
	int arr[4] = { 0 };
	int i = 0;
	for (i = 0; i < 4; i++) {
		//假设第i+1个为凶手
		arr[i] = 1;
		if ((arr[0] != 1) + (arr[2] == 1) + (arr[3] == 1) + (arr[3] != 1) == 3) {
			break;
		}
		//如果是好人，就恢复
		else {
			arr[i] = 0;
		}
	}
	printf("凶手是：%d\n", i+1);
}

int main() {
	isMurderer();
	return 0;
}