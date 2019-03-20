#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//
unsigned int reverse_bit(unsigned int value)
{
	unsigned int va = 0;
	int ret = 0;
	int count = 31;
	while (count)
	{
		ret = value & 1;
		va ^= ret;
		va <<= 1;
		value >>= 1;
		count--;
	}
	return va;
}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//
int Average_1(int x, int y)
{
	int c = (x + y) >> 1;     //���������
	return c;
}

int Average_2(int x, int y)
{
	int c = y + ((x - y) >> 1);
	return c;
}

int Average_3(int x, int y)
{
	int c = (x&y) + ((x^y) >> 1);
	return c;
}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
void Alone()
{
	int a[] = { 1,2,3,4,5,4,3,2,1 };
	int b = a[0];
	int i = 0;
	int sz = sizeof(a) / sizeof(a[0]);
	for (i = 1; i < sz; i++)
	{
		b ^= a[i];
	}
	printf("%d\n", b);
}

//4.
//��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

//ʵ�����ַ�������
static int my_strlen(const char *str)
{
	int count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return count;
}

//��ת
static void ReverseArr(char *left, char *right)
{
	while (left < right)
	{
		int tmp = *right;
		*right = *left;
		*left = tmp;
		right--;
		left++;
	}
}

void ReverseStr(char *str)
{
	assert(str);

	char *right = str + my_strlen(str) - 1;
	char *left = str;
	char *cur = str;

	ReverseArr(left, right);     //i ma a tneduts

	while (*cur)
	{
		char* start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		ReverseArr(start, cur - 1);
		if (*cur == ' ')
		{
			cur++;
		}
	}
}

void ReverseStrTest()
{
	char a[] = "student a am i";
	ReverseStr(a);
	printf("%s\n", a);
}


int main()
{
	//printf("%d\n", Average_1(1, 2));
	//printf("%d\n", Average_2(1, 2));
	//printf("%d\n", Average_3(1, 2));

	//printf("%u\n",reverse_bit(25));

	//Alone();

	ReverseStrTest();
	system("pause");
	return 0;
}