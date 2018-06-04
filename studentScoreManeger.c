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
	printf("\t1����ѧ������\t\t\t\t\t2ɾ��ѧ������\n");
	printf("\t3��ѯѧ������\t\t\t\t\t4�޸�ѧ������\n");
	printf("\t5��ʾѧ������\t\t\t\t\t6ͳ��ѧ���ɼ�\n");
	printf("\t7����ѧ���ɼ�\t\t\t\t\t8����ѧ������\n");
	printf("\t9��ȡ������Ϣ\t\t\t\t\t0�˳�ϵͳ\n");
	printf("**********************************************\n");
}

void printstart()
{
	printf("----------------------------------------------\n");
}

void Wrong()
{
	printf("\n=====>��ʾ:�������!\n");
}

void Nofind()
{
	printf("\n=====>��ʾ:û���ҵ���ѧ��!\n");
}

void printc()
{
	printf("	ѧ��\t	����		Ӣ��ɼ�		��ѧ�ɼ�		C���Գɼ�	�ܷ�		ƽ����\n");
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
		printf("��������ѧ��(��'0'������һ���˵�:)");
		scanf("%s", num);
		getchar();
		if(strcmp(num, "0") == 0)
			break;
		while(s)
		{
			if(strcmp(s->data.num, num) == 0)
			{
				printf("========>��ʾ:ѧ��Ϊ'%s'��ѧ���Ѿ�����,��Ҫ�޸�����ѡ��'4�޸�'!\n", num);
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
		printf("������������:");
		scanf("%s", p->data.name);
		getchar();
		printf("��������c���Գɼ�:");
		scanf("%d", &p->data.cgrade);
		getchar();
		printf("����������ѧ�ɼ�:");
		scanf("%d", &p->data.mgrade);
		getchar();
		printf("��������Ӣ��ɼ�:");
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
		printf("\n====>��ʾ:û�����Ͽ��Բ�ѯ!\n");
		return;
	}
	printf("\n====>1��ѧ�Ų���\n====>2����������\n");
	scanf("%d", &sel);
	if(sel == 1)
	{
		printf("��������Ҫ���ҵ�ѧ��:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if(p)
		{
			printf("\t\t\t\t���ҽ��\n");
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
		printf("��������Ҫ���ҵ�����:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if(p)
		{
			printf("\t\t\t\t���ҽ��\n");
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
		printf("\n=====>��ʾ:û�����Ͽ���ɾ��!\n");
		return;
	}
	printf("\n=====>1��ѧ��ɾ��\n=====>2������ɾ��\n");
	scanf("%d", &sel);
	if(sel == 1)
	{
		printf("��������Ҫɾ����ѧ��:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "num");
		if(p)
		{
			r = l;
			while(r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n=====>��ʾ:��ѧ���Ѿ��ɹ�ɾ��!\n");
			shoudsave = 1;
		}
		else
			Nofind();
	}
	else if(sel == 2)
	{
		printf("��������Ҫɾ��������:");
		scanf("%s", findmess);
		p = Locate(l, findmess, "name");
		if(p)
		{
			r = l;
			while(r->next != p)
				r = r->next;
			r->next = p->next;
			free(p);
			printf("\n======>��ʾ:��ѧ���Ѿ��ɹ�ɾ��!\n");
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
		printf("\n=======>��ʾ:û�����Ͽ����޸�!\n");
		return;
	}
	printf("��������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s", findmess);
	p = Locate(l, findmess, "num");
	if(p)
	{
		printf("���������µ�c���Գɼ�(ԭ����%d��):", p->data.cgrade);
		scanf("%d", &p->data.cgrade);
		printf("\n======>��ʾ:�����޸ĳɹ�!\n");
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
		printf("\n=====>��ʾ:û�����Ͽ�����ʾ!\n");
		return;
	}
	printf("\t\t\t\t��ʾ���\n");
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
		printf("\n======>��ʾ:���´��ļ�ʱ��������!\n");
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
		printf("\n======>��ʾ:�ļ�����ɹ�.(��%d����¼�Ѿ�����.)\n", count);
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
		printf("\n======>��ʾ:û�����Ͽ���ͳ��!\n");
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
		printf("1.ͳ�Ƹ��Ƴɼ�����߷ֺ���ͷ�\n");
		printf("2.ͳ�Ƹ������ε�����\n");
		printf("0.�˳�ͳ��\n");
		printf("����������ѡ��:");
		scanf("%d", &n);
		if(n == 1)
		{
			printf("|-------|------------|------------|\n");
			printf("|��Ŀ    | ��߷�     | ��ͷ�     |\n");
			printf("|--------|-----------|------------|\n");
			printf("c����   %d		%d		\n", cmax, cmin);
			printf("��ѧ    %d      %d      \n", mmax, mmin);
			printf("Ӣ��    %d       %d     \n", emax, emin);
		}
		else if(n == 2)
		{
			printf("|------|--------|---------|--------|--------|---------|\n");
			printf("|��Ŀ  | 90-100 | 80-90   |  70-80 |  60-70 | 60����   |\n");
			printf("|------|--------|---------|--------|--------|---------|\n");
			printf("c����   %d		 %d		   %d		%d		 %d\n",c[0][0], c[0][1], c[0][2], c[0][3], c[0][4]);
			printf("��ѧ    %d       %d        %d       %d       %d\n",c[1][0], c[1][1], c[1][2], c[1][3], c[1][4]);
			printf("Ӣ��    %d		 %d		   %d       %d       %d\n",c[2][0], c[2][1], c[2][2], c[2][3], c[2][4]);
		}
		else if(n == 0)
		{
			break;
		}
		else
		{
			printf("�������!\n");
		}
	}
	return;
}

void sort(Link l)
{
	Node *p;
	if(!l->next)
	{
		printf("\n======>��ʾ:û�����Ͽ�������!\n");
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
	printf("\t\t\t\tѧ���ɼ�����ϵͳ\n\t\t\t-----------------------\n");
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	
	fp = fopen("C:\\student", "ab+");
	if(fp == NULL)
	{
		printf("\n======>��ʾ:�ļ����ܴ�!\n");
		exit(0);
	}
	printf("\n=====>��ʾ:�ļ��Ѿ���,���ڵ����¼.......\n");

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
	printf("\n=======>��ʾ:��¼�������,������%d����¼.\n", count);
	menu();
	while(1)
	{
		printf("����ѡ�����:");
		scanf("%d", &sel);

		if(sel == 0)
		{
			if(shoudsave == 1)
			{
				getchar();
				printf("\n======>��ʾ:�����Ѿ��Ķ�,�Ƿ񽫸Ķ����浽�ļ���(y/n)?\n");
				scanf("%c", &ch);
				if(ch == 'y' || ch == 'Y')
					Save(l);
			}
			printf("\n======>��ʾ:���Ѿ��˳�ϵͳ,�ټ�!\n");
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
			printf("\t\t\t===============������Ϣ================\n");
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