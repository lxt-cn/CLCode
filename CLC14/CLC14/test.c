#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
	Reverse(str, left, right);      //������ת
	Reverse(str, left, rcur);       //�����ת
	Reverse(str, lcur, right);      //�ұ���ת
}

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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
	//	printf("������Ҫ����ת�ĸ�����");
	//	scanf_s("%d", &n);
	//	if ((n >= 0) && (n <= sz))
	//	{
	//		LeftReverse(arr, sz, n);
	//		printf("%s\n", arr);
	//	}
	//	else
	//	{
	//		printf("���벻�Ϸ�\n");
	//		goto again;
	//	}

	char arr1[10] = "AABCD";
	char arr2[10] = "BCDAA";
	int ret = IsLeftMove(arr1, arr2);
	if(ret == 1)
	{
		printf("����ת�õ����ַ���\n");
	}
	else
	{
		printf("������ת�õ����ַ���\n");
	}
	system("pause");
	return 0;
}