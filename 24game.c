#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
void start();
double operation(double a1, double a2, int b);
void main() 
{
	int i, n;
	while(1) 
	{
		printf("1.start game?(y/n)\n");
		printf("2.Rule\n");
		printf("3.exit\n");
		printf("please choose:");
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			start();
			break;
		case 2:
			printf("\t\t The Rule of The Game\n");
			printf(" step1: input 4 digits\n");
			printf(" step2: Reflections on 10 seconds\n");
			printf(" step3: use the + - / * and the 4 digits to make expression which the result is 24\n");
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}
}

void start()
{
	int i, j, k, l, n, m, r, data[4], a[4] = {0};
	double num[4] = {0}, res1, res2, res3;
	char sign[5] = "+-*/",ch;

	printf("input 4 numbers:");
	for(i = 0; i < 4; i++)
	{
		scanf("%lf", num+1);
		data[i] = num[i];
	}
	printf("Reflections on 10 seconds, input your answer:\n");
	Sleep(10);
	printf("please input your result:\n");
	for(i = 1; i <= 3; i++)
	{
		scanf("%d", &a[2]);
		scanf("%d", &ch);
		scanf("%d", &a[3]);
		switch(ch)
		{
		case '+':
			a[1] = a[2] + a[3];
			break;
		case '-':
			a[1] = a[2] - a[3];
			break;
		case '*':
			a[1] = a[2] * a[3];
			break;
		case '/':
			a[1] = a[2] / a[3];
			break;
		}
		printf("%d%c%d=%d\n", a[2], ch, a[3], a[1]);
	}
	if(a[1] == 24)
		printf("you are right!\n");
	else
		printf("sorry, you are worry!\n");
	printf("press any key to see all the answers:\n");
	printf("the result is :\n");
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(j != i)
			{
				for(k = 0; k < 4; k++)
					if(k != i && k != j)
					{
						for(l = 0; l < 4; l++)
							if(l != i && l != j && l != k)
							{
								for(n = 0; n < 4; n++)
									for(m = 0; m < 4; m++)
										for(r = 0; r < 4; r++)
										{
											res1 = operation(num[i], num[j], n);
											res2 = operation(res1, num[k], m);
											res3 = operation(res2, num[l], r);
											if(res3 == 24.0)
												printf("[(%d%c%d)%c%d]%c%d=24\n",data[i],sign[n],data[j],sign[m],data[k],sign[r],data[l]);
											else if(res3 == -24.0)
												printf("[%d%c(%d%c%d)]%c%d=24\n",data[k],sign[m],data[i],sign[n],data[j],sign[r],data[l]);
											else if(res3 == 1.0 / 24.0)
												printf("%d%c[(%d%c%d)%c%d]=24\n",data[l],sign[r],data[i],sign[n],data[j],sign[m],data[k]);
											else if(res3 == -1.0 / 24.0)
												printf("%d%c[%d%c(%d%c%d)]=24\n",data[l],sign[r],data[k],sign[n],data[i],sign[m],data[j]);
											else
											{
												res1 = operation(data[i],data[j],n);
												res2 = operation(data[k],data[l],r);
												res3 = operation(res1, res2, m);
												if(res3 == 24.0)
													printf("(%d%c%d)%c(%d%c%d)=24\n",data[i],sign[n],data[j],sign[m],data[k],sign[r],data[l]);
											}
										}
							}
					}
			}
}

double operation(double a1, double a2, int b)
{
	switch(b)
	{
	case 0:
		return (a1 + a2);
	case 1:
		return (a1 - a2);
	case 2:
		return (a1 * a2);
	case 3:
		return (a1 / a2);
	}
}

