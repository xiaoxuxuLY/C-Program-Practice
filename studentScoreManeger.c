#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int shoudsave = 0;
struct student
{
	char num[10];
	char name[20];
	int cgrade;
	int mgrade;
	int egrade;
	int totle;
	int ave;
};
typedef struct node
{
	struct student data;
	struct node *next;
}Node, *Link;

void menu()
{
	printf("*********************************************\n");
	printf("\t1输入学生资料\t\t\t\t\t2删除学生资料\n");
	printf("\t3查询学生资料\t\t\t\t\t4修改学生资料\n");
	printf("\t5显示学生资料\t\t\t\t\t6统计学生成绩\n");
	printf("\t7排序学生成绩\t\t\t\t\t8保存学生资料\n");
	printf("\t9获取帮助信息\t\t\t\t\t0退出系统\n");
	printf("**********************************************\n");
}

void printstart()
{
	printf("----------------------------------------------\n");
}

void Wrong()
{
	printf("\n=====>提示:输入错误!\n");
}

void Nofind()
{
	printf("\n=====>提示:没有找到该学生!\n");
}

void printc()
{
	printf("	学号\t	姓名		英语成绩		数学成绩		C语言成绩	总分		平均分\n");
}

void printe(Node *p)
{
	printf("%-12s%s\t%d\t%d\t%d\t	%d\t	%d\n", p->data.num, p->data.name, p->data.egrade, p->data.mgrade, p->data.cgrade, p->data.totle, p->data.ave);
}

Node *Locate(Link l,  char findmess[], char nameornum[])
{
	Node *r;
	if(strcmp(nameornum, "num") == 0)
	{
		r = l->next;
		while(r)
		{
			if(strcmp(r->data.num, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	else if(strcmp(nameornum, "name") == 0)
	{
		r = l->next;
		while(r)
		{
			if(strcmp(r->data.name, findmess) == 0)
				return r;
			r = r->next;
		}
	}
	return 0;
}

void Add(Link l)
{
	Node *p, *r, *s;
	char num[10];
	r = l;
	s = l->next;
	while(r->next != NULL)
		r = r->next;
	while(1)
	{
		printf("请你输入学号(以'0'返回上一级菜单:)");
		scanf("%s", num);
		getchar();
		if(strcmp(num, "0") == 0)
			break;
		while(s)
		{
			if(strcmp(s->data.num, num) == 0)
			{
				printf("========>提示:学号为'%s'的学生已经存在,若要修改请你选择'4修改'!\n", num);
				printstart();
				printc();
				printe(s);
				printstart();
				printf("\n");
				return;
			}
			s = s->next;
		}
		p = (Node *) malloc(sizeof(Node));
		strcpy(p->data.num, num);
		printf("请你输入姓名:");
		scanf("%s", p->data.name);
		getchar();
		printf("请你输入c语言成绩:");
		scanf("%d", &p->data.cgrade);
		getchar();
		printf("请你输入数学成绩:");
		scanf("%d", &p->data.mgrade);
		getchar();
		printf("请你输入英语成绩:");
		scanf("%d", &p->data.egrade);
		getchar();
		p->data.totle = p->data.egrade + p->data.cgrade + p->data.mgrade;
		p->data.ave = p->data.totle / 3;
		
		p->next = NULL;
		r->next = p;
		r = p;
		shoudsave = 1;
	}
}
void Qur(Link l)
{
	int sel;
	char findmess[20];
	Node *p;
	if(!l->next)
	{
		printf("\n====>提示:没有资料可以查询!\n");
		return;
	}
	printf("\n====>1按学号查找\n====>2按姓名查找\n");
	scanf("%d", &sel);
	if(sel == 1)
	{
		printf("请你输入要查找的学号:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if(p)
		{
			printf("\t\t\t\t查找结果\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else
			Nofind();
	}
	else if(sel == 2)
	{
		printf("请你输入要查找的姓名:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if(p)
		{
			printf("\t\t\t\t查找结果\n");
			printstart();
			printc();
			printe(p);
			printstart();
		}
		else 
			Nofind();
	}
	else
		Wrong();
}

void Del(Link l)
{
	int sel;
	Node *p, *r;
	char findmess[20];
	if(!l->next)
	{
		printf("\n=====>提示:没有资料可以删除!\n");
		return;
	}
	printf("\n=====>1按学号删除\n=====>2按姓名删除\n");
	scanf("%d", &sel);
	if(sel == 1)
	{
		printf("请你输入要删除的学号:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if(p)
		{
			r = l;
			while(r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>提示:该学生已经成功删除!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else if(sel == 2)
	{
		printf("请你输入要删除的姓名:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if(p)
		{
			r = l;
			while(r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n======>提示:该学生已经成功删除!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else
		Wrong();
}

void Modify(Link l)
{
	Node *p;
	char findmess[20];
	if(!l->next)
	{
		printf("\n=======>提示:没有资料可以修改!\n");
		return;
	}
	printf("请你输入要修改的学生学号:");
	scanf("%s", findmess);
	p = Locate(l, findmess, "num");
	if(p)
	{
		printf("请你输入新的c语言成绩(原来是%d分):", p->data.cgrade);
		scanf("%d", &p->data.cgrade);
		printf("\n======>提示:资料修改成功!\n");
		shoudsave = 1;
	}
	else
		Nofind();
}

void Disp(Link l)
{
	int count = 0;
	Node *p;
	p = l->next;
	if(!p)
	{
		printf("\n=====>提示:没有资料可以显示!\n");
		return;
	}
	printf("\t\t\t\t显示结果\n");
	printstart();
	printc();
	printf("\n");
	while(p)
	{
		printe(p);
		p = p->next;
	}
	printstart();
	printf("\n");
}

void Save(Link l)
{
	FILE *fp;
	Node *p;
	int flag = 1, count = 0;
	fp = fopen("c:\\student", "wb");
	if(fp == NULL)
	{
		printf("\n======>提示:重新打开文件时发生错误!\n");
		exit(1);
	}
	p = l->next;
	while(p)
	{
		if(fwrite(p, sizeof(Node), 1, fp) == 1)
		{
			p = p->next;
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{
		printf("\n======>提示:文件保存成功.(有%d条记录已经保存.)\n", count);
		shoudsave = 0;
	}
	fclose(fp);
}

void stastic(Link l)
{
	Node *p;
	int n, c[3][5] = {0};
	int cmax, cmin, mmax, mmin, emax, emin;
	if(!l->next)
	{
		printf("\n======>提示:没有资料可以统计!\n");
		return;
	}
	p = l->next;
	cmax = p->data.cgrade;
	cmin = p->data.cgrade;
	mmax = p->data.mgrade;
	mmin = p->data.mgrade;
	emax = p->data.egrade;
	emin = p->data.egrade;
	while(p)
	{
		if(p->data.cgrade > cmax)
			cmax = p->data.cgrade;
		if(p->data.mgrade > mmax)
			mmax = p->data.mgrade;
		if(p->data.egrade > emax)
			emax = p->data.egrade;
		if(p->data.cgrade < cmin)
			cmin = p->data.cgrade;
		if(p->data.mgrade < mmin)
			mmin = p->data.mgrade;
		if(p->data.egrade < emin)
			emin = p->data.egrade;

		if(p->data.cgrade >= 90 && p->data.cgrade <= 100)
			c[0][0]++;
		if(p->data.cgrade >= 80 && p->data.cgrade < 90)
			c[0][1]++;
		if(p->data.cgrade >= 70 && p->data.cgrade < 80)
			c[0][2]++;
		if(p->data.cgrade >= 60 && p->data.cgrade < 70)
			c[0][3]++;
		if(p->data.cgrade < 60)
			c[0][4]++;

		if(p->data.mgrade >= 90 && p->data.mgrade <= 100)
			c[1][0]++;
		if(p->data.mgrade >= 80 && p->data.mgrade < 90)
			c[1][1]++;
		if(p->data.mgrade >= 70 && p->data.mgrade < 80)
			c[1][2]++;
		if(p->data.mgrade >= 60 && p->data.mgrade < 70)
			c[1][3]++;
		if(p->data.mgrade < 60)
			c[1][4]++;

		if(p->data.egrade >= 90 && p->data.egrade <= 100)
			c[2][0]++;
		if(p->data.egrade >= 80 && p->data.egrade < 90)
			c[2][1]++;
		if(p->data.egrade >= 70 && p->data.egrade < 80)
			c[2][2]++;
		if(p->data.egrade >= 60 && p->data.egrade < 70)
			c[2][3]++;
		if(p->data.egrade < 60)
			c[2][4]++;

		p = p->next;
	}
	while(1)
	{
		printf("1.统计各科成绩的最高分和最低分\n");
		printf("2.统计各分数段的人数\n");
		printf("0.退出统计\n");
		printf("请输入您的选择:");
		scanf("%d", &n);
		if(n == 1)
		{
			printf("|-------|------------|------------|\n");
			printf("|科目    | 最高分     | 最低分     |\n");
			printf("|--------|-----------|------------|\n");
			printf("c语言   %d		%d		\n", cmax, cmin);
			printf("数学    %d      %d      \n", mmax, mmin);
			printf("英语    %d       %d     \n", emax, emin);
		}
		else if(n == 2)
		{
			printf("|------|--------|---------|--------|--------|---------|\n");
			printf("|科目  | 90-100 | 80-90   |  70-80 |  60-70 | 60以下   |\n");
			printf("|------|--------|---------|--------|--------|---------|\n");
			printf("c语言   %d		 %d		   %d		%d		 %d\n",c[0][0], c[0][1], c[0][2], c[0][3], c[0][4]);
			printf("数学    %d       %d        %d       %d       %d\n",c[1][0], c[1][1], c[1][2], c[1][3], c[1][4]);
			printf("英语    %d		 %d		   %d       %d       %d\n",c[2][0], c[2][1], c[2][2], c[2][3], c[2][4]);
		}
		else if(n == 0)
		{
			break;
		}
		else
		{
			printf("输入错误!\n");
		}
	}
	return;
}

void sort(Link l)
{
	Node *p;
	if(!l->next)
	{
		printf("\n======>提示:没有资料可以排序!\n");
		return;
	}
	p = l->next;
}

int main()
{
	Link l;
	FILE *fp;
	int sel;
	char ch;
	int count = 0;
	Node *p, *r;
	printf("\t\t\t\t学生成绩管理系统\n\t\t\t-----------------------\n");
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	
	fp = fopen("C:\\student", "ab+");
	if(fp == NULL)
	{
		printf("\n======>提示:文件不能打开!\n");
		exit(0);
	}
	printf("\n=====>提示:文件已经打开,正在导入记录.......\n");

	while(!feof(fp))
	{
		p = (Node*)malloc(sizeof(Node));
		if(fread(p,sizeof(Node), 1, fp) == 1)
		{
			p->next = NULL;
			r->next = p;
			r = p;
			count++;
		}
	}
	fclose(fp);
	printf("\n=======>提示:记录导入完毕,共导入%d条记录.\n", count);
	menu();
	while(1)
	{
		printf("请你选择操作:");
		scanf("%d", &sel);

		if(sel == 0)
		{
			if(shoudsave == 1)
			{
				getchar();
				printf("\n======>提示:资料已经改动,是否将改动保存到文件中(y/n)?\n");
				scanf("%c", &ch);
				if(ch == 'y' || ch == 'Y')
					Save(l);
			}
			printf("\n======>提示:你已经退出系统,再见!\n");
			break;
		}
		switch(sel)
		{
		case 1:
			Add(l);
			break;
		case 2:
			Del(l);
			break;
		case 3:
			Qur(l);
			break;
		case 4:
			Modify(l);
			break;
		case 5:
			Disp(l);
			break;
		case 6:
			stastic(l);
			break;
		case 7:
			sort(l);
			break;
		case 8:
			Save(l);
			break;
		case 9:
			printf("\t\t\t===============帮助信息================\n");
			menu();
			break;
		default:
			Wrong();
			getchar();
			break;
		}
	}

	while(l)
	{
		p = l;
		l = l->next;
		free(p);
	}
	getchar();
	return 0;
}