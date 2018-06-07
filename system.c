#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void D_B(int);
void D_X(int);
void B_D(int);
void B_X(int);
void X_B(char r[], int k);
void X_D(char r[], int k);

void main()
{
	int i, j, k = 0;
	int q;
	char r[10];
	do
	{
		q = 0;
		printf("\n请选择需要被转换的进制:\n0.退出\n1.二进制\n2.十进制\n3.十六进制\n");
		scanf("%d", &i);

		switch(i)
		{
		case 1:
			printf("\n请选择转换后的进制:\n0.退出\n1.二进制\n2.十进制\n3.十六进制\n");
			scanf("%d", &j);
			switch(j)
			{
			case 1:
				printf("\n同进制之间不用转化!\n");
				q = 1;
				break;
			case 2:
				printf("\n请输入您想要转化的数: ");
				scanf("%d", &k);
				B_D(k);
				q = 1;
				break;
			case 3:
				printf("\n请输入您想要转化的数: ");
				scanf("%d", &k);
				B_X(k);
				q = 1;
				break;
			case 0:
				q = 1;
				break;
			}
			break;
		case 2:
			printf("\n请选择转换后的进制:\n0.退出\n1.二进制\n2.十进制\n3.十六进制\n");
			scanf("%d", &j);
			switch(j)
			{
			case 2:
				printf("\n同进制之间不同转化!\n");
				q = 1;
				break;
			case 1:
				printf("\n请输入您想要转化的数: ");
				scanf("%d", &k);
				D_B(k);
				q = 1;
				break;
			case 3:
				printf("\n请输入您想要转化的数: ");
				scanf("%d", &k);
				D_X(k);
				q = 1;
				break;
			case 0:
				q = 1;
				break;
			}
			break;
		case 3:
			printf("\n请选择转换后的进制:\n0.退出\n1.二进制\n2.十进制\n3.十六进制\n");
			scanf("%d", &j);
			switch(j)
			{
			case 3:
				printf("\n同进制之间不用转化!\n");
				q = 1;
				break;
			case 1:
				printf("\n请输入您想要转化的数: ");
				fflush(stdin);
				gets(r);
				for(k = 0; ; k++)
				{
					if(r[k] == '\0')
						break;
				}
				X_B(r, k);
				q = 1;
				break;
			case 2:
				printf("\n请输入您想要转化的数: ");
				fflush(stdin);
				gets(r);
				for(k = 0; ;k++)
				{
					if(r[k] == '\0')
						break;
				}
				X_D(r,k);
				q = 1;
				break;
			case 0:
				q = 1;
				break;
			}
			break;
		case 0:
			printf("\n 谢谢使用 !\n");
		}
	}while(q == 1);
}

void B_D(int a)
{
	int i, s = 0;
	int result = 0;
	for(i = 1; a != 0; i *= 2)
	{
		if(a % 10 > 1)
		{
			s = 1;
			break;
		}
		else
		{
			result += (a % 10) * i;
			a = a / 10;
		}
	}
	if(s == 1)
		printf("您的输入有误!请重新输入\n");
	else
		printf("\n转换后的数为: %d\n", result);
}

void B_X(int a)
{
	int i, j, k, s = 0;
	char p[30];
	int result = 0;
	for(i = 1; a != 0; i *= 2)
	{
		if(a % 10 > 1)
		{
			s = 1;
			break;
		}
		else
		{
			result += (a % 10) * i;
			a = a /10;
		}
	}
	for(j = 0; result != 0; j++)
	{
		p[j] = result % 16;
		result = result / 16;
		if(p[j] >= 10)
		{
			switch(p[j])
			{
			case 10:
				p[j] = 'A';
				break;
			case 11:
				p[j] = 'B';
				break;
			case 12:
				p[j] = 'C';
				break;
			case 13:
				p[j] = 'D';
				break;
			case 14:
				p[j] = 'E';
				break;
			case 15:
				p[j] = 'F';
				break;
			}
		}
		else
			p[j] += 48;
	}
	if(s == 1)
		printf("您输入有误!请重新输入\n");
	else
	{
		printf("\n转换后的数为: ");
		for(k = j - 1; k >= 0; k--)
		{
			printf("%c", p[k]);
		}
		printf("\n");
	}
}

void X_D(char a[], int k)
{
	int i, j, s = 0;
	int result = 0;
	int b[50];
	for(i = 0; i < k; i++)
	{
		if(a[i] <= '9' && a[i] >= '1')
		{
			b[i] = a[i] - 48;
		}
		else
		{
			switch(a[i])
			{
			case 'A':
				b[i] = 10;
				break;
			case 'B':
				b[i] = 11;
				break;
			case 'C':
				b[i] = 12;
				break;
			case 'D':
				b[i] = 13;
				break;
			case 'E':
				b[i] = 14;
				break;
			case 'F':
				b[i] = 15;
				break;
			case 'a':
				b[i] = 10;
				break;
			case 'b':
				b[i] = 11;
				break;
			case 'c':
				b[i] = 12;
				break;
			case 'd':
				b[i] = 13;
				break;
			case 'e':
				b[i] = 14;
				break;
			case 'f':
				b[i] = 15;
				break;
			default:
				s = 1;
			}
		}
	}
	for(i = 1, j = k - 1; j >= 0; j--, i *= 16)
	{
		result += b[j] * i;
	}
	if(s == 1)
		printf("您的输入有误!请重新输入\n");
	else
	{
		printf("\n转换后的数为: %d",result);
	}
}

void X_B(char a[], int k)
{
	int i, j, s = 0;
	int result = 0;
	int b[50];
	int p[30];
	for(i = 0; i < k; i++)
	{
		if(a[i] <= '9' && a[i] >= '1')
			b[i] = a[i] - 9;
		else
		{
			switch(a[i])
			{
			case 'A':
				b[i] = 10;
				break;
			case 'B':
				b[i] = 11;
				break;
			case 'C':
				b[i] = 12;
				break;
			case 'D':
				b[i] = 13;
				break;
			case 'E':
				b[i] = 14;
				break;
			case 'F':
				b[i] = 15;
				break;
			case 'a':
				b[i] = 10;
				break;
			case 'b':
				b[i] = 11;
				break;
			case 'c':
				b[i] = 12;
				break;
			case 'd':
				b[i] = 13;
				break;
			case 'e':
				b[i] = 14;
				break;
			case 'f':
				b[i] = 15;
				break;
			default:
				s = 1;
			}
		}
	}
	for(j = k - 1, i = 1; j >= 0; j--, i *= 16)
	{
		result += b[j] * i;
	}
	for(j = 0; result != 0; j++)
	{
		p[j] = result % 2;
		result = result / 2;
	}
	if(s == 1)
		printf("您的输入有误! 请重新输入\n");
	else
	{
		printf("\n转换后的数为: ");
		for(k = j - 1; k >= 0; k--)
		{
			printf("%d", p[k]);
		}
		printf("\n");
	}
}

void D_B(int a)
{
	int j, k;
	int p[30];
	for(j = 0; a != 0; j++)
	{
		p[j] = a % 2;
		a = a / 2;
	}
	printf("\n 转换后的数为: ");
	for(k = j - 1; k >= 0; k--)
	{
		printf("%d", p[k]);
	}
	printf("\n");
}

void D_X(int a)
{
	int j, k;
	int p[30];
	for(j = 0; a != 0; j++)
	{
		p[j] = a % 16;
		a = a / 16;

		if(p[j] < 10)
			p[j] += 48;
		else
		{
			switch(p[j])
			{
			case 10:
				p[j] = 'A';
				break;
			case 11:
				p[j] = 'B';
				break;
			case 12:
				p[j] = 'C';
				break;
			case 13:
				p[j] = 'D';
				break;
			case 14:
				p[j] = 'E';
				break;
			case 15:
				p[j] = 'F';
				break;
			}
		}
	}
	printf("\n转换后的数为: ");
	for(k = j - 1; k >= 0; k--)
	{
		printf("%c", p[k]);
	}
	printf("\n");
}