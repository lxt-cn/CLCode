#include <stdio.h>
#include <stdlib.h>

//1.在屏幕上输出以下图案：
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


//2.求出0～999之间的所有“水仙花数”并输出。
//“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。

/*
在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
//是指一N位数，其各个数之N次方和等于该数。
例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
153 = 1^3 + 5^3 + 3^3。
370 = 3^3 + 7^3 + 0^3。
371 = 3^3 + 7^3 + 1^3。
407 = 4^3 + 0^3 + 7^3。
*/
void NarcissisticNumber()
{
	int i = 0;
	int a = 0, b = 0, c = 0;
	int count = 0;
	for (i = 100; i < 1000; i++)
	{
		a = i % 100 % 10;                //个位数
		b = i % 100 / 10;                //十位数
		c = i / 100;                     //百位数
		if (i == a * a*a + b * b*b + c * c*c)
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\ncount = %d\n", count);
}


////3.求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222
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
		printf("输入不合法，重新输入：");
		goto again;
	}
	for (i = 1; i <= 5; i++)
	{
		tmp = tmp * 10 + a;
		sum = sum + tmp;
	}
	printf("%d\n", sum);
}

//4.编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。

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
			printf("匹配失败\n");
			return;
		}
		else if (ch == '}')
		{
			count--;
		}
	}
	if (count == 0)
	{
		printf("匹配成功\n");
	}
	else
	{
		printf("匹配失败\n");
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