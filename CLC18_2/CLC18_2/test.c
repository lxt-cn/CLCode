#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//п╢ц╟ещеепР©иртеепР╤Ю╦Жвж╥Ш╢╝
void BubbleSort(char **arr, int sz)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz -1 - i; j++)
		{
			if (strcmp(arr[j], arr[j + 1]) < 0)
			{
				char* tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void PrintArr(char **arr, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		printf("%s ", arr[i]);
	}
	printf("\n");
}

int main()
{
	char *arr[] = { "abcdef","opqrst","hijkmn","uvwxyz" };
	int sz = sizeof(arr) / sizeof(arr[0]);
	PrintArr(arr, sz);

	BubbleSort(arr, sz);
	PrintArr(arr, sz);

	system("pause");
	return 0;
}