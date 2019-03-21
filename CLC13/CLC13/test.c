#include<stdio.h>
#include<stdlib.h>

//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，所有偶数位于数组的后半部分。
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
////杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
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
	printf("请输入要查找的数字：");
	scanf_s("%d", &key);
	if (Select(arr, 3, 3, key) == 0)
	{
		printf("未找到\n");
	}
	if (Select(arr, 3, 3, key) != 0)
	{
		printf("找到了\n");
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