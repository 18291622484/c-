#include<stdio.h>
#include<stdlib.h>

//A˵��������
//B˵����C
//C˵����D
//D˵��C�ں�˵

void isMurderer() {
	//ÿ���˶�Ĭ��Ϊ����
	int arr[4] = { 0 };
	int i = 0;
	for (i = 0; i < 4; i++) {
		//�����i+1��Ϊ����
		arr[i] = 1;
		if ((arr[0] != 1) + (arr[2] == 1) + (arr[3] == 1) + (arr[3] != 1) == 3) {
			break;
		}
		//����Ǻ��ˣ��ͻָ�
		else {
			arr[i] = 0;
		}
	}
	printf("�����ǣ�%d\n", i+1);
}

int main() {
	isMurderer();
	return 0;
}