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
	pc->sz++;

	printf("添加成功\n");
}

void Show(pContact pc)
{
	int i = 0;
	printf("%-10s\t%-5d\t%-5s\t%-10s\t\n", "name", "age", "sex", "addr");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-10s\t\n", 
			pc->data[i].name, 
			pc->data[i].age, 
			pc->data[i].sex, 
			pc->data[i].addr);
	}
}

static int FindEntry(pContact pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(pContact pc)
{
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	if (pc->sz == 0)
	{
		printf("没有信息可以删除\n");
		return;
	}

	printf("请输入要删除的人的名字：>");
	scanf_s("%s", name, MAX_NAME);
	//查找这个人
	pos = FindEntry(pc, name);
	if (pos == -1)
	{
		printf("删除的人不存在\n");
		return;
	}
	else
	{
		unsigned int i = 0;
		for (i = pos; i < pc->sz-1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}
		pc->sz--;
		printf("删除成功\n");
	}
}
