#include <stdio.h>
#include <stdlib.h>

//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ�������������
//��һ�������� - a��ѡ��ִ�мӷ���
//�� - s��ѡ��ִ�м�����
//�� - m��ѡ��ִ�г˷���
//�� - d��ѡ��ִ�г�����
//������������Ϊ��������
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3

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

int main(int argc, char* argv[])
{
	int ret = 0;

	if (argc != 4)
	{
		printf("��������argc = %d\n", argc);
		return;
	}

	switch (*(argv[1] + 1))
	{
	case 'a':
		ret = Add(atoi(argv[2]), atoi(argv[3]));  
		//atoiָ��һ���ַ������͵�����ת��Ϊһ��int�͵�����
		break;
	case 's':
		ret = Sub(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'm':
		ret = Mul(atoi(argv[2]), atoi(argv[3]));
		break;
	case 'd':
		ret = Div(atoi(argv[2]), atoi(argv[3]));
		break;
	default:
		printf("��һ����������\n");
		break;
	}
	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}