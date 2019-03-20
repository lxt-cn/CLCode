#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832
//
unsigned int reverse_bit(unsigned int value)
{
	unsigned int va = 0;
	int ret = 0;
	int count = 31;
	while (count)
	{
		ret = value & 1;
		va ^= ret;
		va <<= 1;
		value >>= 1;
		count--;
	}
	return va;
}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//
int Average_1(int x, int y)
{
	int c = (x + y) >> 1;     //有溢出问题
	return c;
}

int Average_2(int x, int y)
{
	int c = y + ((x - y) >> 1);
	return c;
}

int Average_3(int x, int y)
{
	int c = (x&y) + ((x^y) >> 1);
	return c;
}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
void Alone()
{
	int a[] = { 1,2,3,4,5,4,3,2,1 };
	int b = a[0];
	int i = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 1; i < sz; i++)
	{
		b ^= a[i];
	}
	printf("%d\n", b);
}

//4.
//有一个字符数组的内容为:"student a am i", 请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。

//实现求字符串长度
static int my_strlen(const char *str)
{
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}

//旋转
static void ReverseArr(char *left, char *right)
{
	while (left < right)
	{
		int tmp = *right;
		*right = *left;
		*left = tmp;
		right--;
		left++;
	}
}

void ReverseStr(char *str)
{
	assert(str);

	char *right = str + my_strlen(str) - 1;
	char *left = str;
	char *cur = str;

	ReverseArr(left, right);     //i ma a tneduts

	while (*cur)
	{
		char* start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		ReverseArr(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
}

void ReverseStrTest()
{
	char a[] = "student a am i";
	ReverseStr(a);
	printf("%s\n", a);
}


int main()
{
	//printf("%d\n", Average_1(1, 2));
	//printf("%d\n", Average_2(1, 2));
	//printf("%d\n", Average_3(1, 2));

	//printf("%u\n",reverse_bit(25));

	//Alone();

	ReverseStrTest();
	system("pause");
	return 0;
}