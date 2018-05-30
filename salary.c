#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct
{
	char num[10];
	char name[20];
	char date[15];
	double pay;
} employee;

typedef struct node
{
	employee p;
	struct node *pre;
	struct node *next;
}node, *linklist;

linklist head, last;

void setData(linklist p)
{
	printf("���: ");
	scanf("%s", &p->p.num);
	printf("����: ");
	scanf("%s", &p->p.name);
	printf("��ְʱ��: ");
	scanf("%s", &p->p.date);
	printf("����: ");
	scanf("%lf", &p->p.pay);
}

void Insert(linklist p)
{
	setData(p);
	p->next = last;
	last->pre->next = p;
	p->pre = last->pre;
	last->pre = p;
}

void Add()
{
	char ch;
	do
	{
		linklist p = (linklist)malloc(sizeof(node));
		system("cls");
		Insert(p);
		printf("�Ƿ����?");
		scanf(" %c", &ch);
	}while(ch == 'y' || ch == 'Y');
}

linklist Qur(int method)
{
	char ch[20];
	linklist p = head->next;
	if(method == 0)
	{
		printf("ѡ���ѯ��ʽ:(1 ������ 2����)");
		scanf("%d", &method);
	}
	if(method == 1)
	{
		printf("��������:");
		scanf("%s", ch);
		while(p != last)
		{
			if(strcmp(ch, p->p.name) == 0)
				break;
			p = p->next;
		}
	}
	else if(method == 2)
	{
		printf("��������:");
		scanf("%s", ch);
		while(p != last)
		{
			if(strcmp(ch, p->p.date) == 0)
				break;
			p = p->next;
		}
	}
	if(p == last)
	{
		printf("δ�ҵ�\n");
		system("pause");
	}
	return p;
}
void Del()
{
	linklist p = Qur(1);
	if(p == last)
		return;
	p->pre->next = p->next;
	p->next->pre = p->pre;
	free(p);
	printf("ɾ���ɹ�\n");
	system("pause");
}

void Modify()
{
	linklist p = Qur(1);
	if(p == last)
		return;
	setData(p);
}

void printTitle()
{
	printf("���\t ����\t ��ְ����\t ����\n");
}

void show(linklist p)
{
	printf("%s\t%s\t%s\t%.2lf\n", p->p.num, p->p.name, p->p.date, p->p.pay);
}

void Sort()
{
	linklist p, q;
	for(p = head->next; p != last; p = p->next)
	{
		for(q = q->next; q != last; q = q->next)
		{
			if(p->p.pay < q->p.pay)
			{
				employee temp = p->p;
				p->p = q->p;
				q->p = temp;
			}
		}
	}
	printf("���.\n");
	system("pause");
}

void Tongji()
{
	linklist p = head->next;
	Sort();
	printTitle();
	while(p != last)
	{
		show(p);
		p = p->next;
	}
	system("pause");
}

void Wrong()
{
	printf("�������!\n");
	system("pause");
}

void menu(void)
{
	system("cls");
	printf("**********���ʹ���ϵͳ**********\n");
	printf("*							  *\n");
	printf("*			1:���			  *\n");
	printf("*			2:ɾ��			  *\n");
	printf("*			3.��ѯ			  *\n");
	printf("*			4.�޸�			  *\n");
	printf("*			5.ͳ��			  *\n");
	printf("*			6.����			  *\n");
	printf("*			0.�˳�			  *\n");
	printf("*******************************\n");
}

int select()
{
	int choose;
	scanf("%d", &choose);
	switch(choose)
	{
	case 1:
		Add();
		break;
	case 2:
		Del();
		break;
	case 3:
		{
			linklist p = Qur(0);
			if(p != last)
			{
				show(p);
				system("pause");
			}
			break;
		}
	case 4:
		Modify();
		break;
	case 5:
		Tongji();
		break;
	case 6:
		Sort();
		break;
	case 0:
		break;
	default:
		Wrong();
		break;
	}
	return choose;
}

void destroy()
{
	linklist p = head->next;
	while(p != last)
	{
		head->next = p->next;
		free(p);
		p = head->next;
	}
	free(head);
	free(last);
}
int main()
{
	head = (linklist)malloc(sizeof(node));
	last = (linklist)malloc(sizeof(node));
	head->next = last;
	last->next = NULL;
	last->pre = head;
	head->pre = NULL;
	do
	{
		menu();
	}while(select() != 0);
	destroy();
	return 0;
}
