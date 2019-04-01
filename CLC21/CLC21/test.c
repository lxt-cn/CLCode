#include <stdio.h>
#include <stdlib.h>


//qsort函数的使用

////比较函数
//int cmp_int(const void* e1, const void* e2)   //e1、e2分别表示一个要比较的整型的地址
//{
//	return *(int*)e1 - *(int*)e2;   /*  e1是void *类型，不能对它直接进行运算，
//	                                    故强制类型转换为int*,再解引用，
//										得到它存储的地址对应的值；e2同理   */
//}
//
//struct S
//{
//	char name[20];
//	int age;
//};
//
//int cmp_s_name(const void* e1, const void* e2)
//{
//	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
//}
//
//int cmp_s_age(const void* e1, const void* e2)
//{
//	return ((struct S*)e1)->age - ((struct S*)e2)->age;
//}


/*   一般冒泡排序
void BubbleSort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
*/


//模拟实现qsort(冒泡的方式)
int int_cmp(const void* p1, const void* p2)
{
	return (*(int*)p1 > *(int*)p2);
}

void Swap(void *p1, void *p2, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp = *((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2 + i) = tmp;
	}
}

void UBubbleSort(void *base, int count, int size, int(*cmp)(void*, void*))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * size, (char*)base + (j + 1)*size) > 0)
			{
				Swap((char*)base + j * size, (char*)base + (j + 1)*size, size);
			}
		}
	}
}
int main()
{
	//int arr1[] = { 1,3,5,7,9,2,4,6,8,0 };
	//int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	//struct S arr[] = { {"zhangsan",21},{"lisi",20},{"wangwu",21} };
	//int sz = sizeof(arr) / sizeof(arr[0]);
	//qsort(arr1, sz1, sizeof(arr1[0]),cmp_int);
	//qsort(arr, sz, sizeof(arr[0]),cmp_s_name);

	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	UBubbleSort(arr, sz, sizeof(int), int_cmp);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}