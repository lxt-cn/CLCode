#include<stdio.h>
#include<stdlib.h>

//1.дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1

int CountOneBits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}

void CountOneBitsTest()
{
	unsigned int input = 0;
	printf("������һ���޷���������>");
	scanf_s("%d", &input);
	printf("���Ķ������е�'1'�ĸ���Ϊ��%d\n", CountOneBits(input));
}

//2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
void Get()
{
	int a = 0;
	int i = 0;
	int arr1[16] = { 0 };        //�������λ
	int arr2[16] = { 0 };        //���ż��λ
	printf("����һ��������");
	scanf_s("%d", &a);
	while (i < 32)
	{
		arr1[i / 2] = a % 2;
		a = a >> 1;
		arr2[i / 2] = a % 2;
		a = a >> 1;
		i += 2;
	}
	//��ӡ
	printf("����λ��ɵĶ���������Ϊ��");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr1[i]);
	}
	printf("\nż��λ��ɵĶ���������Ϊ��");
	for (i = 15; i >= 0; i--)
	{
		printf("%d", arr2[i]);
	}
	printf("\n");
}

//3. ���һ��������ÿһλ��
void Every()
{
	int a = 0;
	scanf_s("%d", &a);
	while (a)
	{
		printf("%d\n", a % 10);
		a = a / 10;
	}
}
//4.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
///�������� :
//1999 2299
//������� : 7
int DifferentCount(int x, int y)
{
	int value = 0;
	int count = 0;
	value = x ^ y;
	while (value)
	{
		value = value & (value - 1);
		count++;
	}
	return count;
}

void DifferentCountTest()
{
	int m = 0, n = 0;
	scanf_s("%d %d", &m, &n);
	printf("%d\n", DifferentCount(m, n));
}

int main()
{
	CountOneBitsTest();
	Get();
	Every();
	DifferentCountTest();
	system("pause");
	return 0;
}