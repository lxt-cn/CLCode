#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�
void FindTwo(int arr[], int sz)
{
	int num = 0;
	int i = 0;
	int pos = 0;
	int x = 0;
	int y = 0;
	//���
	for (i = 0; i < sz; i++)
	{
		num ^= arr[i];
	}
	//��num�Ķ�������Ϊ1��һ��λpos
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

//2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
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

//3.ģ��ʵ��strcpy
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

//4.ģ��ʵ��strcat
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