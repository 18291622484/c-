#include<stdio.h>
#include<stdlib.h>

int main() {
	int flat = 1;
	double result = 0;
	for (int i = 1; i <= 100; i++) {
		result = result + flat * (1.0 / i);
		flat = -flat;
	}
	printf("��ͽ��Ϊ��%f\n", result);
	return 0;
}