#ifndef __CONTACT_H__
#define __CONTACT_H___

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Option1
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	EMPTY
};

enum Option2
{
	NAME = 1,
	ID
};

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX 1000
#define MAX1 30

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
	short age;
	int id;
}PeoInfo;

typedef struct Contact
{
	struct PeoInfo data[MAX];
	unsigned int sz;
}Contact, *pContact;

void InitContact(pContact pc);
void AddContact(pContact pc);
void ShowContact(pContact pc);
void DelContact(pContact pc);
void SearchContact(pContact pc);
void ModifyContact(pContact pc);
void SortContact(pContact pc);
void EmptyContact(pContact pc);

#endif //__CONTACT_H__