#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。
void FindTwo(int arr[], int sz)
{
	int num = 0;
	int i = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	//异或
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//找num的二进制中为1的一个位pos
	for (i = 0; i < 32; i++)
	{
		if (1 == ((num >> i) & 1))
		{
			pos = i;
			break;
		}
	}

	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			x ^= arr[i];
		}
		else
		{
			y ^= arr[i];
		}
	}
	printf("x = %d, y = %d\n", x, y);
}

//2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
int BuySoda(int money)
{
	int total = money;
	int empty = money;

	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;

	}
	return total;
}

//3.模拟实现strcpy
char* MyStrcpy(char* dest, const char* src)
{
	char* ret = dest;

	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//4.模拟实现strcat
char* MyStrcat(char* dest, const char* src)
{
	char* ret = dest;

	assert(dest != NULL);
	assert(src != NULL);

	while(*dest)
	{
		dest++;
	}

	while (*dest++ = *src++)
	{
		;
	}

	return dest;
}

int main()
{
	//int arr[] = { 1,3,8,1,3,8,4,6 };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//FindTwo(arr, sz);

	//int money = 0;
	//int total = 0;
	//scanf_s("%d", &money);
	//total = BuySoda(money);
	//printf("total = %d\n", total);

	//char arr[10] = { 0 };
	//MyStrcpy(arr, "hello");
	//printf("%s\n", arr);

	char arr[20] = "hello";
	MyStrcat(arr, " world");
	printf("%s\n", arr);
	system("pause");
	return 0;
}