#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//  输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
void ClcDisp(int key)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= key; i++)
	{
		for (j = 1; j <= key; j++)
		{
			printf("%2d*%2d=%3d ", i, j, i*j);
		}
		printf("\n");
	}
}

void ClcDispTest()
{
	int key = 0;
	printf("请输入乘法口诀表的行数：");
	scanf_s("%d", &key);
	ClcDisp(key);
}

//2.使用函数实现两个数的交换。
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void SwapTest()
{
	int x = 0;
	int y = 0;
	scanf_s("%d %d", &x, &y);
	Swap(&x, &y);
	printf("x=%d,y=%d\n", x, y);
}

//3.实现一个函数判断year是不是润年。
int LeapYear(int year)
{
	if (year % 4 == 0 && year != 0)
	{
		return 1;
	}
	if (year % 100 == 0)
	{
		return 1;
	}
	return 0;
}

void LeapYearTest()
{
	int year = 0;
	scanf_s("%d", &year);
	int key = LeapYear(year);
	if (key)
	{
		printf("%d年是闰年\n", year);
		return;
	}
	printf("%d年不是闰年\n", year);
}

//4.创建一个数组，
//  实现函数init（）初始化数组、
//  实现empty（）清空数组、
//  实现reverse（）函数完成数组元素的逆置。
//  要求：自己设计函数的参数，返回值。

void Init(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = i + 1;
	}
}

void Reverse(int *arr, int left, int right)
{
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

void Empty(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

void PrintArr(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%2d ", arr[i]);
	}
	printf("\n");
}

void Test()
{
	int arr[20] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;

	Init(arr, sz);
	PrintArr(arr, sz);

	Reverse(arr, left, right);
	PrintArr(arr, sz);

	Empty(arr, sz);
	PrintArr(arr, sz);
}

//5.实现一个函数，判断一个数是不是素数。
int IsPrime(int key)
{
	int i = 0;
	for (i = 2; i < key; i++)
	{
		if (key % i == 0)
		{
			return -1;
		}
	}
	if (i == key)
	{
		return 1;
	}

}

void IsPrimeTest()
{
	int key = 0;
	int ret = 0;
	while (1)
	{
		printf("请输入需要判断是否为素数的数字：");
		scanf_s("%d", &key);
		if (key < 0)
		{
			printf("输入不合法\n");
		}
		else
		{
			break;
		}
	}
	ret = IsPrime(key);
	if (ret == 1)
	{
		printf("%d是素数\n", key);
	}
	else
	{
		printf("%d不是素数\n", key);
	}
}

int main()
{
	ClcDispTest();
	SwapTest();
	LeapYearTest();
	Test();
	IsPrimeTest();
	system("pause");
	return 0;
}