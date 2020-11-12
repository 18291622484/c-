#include<stdio.h>
#include<stdlib.h>

//A选手说：B第二，我第三；           我第三
//B选手说：我第二，E第四；            E第四
//C选手说：我第一，D第二；           D第二
//D选手说：C最后，我第三；            C最后
//E选手说：我第四，A第一；           我第四
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。

void GuessPlaces(int arr[5],int n) { 
	if (n == 4) {
		/*for (int k = 0; k < 5; k++) {
			printf("%d ", arr[k]);
		}printf("\n");*/

		//然后对满足条件的排列进行打印
		if ((arr[1] == 2) + (arr[0] == 3) == 1 && (arr[1] == 2) + (arr[4] == 4) == 1 && (arr[2] == 1) + (arr[3] == 2) == 1 && (arr[2] == 5) + (arr[3] == 3) == 1
			&& (arr[4] == 4) + (arr[0] == 1) == 1) {
			for (int i = 0; i < 5; i++) {
				printf("%d ", arr[i]);
			}printf("\n");
		}
	}
	//利用递归对五个人的排名进行全排列
	else {
		for (int i = n; i < 5; i++) {
			int t = 0;
			t = arr[n]; arr[n] = arr[i]; arr[i] = t;
			GuessPlaces(arr, n+1);
			t = arr[n]; arr[n] = arr[i]; arr[i] = t;
		}
	}
}


int main() {
	printf("a b c d e的名次依次为：\n");
	int arr[5] = { 1,2,3,4,5 };
	GuessPlaces(arr,0);
	return 0;
}