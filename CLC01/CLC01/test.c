#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1. ��ӡ100~200 ֮�������
void Prime_1()
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}

void Prime_2()
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i / 2; j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j == i / 2)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}

void Prime_3()
{
	int i = 0;
	int j = 0;
	int count = 0;

	for (i = 101; i < 200; i += 2)           //����һ��������
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
			{
				break;
			}
		}
		if (j > sqrt(i))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}

//2. ����˷��ھ���
void ClcDisp()
{
	int i = 0;
	int j = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			printf("%2d*%2d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
}

//3. �ж�1000��-- - 2000��֮�������
void LeapYear()
{
	int i = 0;
	int count = 0;
	for (i = 1000; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}

int main()
{
	Prime_1();
	Prime_2();
	Prime_3();
	ClcDisp();
	LeapYear();

	system("pause");
	return 0;
}