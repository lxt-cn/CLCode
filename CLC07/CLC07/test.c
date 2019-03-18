#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//  ����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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
	printf("������˷��ھ����������");
	scanf_s("%d", &key);
	ClcDisp(key);
}

//2.ʹ�ú���ʵ���������Ľ�����
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

//3.ʵ��һ�������ж�year�ǲ������ꡣ
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
		printf("%d��������\n", year);
		return;
	}
	printf("%d�겻������\n", year);
}

//4.����һ�����飬
//  ʵ�ֺ���init������ʼ�����顢
//  ʵ��empty����������顢
//  ʵ��reverse���������������Ԫ�ص����á�
//  Ҫ���Լ���ƺ����Ĳ���������ֵ��

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

//5.ʵ��һ���������ж�һ�����ǲ���������
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
		printf("��������Ҫ�ж��Ƿ�Ϊ���������֣�");
		scanf_s("%d", &key);
		if (key < 0)
		{
			printf("���벻�Ϸ�\n");
		}
		else
		{
			break;
		}
	}
	ret = IsPrime(key);
	if (ret == 1)
	{
		printf("%d������\n", key);
	}
	else
	{
		printf("%d��������\n", key);
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