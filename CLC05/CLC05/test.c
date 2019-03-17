#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//1.��ɲ�������Ϸ��

void meau()
{
	printf("##########################################\n");
	printf("######          1.game             #######\n");
	printf("######          0.exit             #######\n");
	printf("##########################################\n");
}

void GuessNumdersGame()
{
	int input = 0;
	int ret = rand() % 100 + 1;
	while (1)
	{
		printf("���������֣�");
		scanf_s("%d", &input);
		if (input < ret)
		{
			printf("��С��\n");
		}
		else if (input > ret)
		{
			printf("�´���\n");
		}
		else
		{
			printf("��ϲ�㣬��Ϸʤ��\n");
			return;
		}
	}
}

void GuessNumdersGameTest()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		meau();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			GuessNumdersGame();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���벻�Ϸ�\n");
			break;
		}
	} while (input);
}

//2.д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

int BinSearch(int arr[], int key, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) >> 1;            //����һλ�൱�ڳ��� 2
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void BinSearchTest()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	int key = 0;
	int ret = 0;
	printf("������Ҫ���ҵ�����");
	scanf_s("%d", &key);
	ret = BinSearch(arr, key, left, right);
	if (-1 == ret)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ��ˣ��±�Ϊ��%d\n", ret);
	}
}

//3.��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, ������󣬿����������룬����������Ρ����ξ�������ʾ�˳�����
void PoverOn()
{
	char password[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("���������룺>");
		scanf_s("%s", password, sizeof(password));         //��VS2005֮��İ汾�У�΢������scanf_s��������scanf����
														  //�Դ˱���scanf�����߽�����ڴ�й¶��
														  //��ʹ��%c��%s�����ַ����ַ���ʱ��Ӧ�ڵ�ַ�����󸽼�һ���������߽�ֵ��
		if (0 == strcmp(password, "60215"))
		{
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			printf("�������\n");
		}
	}
	if (3 == i)
	{
		return;
	}
}



//4.��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
void CharacterConversion()
{
	int ch = 0;

	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'A'&&ch <= 'Z')
		{
			putchar(ch + 32);
			//putchar(ch+'a'-'A');
		}
		else if (ch >= 'a'&&ch <= 'z')
		{
			putchar(ch - 32);
		}
		else if (ch >= 0 && ch <= 9)
		{
			;
		}
		else
		{
			putchar(ch);
		}
	}
}


int main()
{
	GuessNumdersGameTest();
	BinSearchTest();
	CharacterConversion();
	PoverOn();
	system("pause");
	return 0;
}