#include<stdio.h>
#include<stdlib.h>

//Aѡ��˵��B�ڶ����ҵ�����           �ҵ���
//Bѡ��˵���ҵڶ���E���ģ�            E����
//Cѡ��˵���ҵ�һ��D�ڶ���           D�ڶ�
//Dѡ��˵��C����ҵ�����            C���
//Eѡ��˵���ҵ��ģ�A��һ��           �ҵ���
//����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�

void GuessPlaces(int arr[5],int n) { 
	if (n == 4) {
		/*for (int k = 0; k < 5; k++) {
			printf("%d ", arr[k]);
		}printf("\n");*/

		//Ȼ����������������н��д�ӡ
		if ((arr[1] == 2) + (arr[0] == 3) == 1 && (arr[1] == 2) + (arr[4] == 4) == 1 && (arr[2] == 1) + (arr[3] == 2) == 1 && (arr[2] == 5) + (arr[3] == 3) == 1
			&& (arr[4] == 4) + (arr[0] == 1) == 1) {
			for (int i = 0; i < 5; i++) {
				printf("%d ", arr[i]);
			}printf("\n");
		}
	}
	//���õݹ������˵���������ȫ����
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
	printf("a b c d e����������Ϊ��\n");
	int arr[5] = { 1,2,3,4,5 };
	GuessPlaces(arr,0);
	return 0;
}