#include<stdio.h>
#include<stdlib.h>

#define ROW 30
#define COL 30

//1. 5λ�˶�Ա�μ���10��̨��ˮ����������������Ԥ��������
//   Aѡ��˵��B�ڶ����ҵ�����
//   Bѡ��˵���ҵڶ���E���ģ�
//   Cѡ��˵���ҵ�һ��D�ڶ���
//   Dѡ��˵��C����ҵ�����
//   Eѡ��˵���ҵ��ģ�A��һ��
//   ����������ÿλѡ�ֶ�˵����һ�룬����ȷ�����������Ρ�
void match()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2 && a != 3) || (b != 2 && a == 3)) &&
							((b == 2 && e != 4) || (b != 2 && e == 4)) &&
							((c == 1 && d != 2) || (c != 1 && d == 2)) &&
							((c == 5 && d != 3) || (c != 5 && d == 3)) &&
							((e == 4 && a != 1) || (e != 4 && a == 1)) &&
							(a != b) && (a != c) && (a != d) && (a != e) &&
							(b != c) && (b != d) && (b != e) &&
							(c != d) && (c != e) &&
							(d != e))
						{
							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
}

//2. �ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ����
//   ����Ϊ4�����ɷ��Ĺ��ʡ�
//   A˵�������ҡ�
//   B˵����C��
//   C˵����D��
//   D˵��C�ں�˵
//   ��֪3����˵���滰��1����˵���Ǽٻ���
//   �����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
void prisoner()
{
	int murderer = 0;
	for (murderer = 'A'; murderer <= 'D'; murderer++)
	{
		if ((murderer != 'A') + (murderer == 'C') + (murderer == 'D') + (murderer != 'D') == 3)
		{
			printf("%c\n", murderer);
		}
	}
}

//3. ����Ļ�ϴ�ӡ������ǡ�
void PascalTriangle()
{
	int n = 0;
	int i = 0, j = 0;
	scanf_s("%d", &n);
	int a[ROW][COL] = { 0 };
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 1; j < n - 1; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	match();
	prisoner();
	PascalTriangle();
	system("pause");
	return 0;
}