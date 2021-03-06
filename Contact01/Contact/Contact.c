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
		printf("通讯录已满\n");
		return;
	}

	printf("请输入名字：");
	scanf_s("%s", (pc->data[pc->sz].name),MAX_NAME);
	printf("请输入年龄：");
	scanf_s("%hd", &(pc->data[pc->sz].age));
	printf("请输入性别：");
	scanf_s("%s", pc->data[pc->sz].sex,MAX_SEX);
	printf("请输入地址：");
	scanf_s("%s", pc->data[pc->sz].addr,MAX_ADDR);
	printf("请输入电话号码：");
	scanf_s("%d", &(pc->data[pc->sz].tel));
	pc->sz++;

	printf("添加成功\n");
}

void ShowContact(pContact pc)
{
	unsigned int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-5s\n", "name", "age", "sex", "addr", "tel");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-10s\t%-5d\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tel);
	}
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
			(*ppc)->data[i].tel = (*ppc)->data[i + 1].tel;
		}
	}
	if (i == (*ppc)->sz + 1)
	{
		printf("要删除的联系人不存在\n");
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
		printf("通讯录没有可以删除的联系人\n");
		return;
	}

	DelNameEntry(&pc);

}

static unsigned int SearchNameEntry(pContact* ppc)
{
	char name1[MAX_NAME] = { 0 };
	unsigned int i = 0;
	scanf_s("%s", name1, MAX_NAME);

	if ((*ppc)->sz == 0)
	{
		printf("通讯录无可查找的联系人\n");
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

static void PrintCon(pContact pc, unsigned int pos)
{
	if (pos < 0 || pos >= pc->sz)
	{
		printf("位置错误\n");
	}

	printf("%-10s\t%-5s\t%-5s\t%-10s\t%-5s\n", "name", "age", "sex", "addr", "id");
	printf("%-10s\t%-5d\t%-5s\t%-10s\t%-5d\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].addr,
		pc->data[pos].tel);
}

void SearchContact(pContact pc)
{
	int input = 0;
	int pos = 0;
	if (pc->sz == 0)
	{
		printf("通讯录无可查找的联系人\n");
		return;
	}

	pos = SearchNameEntry(&pc);
	if (pos != MAX)
	{
		PrintCon(pc, pos);
	}
	else
	{
		printf("未找到\n");
	}
}

static void ModifyContent(pContact* ppc, unsigned int pos)
{
	printf("请输入修改后的名字：");
	scanf_s("%s", ((*ppc)->data[pos].name), MAX_NAME);
	printf("请输入修改后的年龄：");
	scanf_s("%hd", &((*ppc)->data[pos].age));
	printf("请输入修改后的性别：");
	scanf_s("%s", (*ppc)->data[pos].sex, MAX_SEX);
	printf("请输入修改后的地址：");
	scanf_s("%s", (*ppc)->data[pos].addr, MAX_ADDR);
	printf("请输入修改后的电话号码：");
	scanf_s("%d", &((*ppc)->data[pos].tel));
}

void ModifyContact(pContact pc)
{
	int input = 0;
	unsigned int pos = 0;
	if (pc->sz == 0)
	{
		printf("通讯录无可修改的联系人\n");
		return;
	}

	pos = SearchNameEntry(&pc);
	if (pos != MAX)
	{
		ModifyContent(&pc, pos);
		PrintCon(pc, pos);
	}
}

void SortContact(pContact pc)
{
	pContact tmp = NULL;
	unsigned int i = 0;
	unsigned int j = 0;

	if (0 == pc->sz)
	{
		printf("通讯录为空\n");
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