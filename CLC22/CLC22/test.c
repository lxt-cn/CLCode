#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//1.模拟实现strncpy
char* MyStrncpy(char* dest, const char*src, int n)
{
	char *p = dest;

	assert(dest);
	assert(src);

	while (n--)
	{
		*p++ = *src++;
	}
	return dest;
}

//2.模拟实现strncat
char* MyStrncat(char* dest,const char* src,int n)
{
	char* p = dest;

	assert(dest);
	assert(src);

	while (*p != 0)
	{
		*p++;
	}

	while (n--)
	{
		*p++ = *src++;
	}
	*p = 0;
	return dest;
}

//3.模拟实现strncmp
int MyStrncmp(const char* str1, const char* str2, int n)
{
	assert(str1);
	assert(str2);

	while ((str1 != NULL) && (str2 != NULL) && (n != 0))
	{
		if ((*str1 - *str2) > 0)
		{
			return 1;
		}
		if ((*str1 - *str2) < 0)
		{
			return -1;
		}
		*str1++;
		*str2++;
		n--;
	}
	if (*str1 == 0)
	{
		return -1;
	}
	if (*str2 == 0)
	{
		return 1;
	}
	return 0;
}

int main()
{
	char str1[] = "abcdef";
	char strr1[] = "hello world";
	char str2[20] = "abcdef";
	char strr2[] = "hello world";
	int ret = 0;
	MyStrncpy(str1, strr1, 4);
	printf("%s\n", str1);

	MyStrncat(str2, strr2, 10);
	printf("%s\n", str2);

	ret = MyStrncmp(str2, strr2, 4);
	printf("%d\n", ret);

	system("pause");
	return 0;
}