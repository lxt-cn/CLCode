#include <stdio.h>
#include <stdlib.h>

//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，
//第一个参数“ - a”选项执行加法，
//“ - s”选项执行减法，
//“ - m”选项执行乘法，
//“ - d”选项执行除法，
//后面两个参数为操作数。
//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main(int argc, char* argv[])
{
	int ret = 0;

	if (argc != 4)
	{
		printf("参数有误，argc = %d\n", argc);
		return;
	}

	switch (*(argv[1] + 1))
	{
	case 'a':
		ret = Add(atoi(argv[2]), atoi(argv[3]));  
		//atoi指把一个字符串类型的数据转换为一个int型的数据
		break;
	case 's':
		ret = Sub(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'm':
		ret = Mul(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'd':
		ret = Div(atoi(argv[2]), atoi(argv[3]));
		break;
	default:
		printf("第一个参数有误\n");
		break;
	}
	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}