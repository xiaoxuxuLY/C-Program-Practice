#include<stdio.h>
#include<time.h>
#include<Windows.h>
void guess(int n);
main()
{
	int i, n;
	while(1)
	{
		printf("1.Start game?(y/n)\n");
		printf("2.Rule\n");
		printf("3.Exit\n");
		printf("please choose:");
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			printf("please input n:\n");
			scanf("%d", &n);
			guess(n);
			Sleep(5);
			break;
		case 2:
			printf("step1:input the number of digits\n");
			printf("step2:input the number, separated by a space between two numbers\n");
			printf("setp3:A represent location and data are correct\n");
			printf("\tB represent data is correct but location is wrong!\n");
			Sleep(10);
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}
}

void guess(int n)
{
	int acount, bcount, i, j, k=0, flag, a[10], b[10];
	do
	{
		flag = 0;
		srand((unsigned)time(NULL));
		for(i = 0; i < n; i++)
			a[i] = rand() % 10;
		for(i = 0; i < n - 1; i++)
		{
			for(j = i + 1; j < n; j++)
				if(a[i] == a[j])
				{
					flag = 1;
					break;
				}
		}
	}while(flag == 1);
	do
	{
		k++;
		acount = 0;
		bcount = 0;
		printf("guess:");
		for(i = 0; i < n; i++)
			scanf("%d", &b[i]);
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
			{
				if(a[i] == b[i])
				{
					acount++;
					break;
				}
				if(a[i] == b[i] && i != j)
				{
					bcount++;
					break;
				}
			}
			printf("clue on:%d A %d B \n\n", acount, bcount);
			if(acount == n)
			{
				if(k == 1)
					printf("you are the topmost rung of Fortune's ladder!!\n\n");
				else if (k <= 5)
					printf("you are genius!!\n\n");
				else if (k <= 10)
					printf("you are cleaver!!\n\n");
				else 
					printf("you need try hard!!\n\n");
				break;
			}
	}while(1);
}