#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//1���ݹ�ͷǵݹ�ֱ���� n ��쳲�������
//�ݹ�
int Fib_1(int n)
{
	if (n <= 0)
	{
		return -1;
	}
	if (n <= 2 && n > 0)
	{
		return 1;
	}
	else
	{
		return Fib_1(n-1) + Fib_1(n - 2);
	}
}

//�ǵݹ�
int Fib_2(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	if (n <= 0)
	{
		return -1;
	}
	if (n <= 2 && n > 0)
	{
		return 1;
	}
	while ((n--) - 2)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

//2����дһ������ʵ�� n^k��ʹ�õݹ�ʵ��
int Power(int n, int k)
{
	if (0 == k)
	{
		return 1;
	}
	else
	{
		return n * Power(n, k - 1);
	}
}

//3��дһ���ݹ麯�� DigitSum(n) ,����һ���Ǹ����������������������֮��
// eg:DigitSum(1729),����19
int DigitSum(int n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return n % 10 + DigitSum(n / 10);
	}
}

//4����дһ������reverse_string(char* string)
//   ʵ�֣��������ַ����е��ַ���������
//   Ҫ�󣺲���ʹ��C�������е��ַ�����������
int MyStrlen(const char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + MyStrlen(str + 1);
	}
}
void reverse_string(char* str)
{
	int len = MyStrlen(str);
	char tmp = *str;

	assert(str != NULL);

	if (len == 0)
	{
		return;
	}

	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (MyStrlen(str + 1) > 1)
	{
		reverse_string(str + 1);
	}
	*(str + len - 1) = tmp;
}

//5���ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ݹ�
int MyStrlen_1(const char* str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + MyStrlen(str + 1);
	}
}

//�ǵݹ�
int MyStrlen_2(const char* str)
{
	int count = 0;
	while(*str)
	{
		count++;
		str++;
	}
	return count;
}

//6���ݹ�ͷǵݹ�ֱ�ʵ���� n �Ľ׳�
//�ݹ�
int Factorial_1(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n * Factorial_1(n - 1);
	}
}

int Factorial_2(int n)
{
	int ret = 1;
	while (n > 1)
	{
		ret *= n;
		n--;
	}
	return ret;
}

//7���ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d ", n % 10);
}

int main()  
{
	//int n = 0;
	//int ret = 0;
	//scanf_s("%d", &n);
	//ret = Fib_1(n);
	//printf("%d\n", ret);
	//ret = Fib_2(n);
	//printf("%d\n", ret);

	//int n = 0;
	//int k = 0;
	//int ret = 0;
	//scanf_s("%d %d", &n, &k);
	//ret = Power(n, k);
	//printf("%d\n", ret);

	//int ret = 0;
	//ret = DigitSum(1729);
	//printf("%d\n", ret);

	//char arr[] = "abcdef";
	//reverse_string(arr);
	//printf("%s\n", arr);

	//const char* p = "abcdef";
	//int len = MyStrlen_1(p);
	//printf("%d\n", len);
	//len = MyStrlen_2(p);
	//printf("%d\n", len);

	//int n = 0;
	//int ret = 0;
	//scanf_s("%d", &n);
	//ret = Factorial_1(n);
	//printf("%d\n", ret);
	//ret = Factorial_2(n);
	//printf("%d\n", ret);

	int num = 0;
	scanf_s("%d", &num);
	Print(num);

	system("pause");
	return 0;
}