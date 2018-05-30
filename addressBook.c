#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct person
{
	char name[15];
	char celephone[22];
	char QQ[20];
}per[500];
int num = 0;
FILE *fp;
void mainmenu();

void newrecord();
void readfromfile();

void searchmenu();
void searchbyname();
void searchbycelephone();
void searchbyqq();

void xiugaimenu();
void xiugaibyname();
void xiugaibycelephone();
void xiugaixiangmu(int a);

void deletemenu();
void deleteall();
void deleteone();
void deletebycelephone();
void deletebyname();
void showall();

void main()
{
	while(1)
	{
		mainmenu();
	}
}

void mainmenu()
{
	int a;
	printf("*****��ӭ������ͨѶ¼��******");
	printf("\n\n");
	printf("  ѡ��1: ������Ϣ\n");
	printf("  ѡ��2: �½���Ϣ\n");
	printf("  ѡ��3: ��ѯ��Ϣ\n");
	printf("  ѡ��4: �޸���Ϣ\n");
	printf("  ѡ��5: ɾ������\n");
	printf("  ѡ��6: ɾ������\n");
	printf("  ѡ��7: �����Ϣ\n");
	printf("  ѡ��0: �˳�ϵͳ\n\n");
	printf("***************************\n");

	printf("����ѡ������0-7,��������ʱ�������á�\n");
loop1:scanf("%d", &a);
	switch(a)
	{
	case 1:
		readfromfile();
		break;
	case 2:
		newrecord();
		break;
	case 3:
		searchmenu();
		break;
	case 4:
		xiugaimenu();
		break;
	case 5:
		deletemenu();
		break;
	case 6:
		deleteall();
		break;
	case 7:
		showall();
		break;
	case 0:
		exit(0);
	default:
		printf("�Բ���!������������!����������: ");
		getchar();
		goto loop1;
	}
}

void readfromfile()
{
	int i, j, k;
	if((fp = fopen("c:\\string.txt", "rb")) == NULL)
	{
		printf("\n\t\t***************************");
		printf("\n\t\t*				     *");
		printf("\n\t\t*				     *");
		printf("\n\t\t*ͨѶ¼�ļ�������!  *");
		if((fp = fopen("per.bin", "wb")) == NULL)
		{
			printf("\n*      ����ʧ��!           *");
			printf("\n*							 *");
			printf("\n*							 *");
			printf("\n****************************");
			exit(0);
		}
		else
		{
			printf("\n\t\t*    ͨѶ¼�ļ��ѽ���!     *");
			printf("\n\t\t*							*");
			printf("\n\t\t*							*");
			printf("\n\t\t***************************");
			printf("\n\t\t   ��������������˵�       ");
			printf("\n\t\t   ��������������ѡ��		 ");
			scanf("%d", &k);
			return;
		}
		exit(0);
	}
	fseek(fp, 0, 2);
	if(ftell(fp) > 0)
	{
		rewind(fp);
		for(num = 0; !feof(fp) && fread(&per[num], sizeof(struct person), 1, fp); num++);
		printf("\n\t\t*******************************");
		printf("\n\t\t*								*");
		printf("\n\t\t*								*");
		printf("\n\t\t*   �ļ�����ɹ�!				*");
		printf("\n\t\t*								*");
		printf("\n\t\t*								*");
		printf("\n\t\t*******************************");
		printf("\n\t\t ��1��ʾ������Ϣ, ��2�����˵�!   ");
		printf("\t\t  ��������������ѡ��:				  ");
		scanf("%d", &j);
		if(j == 1)
			showall();
	}
	else
	{
		printf("\n\t\t********************************");
		printf("\n\t\t*								 *");
		printf("\n\t\t*                              *");
		printf("\n\t\t*   �ļ�����ɹ�!				 *");
		printf("\n\t\t*  ͨѶ¼�ļ������κμ�¼!       *");
		printf("\n\t\t*                              *");
		printf("\n\t\t*                              *");
		printf("\n\t\t********************************");
		printf("\n\t\t �밴�������ּ��������˵�         ");
		scanf("%d", &i);
		return;
	}
}

void newrecord()
{
	char s[81];
	int a;
loop: printf("\n\n\n\n\t\t ��������Ҫ��ӵ���ϵ�˵���Ϣ:  \n");
	printf("\n ����������:\n");
name: scanf("%s", &per[num].name);
	if(strlen(per[num].name) > 15)
	{
		printf("�Բ���!������������! ����������");
		goto name;
	}
	if((fp = fopen("c:\\string.txt", "a")) == NULL)
	{
		printf("�޷����ļ�\n");
		exit(1);
	}
	fprintf(fp, " ����\t\t �绰\t\t\t QQ\n");
	fprintf(fp, "%-15s", per[num].name);
	fclose(fp);
	printf("\n �������ֻ�����: \n");
celephone: scanf("%s", &per[num].celephone);
	if(strlen(per[num].celephone) != 11)
	{
		printf("�Բ���!������������! ����������\n");
		goto celephone;
	}
	if((fp = fopen("c:\\string.ext", "a")) == NULL)
	{
		printf("�޷����ļ�\n");
		exit(1);
	}
	fprintf(fp, "%-24s", per[num].celephone);
	fclose(fp);
	printf("\n����QQ����:");
QQ: scanf("%s", &per[num].QQ);
	if(strlen(per[num].QQ) != 10)
	{
		printf("�Բ���������������! ����������");
		goto QQ;
	}
	if((fp = fopen("c:\\string.txt", "a")) == NULL)
	{
		printf("�޷����ļ�\n");
		exit(1);
	}
	fprintf(fp, "%-20s\n", per[num].QQ);
	fclose(fp);
	num++;
	printf("\n �Ƿ�������?\n");
	printf("\n �밴1 �� 2(1�������; 2��������)\n");
	printf("����������ѡ�� ");
	scanf("%d", &a);
	if(a == 1)
	{
		goto loop;
	}
	else
	{
		return;
	}
}

void searchmenu()
{
	int a;
	printf("\n\t\t      ��ӭʹ�ò�ѯ�˵�");
	printf("\n\t\t	  1-��������ѯ      ");
	printf("\n\t\t    2-���ֻ������ѯ  ");
	printf("\n\t\t    3-��QQ��ѯ        ");
	printf("\n\t\t    ������-�������˵�  ");
	printf("\n\t\t");
	printf("����������ѡ�� ");
	scanf("%d", &a);
	switch(a)
	{
	case 1:
		searchbyname();
		break;
	case 2:
		searchbycelephone();
		break;
	case 3:
		searchbyqq();
		break;
	default:
		mainmenu();
		break;
	}
}

void searchbyname()
{
	int mark = 0;
	int i, j, findmark = 0;
	int a = 0;
	char name[15];
	printf("\n				����������				");
	printf("\n����������:");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			findmark++;
			printf("\n\t\t			�����������ҵ���ϵ�˵���Ϣ		");
			printf("\n\t\t__________________________________________");
			printf("\n\t\t����:   %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s", per[i].QQ);
			printf("\n\t\t__________________________________________");
			if((i + 1) < num)
			{
				printf("\n �Ƿ����������ͬ���ֵ���ϵ�˵���Ϣ?(1�������;2��������)");
				scanf("%d", &j);
				if(j == 1)
				{
					a = i;
					mark++;
					continue;
				}
				else
					break;
			}
			else
			{
				printf("\n �밴�������ּ��������˵�");
				scanf("%d", &j);
				return;
			}
		}
	}
	if(mark != 0)
	{
		printf("\n�Բ���!û����ͬ���ֵĸ���ϵ�˵���Ϣ!!");
		printf("\n���������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
	else if(findmark == 0)
	{
		printf("\n �Բ���!û�и���ϵ�˵���Ϣ!");
		printf("\n �밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
}

void searchbycelephone()
{
	int mark = 0;
	int i,j;
	int a = 0;
	char celephone[11];
	printf("\n			���ֻ��������			\n");
	printf("\n�������ֻ���:\n");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			printf("\n�����������ҵ���ϵ�˵���Ϣ");
			printf("\n______________________________");
			printf("\n���֣� %s", per[i].name);
			printf("\n�ֻ�����: %s", per[i].celephone);
			printf("\nQQ����: %s", per[i].QQ);
			printf("\n______________________________");
			printf("\n�밴�������ּ��������˵�");
			mark++;
			scanf("%d", &j);
			return;
		}
	}
	if(mark == 0)
	{
		printf("\n�Բ���!û�и���ϵ�˵���Ϣ!");
		printf("\n�밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
}

void searchbyqq()
{
	int mark = 0;
	int i, j;
	char QQ[20];
	printf("\n\t\t ��QQ�������			\n");
	printf("\n������QQ����:");
	scanf("%s", QQ);
	for(i = 0; i < num; i++)
	{
		if(!strcmp(per[i].QQ, QQ))
		{
			printf("\n\t\t		�����������ҵ���ϵ�˵���Ϣ	");
			printf("\n\t\t__________________________________");
			printf("\n\t\t����: %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s",per[i].QQ);
			printf("\n\t\t__________________________________");
			printf("\n\t\t�밴�������ּ��������˵�");
			mark++;
			scanf("%d", &j);
			return;
		}
	}
	if(mark == 0)
	{
		printf("\n\t\t �Բ���!û�и���ϵ�˵���Ϣ!");
		printf("\n\t\t �밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
}

void xiugaimenu()
{
	int i, j;
	if(num == 0)
	{
		printf("\n\t\t �Բ���!�ļ������κμ�¼!");
		printf("\n\t\t �밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
	else
	{
		printf("\n\t\t 1-�������޸� 2-���ֻ������޸�\n");
		printf("		��������������ѡ��:	");
loop6: scanf("%d", &i);
		switch(i)
		{
		case 1:
			xiugaibyname();
			break;
		case 2:
			xiugaibycelephone();
			break;
		default:
			printf("�Բ���!������������!����������: ");
			goto loop6;
		}
	}
}

void xiugaibyname()
{
	int a = 0;
	int findmark = 0;
	int xiugaimark = 0;
	int i, j;
	char name[15];
	printf("\n\t\t ������Ҫ�޸���ϵ�˵�����: ");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			printf("\n\t\t ��������Ҫ�޸ĵ���ϵ�˵ļ�¼: ");
			findmark++;
			printf("\n\t\t_____________________________");
			printf("\n\t\t����: %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s", per[i].QQ);
			printf("\n\t\t_____________________________");
			printf("\n\t\t �Ƿ��޸ģ�(1�����޸�; 2�����޸�)");
			printf("	��������������ѡ�� :");
			scanf("%d", &j);
			if(j == 1)
			{
				xiugaixiangmu(i);
				xiugaimark++;
				printf("\n\t\t �޸ĳɹ�");
				if((i + 1) < num)
				{
					printf("\n\t\t �Ƿ�����޸���ͬ��������ϵ�˵���Ϣ?(1������� 2���������) ");
					printf("		��������������ѡ��:		");
					scanf("&d", &j);
					if(j == 1)
					{
						a = i;
						findmark++;
						continue;
					}
				}
				printf("\n\t\t�Ƿ�����޸�?(1�������; 2��������)");
				printf("		��������������ѡ��:        ");
				scanf("%d", &j);
				if(j == 1)
					xiugaibyname();
				return;
			}
		}
	}
	if((xiugaimark == 0) && (findmark == 0))
	{
		printf("\n\t\t û�и���ϵ�˵ļ�¼");
		printf("\n\t\t �Ƿ�����޸�?(1�������;2��������)");
		printf("		��������������ѡ��:   ");
		scanf("%d", &j);
		if(j == 1)
			xiugaibyname();
		return;
	}
	else if (findmark != 0)
	{
		printf("\n\t\t û��������Ϣ");
		printf("\n\t\t �Ƿ�����޸�?(1�������;2��������)");
		printf("		��������������ѡ��:    ");
		scanf("%d", &j);
		if(j == 1)
			xiugaibyname();
		return;
	}
}

void xiugaibycelephone()
{
	int findmark = 0;
	int i, j;
	char celephone[11];
	printf("\n\t\t ������Ҫ�޸���ϵ�˵��ֻ�����: ");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			printf("\n\t\t ��������Ҫ�޸ĵ���ϵ�˵ļ�¼: ");
			findmark++;
			printf("\n\t\t______________________________");
			printf("\n\t\t����: %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s", per[i].QQ);
			printf("\n\t\t______________________________");
			printf("\n\t\t�Ƿ��޸�?(1�����޸�; 2�����޸�) ");
			printf("	��������������ѡ��:		");
			scanf("%d", &j);
			if(j == 1)
			{
				xiugaixiangmu(i);
				printf("\n\t\t�޸ĳɹ�");
				printf("\n\t\t�Ƿ�����޸�?(1�������; 2 ��������)");
				printf("			��������������ѡ��:		");
				scanf("%d", &j);
				printf("		��������������ѡ��:   ");
				if(j == 1)
					xiugaixiangmu(i);
				break;
			}
		}
	}
	if(findmark == 0)
	{
		printf("\n\t\t�Բ���!û�и���ϵ�˵ļ�¼!");
		printf("\n\t\t�Ƿ�����޸�?(1�������;2��������)");
		printf("		��������������ѡ��:     ");
		scanf("%d", &j);
		if(j == 1)
			xiugaibycelephone();
		return;
	}
}

void xiugaixiangmu(int a)
{
	int i;
	printf("\n\t\t		��������Ҫ�޸ĵ���Ŀ			");
	printf("\n\t\t\n");
	printf("\n\t\t1-�ֻ�����\n");
	printf("\n\t\t2-����\n");
	printf("\n\t\t4-QQ����\n");
	printf("\n\t\t8-�����˵�\n");
	printf("\n\t\t\n");
	printf("			��������������ѡ��:			 ");
	scanf("%d", &i);
loop9:switch(i)
	  {
case 1:
	printf("�������ֻ�����:");
	scanf("%s", &per[a].celephone);
	break;
case 2:
	printf("����������:");
	scanf("%s", &per[a].name);
	break;
case 4:
	printf("������QQ����: ");
	scanf("%s", &per[a].QQ);
	break;
case 8:
	mainmenu();
	break;
default:
	printf("�Բ���!����������!����������:   ");
	goto loop9;
	  }
}

void deletemenu()
{
	int i,j;
	if(num == 0)
	{
		printf("\n\t\t�Բ���!�ļ������κμ�¼!");
		printf("\n\t\t������Ӹ�����Ϣ!");
		printf("\n\t\t�밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
	else
	{
		printf("\n\t\t			ɾ���˵�				");
		printf("\n\t\t			1-ɾ������			");
		printf("\n\t\t			2-�������˵�			");
		printf("\n\t\t								");
		printf("\n\t\t��������������ѡ��:				");
loop4:scanf("%d", &i);
		switch(i)
		{
		case 1:
			deleteone();
			break;
		case 2:
			mainmenu();
			break;
		default:
			printf("�Բ���!������������!����������:	");
			goto loop4;
		}
	}
}

void deleteall()
{
	int i,j;
	printf("\n\t\tȷ��ɾ��?\n");
	printf("�밴1��2(1����ȷ��;2����ɾ��) \n");
	scanf("%d", &i);
	if(i == 1)
	{
		fclose(fp);
		if((fp = fopen("per.bin", "wb")) == NULL)
		{
			printf("\n\t\t���ܴ��ļ�,ɾ��ʧ��");
			readfromfile();
		}
		num = 0;
		printf("\n\t\t��¼Ҳɾ��!");
		printf("\n\t\t�밴�������ּ��������˵�");
		scanf("%d", &j);
		return;
	}
}

void deleteone()
{
	int i;
	printf("\n\t\t1-���ֻ�����ɾ�� 2-������ɾ��");
	printf("\n\t\t ����������ѡ��: ");
loop5:scanf("%d", &i);
	switch(i)
	{
	case 1:
		deletebycelephone();
		break;
	case 2:
		deletebyname();
		break;
	default:
		printf("�Բ���!������������! ����������: ");
		goto loop5;
	}
}

void deletebyname()
{
	int a = 0;
	int findmark = 0;
	int i, j, k;
	int deletemark = 0;
	char name[15];
	printf("\n\t\t��������Ҫɾ������ϵ�˵�����: ");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			printf("\n\t\t��������Ҫɾ������ϵ�˵ļ�¼: ");
			findmark++;
			printf("\n\t\t____________________________");
			printf("\n\t\t����: %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s", per[i].QQ);
			printf("\n\t\t____________________________");
			printf("\n\t\t�Ƿ�ɾ��?(1����ɾ��; 2����ɾ��)\n");
			printf("\n\t\t��������������ѡ��:  ");
			scanf("%d", &k);
			if(k == 1)
			{
				for(j = i; j < num - 1; j++)
					per[j] = per[j+1];
				num--;
				deletemark++;
				printf("\n\t\tɾ���ɹ�");
				if((i + i) < num)
				{
					printf("\n\t\t�Ƿ����ɾ����ͬ��������ϵ�˵���Ϣ?(1����ɾ��;2����ɾ��)");
					printf("\n\t\t��������������ѡ��: ");
					scanf("%d", &k);
					if(k = 1)
					{
						a = i;
						findmark++;
						continue;
					}
				}
				printf("\n\t\t�Ƿ����ɾ��?(1 �������; 2��������)");
				printf("\n\t\t��������������ѡ��:  ");
				scanf("%d", &k);
				if(k == 1)
					deleteone();
				else
					break;
			}
		}
		else
			continue;
	}
	if((deletemark == 0) && (findmark == 0))
	{
		printf("\n\t\t �Բ���!û�и���ϵ�˵ļ�¼!");
		printf("\n\t\t �Ƿ����ɾ��?(1�������;2��������)");
		printf("		��������������ѡ��:   ");
		scanf("%d", &k);
		if(k == 1)
			deleteone();
	}
	else if(findmark != 0)
	{
		printf("\n\t\t �Բ���!û��������Ϣ!");
		printf("\n\t\t �Ƿ����ɾ��?(1�������; 2��������)");
		printf("\n\t\t ��������������ѡ��:   ");
		scanf("%d", &k);
		if(k == 1)
			deleteone();
	}
}

void deletebycelephone()
{
	int i, j, h, m;
	int deletemark = 0;
	char celephone[11];
	printf("\n\t\t������Ҫɾ������ϵ�˵��ֻ�����: ");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			deletemark++;
			printf("\n\t\t ��������Ҫɾ������ϵ�˵ļ�¼: ");
			printf("\n\t\t_____________________________");
			printf("\n\t\t����: %s", per[i].name);
			printf("\n\t\t�ֻ�����: %s", per[i].celephone);
			printf("\n\t\tQQ����: %s", per[i].QQ);
			printf("\n\t\t_____________________________");
			printf("\n\t\t�Ƿ�ɾ��?(1����ɾ��; 2����ɾ��)\n");
			printf("		��������������ѡ��:			");
			scanf("%d", &h);
			if(h == 1)
			{
				for(j = i; j < num -1; j++)
					per[j] =per[j + 1];
				num--;
				printf("\n\t\tɾ���ɹ�");
				printf("\n�Ƿ����ɾ��?(1�������; 2��������)\n");
				printf("			��������������ѡ��:	");
				scanf("%d", &h);
				if(h == 1)
					deletebycelephone();
			}
		}
	}
	if(deletemark == 0)
	{
		printf("\n\t\t �Բ���! û�и���ϵ�˵ļ�¼!");
		printf("\n\t\t �Ƿ����ɾ��?(1�������; 2��������) \n");
		printf("		��������������ѡ��:   ");
		scanf("%d", &m);
		if(m == 1)
			deletebycelephone();
	}
}

void showall()
{
	int i,j;
	if (num != 0)
	{
		printf("\n\t\t******************����ΪͨѶ¼������Ϣ**************");
		for(i = 0; i < num; i++)
		{
			printf("\n\t\t______________________________________");
			printf("\n%s", per[i].name);
			printf("\n%s", per[i].celephone);
			printf("\n%s", per[i].QQ);
			printf("\n\t\t______________________________________");
			printf("\t\t");
			if(i + 1 < num)
			{
				printf("\n\t\t__________________________________");
				system("pause");
			}
		}
		printf("\n\t\t***************************************************");
	}
	else
		printf("\n\t\t�Բ���!ͨѶ¼�����κμ�¼!");
	printf("\n\t\t�밴�������ּ��������˵�");
	scanf("%d", &j);
	return;
}

