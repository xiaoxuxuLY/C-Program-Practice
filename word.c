#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void tianjia(struct word str[100], int &count); //往词库中添加词组
void shuchu(struct word str[100], int &count);  //输出词库中所有的词组
void fanyi1(struct word str[100], int &count);
void fanyi2(struct word str[100], int &count);
void chaxun(int point, int count1);

struct word //定义word结构体, 里面的成员分别放英语单词和对应的汉语翻译
{
	char chinese[20];
	char english[20];
};

int point = 0;  //统计分数
int count1 = 0; //测试次数
void main()
{
	int count = 0;
	struct word str[100];
	int n;
	char ch, chioch;

	while(1)
	{
		printf("*********************背单词系统*****************************\n");
		printf("*********************1.添加词库*****************************\n");
		printf("*********************2.汉译英*******************************\n");
		printf("*********************3.英译汉*******************************\n");
		printf("*********************4.输出所有词库**************************\n");
		printf("*********************5.成绩查询******************************\n");
		printf("*********************0.退出**********************************\n");
		printf("*************************************************************\n");
		printf("请输入你要进行的操作");
		scanf("%d",&n);
		switch(n)
		{
		case 1: 
			tianjia(str, count);
			break;
		case 2:
			fanyi1(str, count);
			break;
		case 3:
			fanyi2(str, count);
			break;
		case 4:
			shuchu(str, count);
			break;
		case 5:
			chaxun(point, count1);
			break;
		case 0:
			{
				printf("你确认要退出吗? y/n!!\n");
				scanf("%c%c", &ch, &chioch);
				if(ch == 'y' || ch == 'Y')
					exit(0);
			}
		default:
			printf("你输入了错误的操作,无法执行!!!");
			exit(0);
		}
	}
}

void tainjia(struct word str[100], int &count)
{
	char ch;
	do {
		printf("录入词库!!!\n");
		printf("请输入词库中的英语单词:\n");
		scanf("%s", str[count].english);
		printf("请输入相应的中文意思:\n");
		scanf("%s", str[count].chinese);
		count++;
		printf("是否继续录入?y/n!!!\n");
		scanf("%s", &ch);
	}while(ch == 'y');
	printf("%d\n\n", count);
}

void shuchu(struct word str[100], int &count)
{
	int i = 0;
	printf("输出词库中所有的单词!!!\n");
	if(count <= 0)
	{
		printf("没有任何单词, 无法输出!!!\n");
		return;
	}
	else
	{
		for(i = 0; i < count; i++)
		{
			printf("英文单词是:%s", str[i].english);
			printf("\n 相应的中文意思是:%s", str[i].chinese);
			printf("\n\n");
		}
		printf("词库所有单词输入完毕!!!\n");
	}
}

void fanyi1(struct word str[100], int &count)
{
	int i;
	char ch[20];
	char bh[20];
	printf("请输入英文单词:\n");
	scanf("%s", ch);
	printf("请输入翻译后的中文:\n");
	scanf("%s", bh);
	for(i = 0; i < count; i++)
	{
		if(strcmp(ch, str[i].english) == 0)
		{
			if(strcmp(bh, str[i].chinese) == 0)
			{
				point++;
				count1++;
				printf("恭喜你!!答对了!!!\n");
			}
			else
			{
				count1++;
				printf("很遗憾,答错了!!!正确的翻译是: %s\n", str[i].chinese);
			}
		}
	}
}

void fanyi2(struct word str[100], int &count)
{
	int i;
	char ch[20];
	char bh[20];
	printf("请输入中文:\n");
	scanf("%s", ch);
	printf("请输入翻译后的英文:\n");
	scanf("%s", bh);
	for(i = 0; i < count; i++)
	{
		if(strcmp(ch, str[i].chinese) == 0)
		{
			if(strcmp(bh, str[i].english) == 0)
			{
				point++;
				count1++;
				printf("恭喜你!!答对了!!!\n");
			}
			else
			{
				count1++;
				printf("很遗憾,答错了!!!正确的翻译是: %s\n", str[i].english);
			}
		}
	}
}
void chaxun(int point, int count1)
{
	printf("本次测试的成绩是:\n");
	printf("总共:%d个\n",count1);
	printf("正确:%d个\n",point);
}
