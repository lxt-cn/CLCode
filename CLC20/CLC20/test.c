#include <stdio.h>

//�������ʵ��
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("******************************\n");
	printf("***  1��Add        2��Sub  ***\n");
	printf("***  3��Mul        4��Div  ***\n");
	printf("******************************\n");
}
//һ��ʵ�ַ���
void test_1()
{
	int input = 1;
	int x = 0;
	int y = 0;
	int ret = 0;
	while(input)
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("������������������>");
			scanf_s("%d %d", &x, &y);
			ret = Add(x, y);
			printf("ret = %d\n", ret);
			break;
		case 2:
			printf("������������������>");
			scanf_s("%d %d", &x, &y);
			ret = Sub(x, y);
			printf("ret = %d\n", ret);
			break;
		case 3:
			printf("������������������>");
			scanf_s("%d %d", &x, &y);
			ret = Mul(x, y);
			printf("ret = %d\n", ret);
			break;
		case 4:
			printf("������������������>");
			scanf_s("%d %d", &x, &y);
			ret = Div(x, y);
			printf("ret = %d\n", ret);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} 
}

//����ָ�������ʵ��
void test_2()
{
	int input = 1;
	int x = 0;
	int y = 0;
	int ret = 0;
	int(*p[5])(int x, int y) = { 0,Add,Sub,Mul,Div };
	while (input)
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		if (input < 5 && input > 0)
		{
			printf("������������������>");
			scanf_s("%d %d", &x, &y);
			ret = (*p[input])(x, y);
			printf("ret = %d\n", ret);
		}
		else if (input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("�������\n");
		}
	}
}

int main()
{
	//test_1();
	test_2();
	return 0;
}