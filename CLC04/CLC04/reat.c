#include <stdio.h>
#include <stdlib.h>

//1.����Ļ���������ͼ����
//**
//***
//*****
//*******
//*********
//***********
//*************
//***********
//*********
//*******
//*****
//***
//*
void print()
{
	char arr1[] = "***************";
	char arr2[] = "               ";
	int sz = sizeof(arr1) / sizeof(arr1[0]) - 1;
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];
		arr1[i] = ' ';
		printf("%s\n", arr2);
	}
	for (i = sz - 1; i >= 0; i--)
	{
		arr2[i] = arr1[i];
		printf("%s\n", arr2);
	}
}


//2.���0��999֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ����λ�������λ���ֵ�������ȷ�õ��ڸ��������磻153��1��5��3 ? ����153��һ����ˮ�ɻ�������

/*
�������У�ˮ�ɻ�����Narcissistic number��Ҳ��Ϊ������������������ķ˹׳����ķ˹��������Armstrong number����
//��ָһNλ�����������֮N�η��͵��ڸ�����
����153��370��371��407������λ����ˮ�ɻ������������֮�����͵��ڸ�����
153 = 1^3 + 5^3 + 3^3��
370 = 3^3 + 7^3 + 0^3��
371 = 3^3 + 7^3 + 1^3��
407 = 4^3 + 0^3 + 7^3��
*/
void NarcissisticNumber()
{
	int i = 0;
	int a = 0, b = 0, c = 0;
	int count = 0;
	for (i = 100; i < 1000; i++)
	{
		a = i % 100 % 10;                //��λ��
		b = i % 100 / 10;                //ʮλ��
		c = i / 100;                     //��λ��
		if (i == a * a*a + b * b*b + c * c*c)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}


////3.��Sn = a + aa + aaa + aaaa + aaaaa��ǰ5��֮�ͣ�����a��һ�����֣����磺2 + 22 + 222 + 2222 + 22222
void FiveAdd()
{
	int a = 0;
	int i = 0;
	int tmp = 0;
	int sum = 0;
again:
	scanf_s("%d", &a);
	if (a < 0 || a>9)
	{
		printf("���벻�Ϸ����������룺");
		goto again;
	}
	for (i = 1; i <= 5; i++)
	{
		tmp = tmp * 10 + a;
		sum = sum + tmp;
	}
	printf("%d\n", sum);
}

//4.��дһ���������ӱ�׼�����ȡCԴ���룬����֤���еĻ����Ŷ���ȷ�ĳɶԳ��֡�

void IsPairing()
{
	int ch = 0;
	int count = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
		{
			count++;
		}
		else if (ch == '}' && count == 0)
		{
			printf("ƥ��ʧ��\n");
			return;
		}
		else if (ch == '}')
		{
			count--;
		}
	}
	if (count == 0)
	{
		printf("ƥ��ɹ�\n");
	}
	else
	{
		printf("ƥ��ʧ��\n");
	}
}

int main()
{
	print();
	NarcissisticNumber();
	FiveAdd();
	IsPairing();
	system("pause");
	return 0;
}