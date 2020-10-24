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

	printf("请输入两个数： ");
	int x = 0;
	int y = 0;
	scanf_s("%d %d", &x, &y);
	char op = 'x';
	printf("\n 请选择一个操作符<+-*/>:\n");
	//这里%c前面加空格是为了处理上一步输入时，在键入两个数之后键入的回车键，若不加，则op就为回车键
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
			printf("除数不能为零！！\n");
		}
	}
	else {
		printf("输入有误！！\n");
	}



	return 0;
}

