#include<stdio.h>
#include<stdlib.h>

//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ�������������������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
void Print(int *arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void Sort(int *arr, int sz)
{
	int right = sz - 1;
	int left = 0;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		int tmp = arr[right];
		arr[right] = arr[left];
		arr[left] = tmp;
	}
}
//2.
//
////���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
int Select(int arr[3][3], int row, int col, int key)
{
	int x = 0;
	int y = col - 1;
	while ((x < row) && (y >= 0))
	{
		if (arr[x][y] == key)
		{
			return 1;
		}
		else if (arr[x][y] > key)
		{
			y--;
		}
		else
		{
			x++;
		}
	}
	return 0;
}

void SelectTest()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int key = 0;
	printf("������Ҫ���ҵ����֣�");
	scanf_s("%d", &key);
	if (Select(arr, 3, 3, key) == 0)
	{
		printf("δ�ҵ�\n");
	}
	if (Select(arr, 3, 3, key) != 0)
	{
		printf("�ҵ���\n");
	}
}
int main()
{
	/*int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Sort(arr, sz);
	Print(arr, sz);*/
	SelectTest();
	system("pause");
	return 0;
}