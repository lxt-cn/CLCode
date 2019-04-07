#include "Contact.h"

void menu()
{
	printf("**************************************\n");
	printf("***       1��Add       2��Del      ***\n");
	printf("***       3��Search    4��Modify   ***\n");
	printf("***       5��Show      6��Sort     ***\n");
	printf("***       7��Empty     0��Exit     ***\n");
	printf("**************************************\n");
}

int main()
{
	int input = 0;
	Contact my_con;
	InitContact(&my_con);
	do
	{
		menu();
		printf("��ѡ��>");
		scanf_s("%d", &input);
		switch(input)
		{
		case ADD:
			AddContact(&my_con);
			break;
		case DEL:
			DelContact(&my_con);
			break;
		case SEARCH:
			break;
		case MODIFY:
			break;
		case SHOW:
			Show(&my_con);
			break;
		case SORT:
			break;
		case EMPTY:
			break;
		case EXIT:
			printf("�˳�\n");
			break;
		default:
			printf("���벻�Ϸ�������������\n");
			break;
		}
	} while (input);
	return 0;
}