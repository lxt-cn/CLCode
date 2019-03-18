#include<stdio.h>
#include<stdlib.h>

#define ROW 30
#define COL 30

//1. 5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//   A选手说：B第二，我第三；
//   B选手说：我第二，E第四；
//   C选手说：我第一，D第二；
//   D选手说：C最后，我第三；
//   E选手说：我第四，A第一；
//   比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
void match()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <= 5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((b == 2 && a != 3) || (b != 2 && a == 3)) &&
							((b == 2 && e != 4) || (b != 2 && e == 4)) &&
							((c == 1 && d != 2) || (c != 1 && d == 2)) &&
							((c == 5 && d != 3) || (c != 5 && d == 3)) &&
							((e == 4 && a != 1) || (e != 4 && a == 1)) &&
							(a != b) && (a != c) && (a != d) && (a != e) &&
							(b != c) && (b != d) && (b != e) &&
							(c != d) && (c != e) &&
							(d != e))
						{
							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
						}
					}
				}
			}
		}
	}
}

//2. 日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//   以下为4个嫌疑犯的供词。
//   A说：不是我。
//   B说：是C。
//   C说：是D。
//   D说：C在胡说
//   已知3个人说了真话，1个人说的是假话。
//   现在请根据这些信息，写一个程序来确定到底谁是凶手。
void prisoner()
{
	int murderer = 0;
	for (murderer = 'A'; murderer <= 'D'; murderer++)
	{
		if ((murderer != 'A') + (murderer == 'C') + (murderer == 'D') + (murderer != 'D') == 3)
		{
			printf("%c\n", murderer);
		}
	}
}

//3. 在屏幕上打印杨辉三角。
void PascalTriangle()
{
	int n = 0;
	int i = 0, j = 0;
	scanf_s("%d", &n);
	int a[ROW][COL] = { 0 };
	for (i = 0; i < n; i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
	}
	for (i = 2; i < n; i++)
	{
		for (j = 1; j < n - 1; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%2d ", a[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	match();
	prisoner();
	PascalTriangle();
	system("pause");
	return 0;
}