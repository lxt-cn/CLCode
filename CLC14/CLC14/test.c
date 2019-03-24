#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//

void Reverse(char *str, int left, int right)
{
	while (left < right)
	{
		char tmp = str[left];
		str[left] = str[right];
		str[right] = tmp;
		left++;
		right--;
	}
}

void LeftReverse(char str[], int sz, int n)
{
	int left = 0;
	int right = sz - 1;
	int rcur = right - n;
	int lcur = rcur + 1;
	Reverse(str, left, right);      //整体旋转
	Reverse(str, left, rcur);       //左边旋转
	Reverse(str, lcur, right);      //右边旋转
}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
//
//int IsLeftMove(char* arr, char* p)
//{
//
//	int len1 = strlen(p);
//	int len2 = strlen(arr);
//
//	assert(arr != NULL);
//	assert(p != NULL);
//
//	if (len1 != len2)
//	{
//		return 0;
//	} 
//
//	strncat_s(arr, len2 * 2, arr, len2);
//	if (strstr(arr, p) != NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

int IsLeftMove(char str1[], char str2[]) 
{ 
	int i = 0; 
	int j = 0;   
	int lenght = strlen(str1); 
	for (j = 1; j <= lenght; j++) 
	{
		{         
			int tem = str1[0];     
			for (i = 0; i < lenght - 1; i++)
			{ 
				str1[i] = str1[i + 1];
			}        
			str1[lenght - 1] = tem;  
		}    
		if (0 == strcmp(str1, str2))
		{ return 1; }
	}  
	return 0;
}


int main()
{
	//	char arr[] = "ABCD";
	//	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	//	int n = 0;
	//again:
	//	printf("请输入要左旋转的个数：");
	//	scanf_s("%d", &n);
	//	if ((n >= 0) && (n <= sz))
	//	{
	//		LeftReverse(arr, sz, n);
	//		printf("%s\n", arr);
	//	}
	//	else
	//	{
	//		printf("输入不合法\n");
	//		goto again;
	//	}

	char arr1[10] = "AABCD";
	char arr2[10] = "BCDAA";
	int ret = IsLeftMove(arr1, arr2);
	if(ret == 1)
	{
		printf("是旋转得到的字符串\n");
	}
	else
	{
		printf("不是旋转得到的字符串\n");
	}
	system("pause");
	return 0;
}