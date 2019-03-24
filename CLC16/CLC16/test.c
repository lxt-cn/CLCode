#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//1、使用可变参数，实现函数，求函数参数的平均值
int average(int n, ...)
{
	va_list(arg);
	int i = 0;
	int sum = 0;
	va_start(arg, n);

	for (i = 0; i < n; i++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);
	return sum / n;
}

//2、使用可变参数，实现函数，求函数参数的最大值
int Max(int n, ...)
{
	va_list arg;
	int i = 0;
	int max = 0;
	int tmp = 0;

	va_start(arg, n);

	max = va_arg(arg, int);
	for (i = 1; i < n; i++)
	{
		tmp = va_arg(arg, int);
		if (max < tmp)
		{
			max = tmp;
		}
	}
	va_end(arg);

	return max;
}

//3、模拟实现printf函数，可完成下面的功能
//
//能完成下面的函数调用
//print("s ccc d.\n","hello",'b','i','t',100);
//函数原型：
//print(char *format, ...)
void print_int(int n)
{
	if (n > 9)
	{
		print_int(n / 10);
	}
	putchar(n % 10 + '0');
}

void print(const char *format, ...)
{
	va_list arg;
	va_start(arg, format);

	while (*format)
	{
		switch (*format)
		{
		case 's':
			{
				char *str = va_arg(arg, char*);
				while (*str)
				{
					putchar(*str);
					str++;
				}
			}
			break;
		case 'c':
			{
				char ch = va_arg(arg, char);
				putchar(ch);
			}
			break;
		case 'd':
			{
				int ret = va_arg(arg, int);
				print_int(ret);
			}
			break;
		default:
			putchar(*format);
			break;
		}
		format++;
	}
}

int main()
{
	int avg = 0;
	int max = 0;
	avg = average(4, 1, 2, 3, 4);
	printf("avg = %d\n", avg);
	max = Max(3, 1, 2, 3);
	printf("max = %d\n", max);

	print("s ccc d.\n", "hello", 'b', 'i','t', 100);


	system("pause");
	return 0;
}