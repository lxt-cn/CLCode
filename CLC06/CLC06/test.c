#include<stdio.h>
#include<stdlib.h>

//1.写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1

int CountOneBits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}

void CountOneBitsTest()
{
	unsigned int input = 0;
	printf("请输入一个无符号整数：>");
	scanf_s("%d", &input);
	printf("它的二进制中的'1'的个数为：%d\n", CountOneBits(input));
}

//2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
void Get()
{
	int a = 0;
	int i = 0;
	int arr1[16] = { 0 };        //存放奇数位
	int arr2[16] = { 0 };        //存放偶数位
	printf("输入一个整数：");
	scanf_s("%d", &a);
	while (i < 32)
	{
		arr1[i / 2] = a % 2;
		a = a >> 1;
		arr2[i / 2] = a % 2;
		a = a >> 1;
		i += 2;
	}
	//打印
	printf("奇数位组成的二进制序列为：");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	printf("\n偶数位组成的二进制序列为：");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
}

//3. 输出一个整数的每一位。
void Every()
{
	int a = 0;
	scanf_s("%d", &a);
	while (a)
	{
		printf("%d\n", a % 10);
		a = a / 10;
	}
}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
///输入例子 :
//1999 2299
//输出例子 : 7
int DifferentCount(int x, int y)
{
	int value = 0;
	int count = 0;
	value = x ^ y;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}

void DifferentCountTest()
{
	int m = 0, n = 0;
	scanf_s("%d %d", &m, &n);
	printf("%d\n", DifferentCount(m, n));
}

int main()
{
	CountOneBitsTest();
	Get();
	Every();
	DifferentCountTest();
	system("pause");
	return 0;
}