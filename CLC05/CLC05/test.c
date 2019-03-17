#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//1.完成猜数字游戏。

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
		printf("请输入数字：");
		scanf_s("%d", &input);
		if (input < ret)
		{
			printf("猜小了\n");
		}
		else if (input > ret)
		{
			printf("猜大了\n");
		}
		else
		{
			printf("恭喜你，游戏胜利\n");
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
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			GuessNumdersGame();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入不合法\n");
			break;
		}
	} while (input);
}

//2.写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回 - 1.（折半查找）

int BinSearch(int arr[], int key, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = (right + left) >> 1;            //右移一位相当于除以 2
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
	printf("请输入要查找的数：");
	scanf_s("%d", &key);
	ret = BinSearch(arr, key, left, right);
	if (-1 == ret)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标为：%d\n", ret);
	}
}

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
void PoverOn()
{
	char password[10] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：>");
		scanf_s("%s", password, sizeof(password));         //在VS2005之后的版本中，微软定义了scanf_s用来代替scanf函数
														  //以此避免scanf不检查边界造成内存泄露。
														  //在使用%c和%s读入字符或字符串时，应在地址参数后附加一个缓冲区边界值。
		if (0 == strcmp(password, "60215"))
		{
			printf("登录成功！\n");
			break;
		}
		else
		{
			printf("密码错误。\n");
		}
	}
	if (3 == i)
	{
		return;
	}
}



//4.编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
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