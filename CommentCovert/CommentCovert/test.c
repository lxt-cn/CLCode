#include "CommentConvert.h"

void test()
{
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
	pfIn = fopen("input.c", "r");
	if (NULL == pfIn)
	{
		perror("open file for read");
		exit(EXIT_FAILURE);
	}
	pfOut = fopen("output.c", "w");
	if (NULL == pfOut)
	{
		perror("open file for read");
		fclose(pfIn);
		pfIn = NULL;
		exit(EXIT_FAILURE);
	}

	//×¢ÊÍ×ª»»
	CommentConvert(pfIn, pfOut);

	fclose(pfIn);
	pfIn = NULL;
	fclose(pfOut);
	pfOut = NULL;
}

int main()
{
	test();
	return 0;
}