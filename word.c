#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void tianjia(struct word str[100], int &count); //���ʿ�����Ӵ���
void shuchu(struct word str[100], int &count);  //����ʿ������еĴ���
void fanyi1(struct word str[100], int &count);
void fanyi2(struct word str[100], int &count);
void chaxun(int point, int count1);

struct word //����word�ṹ��, ����ĳ�Ա�ֱ��Ӣ�ﵥ�ʺͶ�Ӧ�ĺ��﷭��
{
	char chinese[20];
	char english[20];
};

int point = 0;  //ͳ�Ʒ���
int count1 = 0; //���Դ���
void main()
{
	int count = 0;
	struct word str[100];
	int n;
	char ch, chioch;

	while(1)
	{
		printf("*********************������ϵͳ*****************************\n");
		printf("*********************1.��Ӵʿ�*****************************\n");
		printf("*********************2.����Ӣ*******************************\n");
		printf("*********************3.Ӣ�뺺*******************************\n");
		printf("*********************4.������дʿ�**************************\n");
		printf("*********************5.�ɼ���ѯ******************************\n");
		printf("*********************0.�˳�**********************************\n");
		printf("*************************************************************\n");
		printf("��������Ҫ���еĲ���");
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
				printf("��ȷ��Ҫ�˳���? y/n!!\n");
				scanf("%c%c", &ch, &chioch);
				if(ch == 'y' || ch == 'Y')
					exit(0);
			}
		default:
			printf("�������˴���Ĳ���,�޷�ִ��!!!");
			exit(0);
		}
	}
}

void tainjia(struct word str[100], int &count)
{
	char ch;
	do {
		printf("¼��ʿ�!!!\n");
		printf("������ʿ��е�Ӣ�ﵥ��:\n");
		scanf("%s", str[count].english);
		printf("��������Ӧ��������˼:\n");
		scanf("%s", str[count].chinese);
		count++;
		printf("�Ƿ����¼��?y/n!!!\n");
		scanf("%s", &ch);
	}while(ch == 'y');
	printf("%d\n\n", count);
}

void shuchu(struct word str[100], int &count)
{
	int i = 0;
	printf("����ʿ������еĵ���!!!\n");
	if(count <= 0)
	{
		printf("û���κε���, �޷����!!!\n");
		return;
	}
	else
	{
		for(i = 0; i < count; i++)
		{
			printf("Ӣ�ĵ�����:%s", str[i].english);
			printf("\n ��Ӧ��������˼��:%s", str[i].chinese);
			printf("\n\n");
		}
		printf("�ʿ����е����������!!!\n");
	}
}

void fanyi1(struct word str[100], int &count)
{
	int i;
	char ch[20];
	char bh[20];
	printf("������Ӣ�ĵ���:\n");
	scanf("%s", ch);
	printf("�����뷭��������:\n");
	scanf("%s", bh);
	for(i = 0; i < count; i++)
	{
		if(strcmp(ch, str[i].english) == 0)
		{
			if(strcmp(bh, str[i].chinese) == 0)
			{
				point++;
				count1++;
				printf("��ϲ��!!�����!!!\n");
			}
			else
			{
				count1++;
				printf("���ź�,�����!!!��ȷ�ķ�����: %s\n", str[i].chinese);
			}
		}
	}
}

void fanyi2(struct word str[100], int &count)
{
	int i;
	char ch[20];
	char bh[20];
	printf("����������:\n");
	scanf("%s", ch);
	printf("�����뷭����Ӣ��:\n");
	scanf("%s", bh);
	for(i = 0; i < count; i++)
	{
		if(strcmp(ch, str[i].chinese) == 0)
		{
			if(strcmp(bh, str[i].english) == 0)
			{
				point++;
				count1++;
				printf("��ϲ��!!�����!!!\n");
			}
			else
			{
				count1++;
				printf("���ź�,�����!!!��ȷ�ķ�����: %s\n", str[i].english);
			}
		}
	}
}
void chaxun(int point, int count1)
{
	printf("���β��Եĳɼ���:\n");
	printf("�ܹ�:%d��\n",count1);
	printf("��ȷ:%d��\n",point);
}
