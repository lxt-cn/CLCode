#include<stdio.h>
#include<stdlib.h>

//������A�е����ݺ�����B�е����ݽ��н�����������һ����

void SwapArr()
{
	int arr1[5] = { 0,2,4,6,8 };
	int arr2[5] = { 1,3,5,7,9 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	//��ӡ
	printf("arr1[5] = {");
	for (i = 0; i < sz - 1; i++)
	{
		printf("%d,", arr1[i]);
	}
	printf("%d}\narr2[5] = {", arr1[i]);
	for (i = 0; i < sz - 1; i++)
	{
		printf("%d,", arr2[i]);
	}
	printf("%d}\n", arr2[i]);
}

//����1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 ���� + 1 / 99 - 1 / 100 ��ֵ��
void Add()
{
	double i = 0;
	double add1 = 1.0;
	double add2 = 1.0 / 2.0;
	for (i = 3.0; i < 100.0; i += 2.0)
	{
		add1 = add1 + 1.0 / i;
	}
	for (i = 4.0; i <= 100.0; i += 2.0)
	{
		add2 = add2 + 1.0 / i;
	}
	printf("%lf\n", add1 - add2);
}

//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��
void NineCount()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if ((i % 10 == 9 && i < 90) || (i / 10 == 9))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}

int main()
{
	SwapArr();
	Add();
	NineCount();
	system("pause");
	return 0;
}