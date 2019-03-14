#include <stdio.h>
#include <stdlib.h>

//1. �����������α�����ֵ��������ֵ�����ݽ��н�����
void Swap_1(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//2. ����������ʱ���������������������ݣ������⣩
//�Ӽ�����
void Swap_2(int* x, int* y)
{
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
}

void Swap_3(int* x, int* y)
{
	*x = *x^*y;
	*y = *x^*y;
	*x = *x^*y;
}

//3.��10 �����������ֵ��
int Max(int arr[], int size)
{
	int i = 0;
	int max = arr[0];
	for (i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

//4.�����������Ӵ�С�����
void SortPrint()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf_s("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		Swap_2(&a, &b);
	}
	if (a < c)
	{
		Swap_2(&a, &c);
	}
	if (b < c)
	{
		Swap_2(&b, &c);
	}
	printf("%d %d %d\n", a, b, c);
}

//5.�������������Լ����
void MaxCommon(int *x, int *y)
{
	while (*x % *y)
	{
		int tmp = *x % *y;
		*x = *y;
		*y = tmp;
	}
	printf("%d\n", *y);
}

int main()
{
	int a = 10;
	int b = 20;
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	Swap_1(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	Swap_2(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	Swap_3(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	printf("max = %d\n", Max(arr, size));

	SortPrint();

	MaxCommon(&a, &b);

	system("pause");
	return 0;
}
