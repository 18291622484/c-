#include <stdio.h>
#include<stdlib.h>


int MyAdd(int x, int y)
{
	return x + y;
}
int MySub(int x, int y)
{
	return x - y;
}
int MyMul(int x, int y)
{
	return x * y;
}
int MyDiv(int x, int y)
{
	return x / y;
}
int main()
{

	printf("�������������� ");
	int x = 0;
	int y = 0;
	scanf_s("%d %d", &x, &y);
	char op = 'x';
	printf("\n ��ѡ��һ��������<+-*/>:\n");
	//����%cǰ��ӿո���Ϊ�˴�����һ������ʱ���ڼ���������֮�����Ļس����������ӣ���op��Ϊ�س���
	scanf_s(" %c", &op);
	if ('+' == op)
	{
		printf("%d + %d = %d\n", x, y, MyAdd(x, y));
	}
	else if ('-' == op)
	{
		printf("%d - %d = %d\n", x, y, MySub(x, y));
	}
	else if ('*' == op)
	{
		printf("%d * %d = %d\n", x, y, MyMul(x, y));
	}
	else if ('/' == op)
	{
		if (y != 0)
		{
			printf("%d / %d = %d\n", x, y, MyDiv(x, y));
		}
		else
		{
			printf("��������Ϊ�㣡��\n");
		}
	}
	else {
		printf("�������󣡣�\n");
	}



	return 0;
}

