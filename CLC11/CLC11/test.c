#include<stdio.h>
#include<stdlib.h>

//дһ������Խ�һ�����ֵ�����λ��ż��λ������
#define SWAP_BIT(n) (((n & 0x55555555)<<1) | ((n&0xaaaaaaaa)>>1))

//ʹ�ú�ʵ������������ϴ�ֵ��
#define MAX(m,n) ((m)>(n)?(m):(n))

int main()
{
	/*int a = 0, b = 0;
	printf("������Ҫ��������������");
	scanf_s("%d %d", &a, &b);
	printf("�������������нϴ����Ϊ��%d\n", MAX(a,b));*/
	int num = 10;
	printf("%d\n", SWAP_BIT(num));
	system("pause");
	return 0;
}