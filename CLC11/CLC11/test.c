#include<stdio.h>
#include<stdlib.h>

//写一个宏可以将一个数字的奇数位和偶数位交换。
#define SWAP_BIT(n) (((n & 0x55555555)<<1) | ((n&0xaaaaaaaa)>>1))

//使用宏实现两个数中求较大值。
#define MAX(m,n) ((m)>(n)?(m):(n))

int main()
{
	/*int a = 0, b = 0;
	printf("请输入要交换的两个数：");
	scanf_s("%d %d", &a, &b);
	printf("交换后两个数中较大的数为：%d\n", MAX(a,b));*/
	int num = 10;
	printf("%d\n", SWAP_BIT(num));
	system("pause");
	return 0;
}