#ifndef __CONTACT_H__
#define __CONTACT_H___

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Option
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

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30
#define MAX 1000

typedef struct PeoInfo
{
	char name[MAX_NAME];
	short age;
	char sex[MAX_SEX];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	struct PeoInfo data[MAX];
	int sz;
}Contact, *pContact;

void InitContact(pContact pc);
void AddContact(pContact pc);
void Show(pContact pc);
void DelContact(pContact pc);


#endif //__CONTACT_H__