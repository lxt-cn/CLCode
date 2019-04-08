#include "Contact.h"

void InitContact(pContact pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(pContact pc)
{
	if (pc->sz == MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}

	printf("���������֣�");
	scanf_s("%s", (pc->data[pc->sz].name),MAX_NAME);
	printf("���������䣺");
	scanf_s("%hd", &(pc->data[pc->sz].age));
	printf("�������Ա�");
	scanf_s("%s", pc->data[pc->sz].sex,MAX_SEX);
	printf("�������ַ��");
	scanf_s("%s", pc->data[pc->sz].addr,MAX_ADDR);
	printf("������ѧ�ţ�");
	scanf_s("%d", &(pc->data[pc->sz].id));
	pc->sz++;

	printf("��ӳɹ�\n");
}

void ShowContact(pContact pc)
{
	unsigned int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-5s\n", "name", "age", "sex", "addr", "id");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-10s\t%-5d\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].id);
	}
}

static void menu1()
{
	printf("----------------------------\n");
	printf("---   1��Name   2��Id    ---\n");
	printf("---        0��Exit       ---\n");
	printf("----------------------------\n");
}

static void DelNameEntry(pContact* ppc)
{
	char name1[MAX_NAME] = { 0 };
	unsigned int i = 0;
	scanf_s("%s", name1, MAX_NAME);
	
	for (i = 0; i < (*ppc)->sz; i++)
	{
		if (strcmp((*ppc)->data[i].name, name1) == 0)
		{
			strcpy_s((*ppc)->data[i].addr, MAX_ADDR, (*ppc)->data[i + 1].addr);
			strcpy_s((*ppc)->data[i].name, MAX_NAME, (*ppc)->data[i + 1].name);
			strcpy_s((*ppc)->data[i].sex, MAX_SEX, (*ppc)->data[i + 1].sex);
			(*ppc)->data[i].age = (*ppc)->data[i + 1].age;
			(*ppc)->data[i].id = (*ppc)->data[i + 1].id;
		}
	}
	if (i == (*ppc)->sz + 1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		(*ppc)->sz--;
	}
}

static void DelIdEntry(pContact* ppc)
{
	int id1 = 0;
	unsigned int i = 0;
	scanf_s("%d", &id1);

	for (i = 0; i < (*ppc)->sz; i++)
	{
		if ((*ppc)->data[i].id == id1)
		{
			strcpy_s((*ppc)->data[i].addr, MAX_ADDR, (*ppc)->data[i + 1].addr);
			strcpy_s((*ppc)->data[i].name, MAX_NAME, (*ppc)->data[i + 1].name);
			strcpy_s((*ppc)->data[i].sex, MAX_SEX, (*ppc)->data[i + 1].sex);
			(*ppc)->data[i].age = (*ppc)->data[i + 1].age;
			(*ppc)->data[i].id = (*ppc)->data[i + 1].id;
		}
	}
	if (i == (*ppc)->sz + 1)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
	}
	else
	{
		(*ppc)->sz--;
	}
}

void DelContact(pContact pc)
{
	char name[MAX_NAME] = { 0 };
	int input = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼û�п���ɾ������ϵ��\n");
		return;
	}

	do
	{
		menu1();
		printf("��ѡ��Ҫɾ�����˵���Ϣ��������ѧ����ѡ��һ��>\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case NAME:
			DelNameEntry(&pc);
			break;
		case ID:
			DelIdEntry(&pc);
			break;
		case EXIT:
			printf("ȡ��ɾ��\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
		if (input <= 5 && input >= 1)
		{
			input = 0;
		}
	} while (input);
}

static unsigned int SearchNameEntry(pContact* ppc)
{
	char name1[MAX_NAME] = { 0 };
	unsigned int i = 0;
	scanf_s("%s", name1, MAX_NAME);

	if ((*ppc)->sz == 0)
	{
		printf("ͨѶ¼�޿ɲ��ҵ���ϵ��\n");
		return MAX;
	}

	for (i = 0; i < (*ppc)->sz; i++)
	{
		if (strcmp((*ppc)->data[i].name, name1) == 0)
		{
			return i;
		}
	}
	return MAX;
}

static unsigned int SearchIdEntry(pContact* ppc)
{
	int id1 = 0;
	unsigned int i = 0;
	scanf_s("%d", &id1);

	if ((*ppc)->sz == 0)
	{
		printf("ͨѶ¼�޿ɲ��ҵ���ϵ��\n");
		return MAX;
	}

	for (i = 0; i < (*ppc)->sz; i++)
	{
		if ((*ppc)->data[i].id == id1)
		{
			return i;
		}
	}
	return MAX;
}

static void PrintCon(pContact pc, unsigned int pos)
{
	if (pos < 0 || pos >= pc->sz)
	{
		printf("λ�ô���\n");
	}

	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-5s\n", "name", "age", "sex", "addr", "id");
	printf("%-10s\t%-5d\t%-5s\t%-10s\t%-5d\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].id);
}
void SearchContact(pContact pc)
{
	int input = 0;
	int pos = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼�޿ɲ��ҵ���ϵ��\n");
		return;
	}

	do 
	{
		menu1();
		printf("��ѡ��Ҫ���ҵ���ϵ�˵���Ϣ��������ѧ����ѡ��һ��>\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case NAME:
			pos = SearchNameEntry(&pc);
			break;
		case ID:
			pos = SearchIdEntry(&pc);
			break;
		case EXIT:
			printf("ȡ������\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
		if (pos != MAX)
		{
			PrintCon(pc, pos);
		}
		if (input == 1 || input == 2)
		{
			input = 0;
		}
	} while (input);
}

static void ModifyContent(pContact* ppc, unsigned int pos)
{
	printf("�������޸ĺ�����֣�");
	scanf_s("%s", ((*ppc)->data[pos].name), MAX_NAME);
	printf("�������޸ĺ�����䣺");
	scanf_s("%hd", &((*ppc)->data[pos].age));
	printf("�������޸ĺ���Ա�");
	scanf_s("%s", (*ppc)->data[pos].sex, MAX_SEX);
	printf("�������޸ĺ�ĵ�ַ��");
	scanf_s("%s", (*ppc)->data[pos].addr, MAX_ADDR);
	printf("�������޸ĺ��ѧ�ţ�");
	scanf_s("%d", &((*ppc)->data[pos].id));
}

void ModifyContact(pContact pc)
{
	int input = 0;
	unsigned int pos = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼�޿��޸ĵ���ϵ��\n");
		return;
	}

	do
	{
		menu1();
		printf("��ѡ��Ҫ�޸ĵ���ϵ�˵���Ϣ��������ѧ����ѡ��һ��>\n");
		scanf_s("%d", &input);

		switch (input)
		{
		case NAME:
			pos = SearchNameEntry(&pc);
			break;
		case ID:
			pos = SearchIdEntry(&pc);
			break;
		case EXIT:
			printf("ȡ���޸�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
		if (pos != MAX)
		{
			ModifyContent(&pc, pos);
			PrintCon(pc, pos);
		}
		if (input == 1 || input == 2)
		{
			input = 0;
		}
	} while (input);
}

void SortContact(pContact pc)
{
	pContact tmp = NULL;
	unsigned int i = 0;
	unsigned int j = 0;

	if (0 == pc->sz)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	for (i = 0; i < pc->sz - 1; i++)
	{
		for (j = 0; j < pc->sz - i - 1; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo peo = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = peo;
			}
		}
	}
}

void EmptyContact(pContact pc)
{
	InitContact(pc);
}