#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//1、strlen
//计数法
int MyStrlen_1(const char* str)
{
	int count = 0;
	assert(str != NULL);

	while (*str++)
	{
		count++;
	}
	return count;
}

//递归
int MyStrlen_2(const char* str)
{
	assert(str != NULL);

	if (*str == '\0')
	{
		return 0;
	}
	return 1 + MyStrlen_2(str + 1);
}

//指针
int MyStrlen_3(char* str)
{
	char *p = str;
	assert(str != NULL);

	while (*p)
	{
		p++;
	}
	return p - str;
}

//2、strcpy
char* MyStrcpy(char* dest, const char* src)
{
	char* ret = dest; 
	assert(dest != NULL);
	assert(src != NULL);

	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//3、strcat
char* MyStrcat(char *dest, const char *src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

//4、strstr
char* MyStrstr(const char* str, const char* substr)
{
	char *s1 = NULL;
	char *s2 = (char*)substr;
	char *cur = (char*)str;
	assert(str != NULL);
	assert(substr != NULL);

	if (*substr == '\0')
	{
		return (char*)str;
	}

	while (*cur)
	{
		s1 = cur;
		s2 = substr;
		while(*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;
		}
		cur++;
	}
	return NULL;
}

//5、strcmp
int MyStrcmp_1(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);

	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int MyStrcmp_2(const char* str1, const char* str2)
{
	int ret = 0;
	assert(str1 != NULL);
	assert(str2 != NULL);

	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1)
	{
		++str1;
		++str2;
	}
	if (ret < 1)
	{
		return - 1;
	}
	else if (ret > 1)
	{
		return 1;
	}
	return ret;
}

//6、memcpy
void* MyMemcpy(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

//7、memmove
void* MyMemmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	if (dest < src)
	{
		//前 --> 后
		while(count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		//后 --> 前
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	return ret;
}


int main()
{
//strlen_test
	char *p = "abcdef";
	printf("%d\n", MyStrlen_1(p));
	printf("%d\n", MyStrlen_2(p));
	printf("%d\n", MyStrlen_3(p));
	printf("%d\n", strlen(p));

//strcpy_test
	//char arr1[20] = { 0 };
	//MyStrcpy(arr1, "lxt");
	//printf("%s\n", arr1);

//strcat_test
	//char arr2[20] = "Hello ";
	//MyStrcat(arr2, "World");
	//printf("%s\n", arr2);

//strcmp_test
	//char *p = "abcdef";
	//char *q = "abbbbbbbb";
	////int ret = MyStrcmp_1(p, q);
	//int ret = MyStrcmp_2(p, q);
	//if (ret == 0)
	//{
	//	printf("p = q\n");
	//}
	//else if (ret > 0)
	//{
	//	printf("p > q\n");
	//}
	//else
	//{
	//	printf("p < q\n");
	//}

//strstr_test
	//const char *str1 = "abbbbbbbbcdef";
	//char *ret = MyStrstr(str1, "bbc");
	//if (ret == NULL)
	//{
	//	printf("不存在\n");
	//}
	//else
	//{
	//	printf("%s\n", ret);
	//}

//memcpy_test
	//int arr1[10] = { 0 };
	//int arr2[] = { 1,2,3,4,5 };
	//MyMemcpy(arr1, arr2, 20);

//memmove_test
	//int arr1[10] = { 1,2,3,4,5,6,7,8,9,0 };
	//MyMemmove(arr1 + 2, arr1, 16);

	system("pause");
	return 0;
}
