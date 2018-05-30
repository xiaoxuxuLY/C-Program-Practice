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
	printf("*****欢迎来到【通讯录】******");
	printf("\n\n");
	printf("  选择1: 导入信息\n");
	printf("  选择2: 新建信息\n");
	printf("  选择3: 查询信息\n");
	printf("  选择4: 修改信息\n");
	printf("  选择5: 删除个人\n");
	printf("  选择6: 删除所有\n");
	printf("  选择7: 输出信息\n");
	printf("  选择0: 退出系统\n\n");
	printf("***************************\n");

	printf("【请选择数字0-7,其他键暂时不起作用】\n");
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
		printf("对不起!您的输入有误!请重新输入: ");
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
		printf("\n\t\t*通讯录文件不存在!  *");
		if((fp = fopen("per.bin", "wb")) == NULL)
		{
			printf("\n*      建立失败!           *");
			printf("\n*							 *");
			printf("\n*							 *");
			printf("\n****************************");
			exit(0);
		}
		else
		{
			printf("\n\t\t*    通讯录文件已建立!     *");
			printf("\n\t\t*							*");
			printf("\n\t\t*							*");
			printf("\n\t\t***************************");
			printf("\n\t\t   按任意键进入主菜单       ");
			printf("\n\t\t   请输入您的数字选择		 ");
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
		printf("\n\t\t*   文件导入成功!				*");
		printf("\n\t\t*								*");
		printf("\n\t\t*								*");
		printf("\n\t\t*******************************");
		printf("\n\t\t 按1显示所有信息, 按2回主菜单!   ");
		printf("\t\t  请输入您的数字选择:				  ");
		scanf("%d", &j);
		if(j == 1)
			showall();
	}
	else
	{
		printf("\n\t\t********************************");
		printf("\n\t\t*								 *");
		printf("\n\t\t*                              *");
		printf("\n\t\t*   文件导入成功!				 *");
		printf("\n\t\t*  通讯录文件中无任何记录!       *");
		printf("\n\t\t*                              *");
		printf("\n\t\t*                              *");
		printf("\n\t\t********************************");
		printf("\n\t\t 请按任意数字键返回主菜单         ");
		scanf("%d", &i);
		return;
	}
}

void newrecord()
{
	char s[81];
	int a;
loop: printf("\n\n\n\n\t\t 请输入您要添加的联系人的信息:  \n");
	printf("\n 请输入姓名:\n");
name: scanf("%s", &per[num].name);
	if(strlen(per[num].name) > 15)
	{
		printf("对不起!您的输入有误! 请重新输入");
		goto name;
	}
	if((fp = fopen("c:\\string.txt", "a")) == NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	fprintf(fp, " 姓名\t\t 电话\t\t\t QQ\n");
	fprintf(fp, "%-15s", per[num].name);
	fclose(fp);
	printf("\n 请输入手机号码: \n");
celephone: scanf("%s", &per[num].celephone);
	if(strlen(per[num].celephone) != 11)
	{
		printf("对不起!您的输入有误! 请重新输入\n");
		goto celephone;
	}
	if((fp = fopen("c:\\string.ext", "a")) == NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	fprintf(fp, "%-24s", per[num].celephone);
	fclose(fp);
	printf("\n输入QQ号码:");
QQ: scanf("%s", &per[num].QQ);
	if(strlen(per[num].QQ) != 10)
	{
		printf("对不起！您的输入有误! 请重新输入");
		goto QQ;
	}
	if((fp = fopen("c:\\string.txt", "a")) == NULL)
	{
		printf("无法打开文件\n");
		exit(1);
	}
	fprintf(fp, "%-20s\n", per[num].QQ);
	fclose(fp);
	num++;
	printf("\n 是否继续添加?\n");
	printf("\n 请按1 和 2(1代表继续; 2代表不继续)\n");
	printf("请输入您的选择 ");
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
	printf("\n\t\t      欢迎使用查询菜单");
	printf("\n\t\t	  1-按姓名查询      ");
	printf("\n\t\t    2-按手机号码查询  ");
	printf("\n\t\t    3-按QQ查询        ");
	printf("\n\t\t    其他键-返回主菜单  ");
	printf("\n\t\t");
	printf("请输入您的选择 ");
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
	printf("\n				按姓名查找				");
	printf("\n请输入姓名:");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			findmark++;
			printf("\n\t\t			以下是您查找的联系人的信息		");
			printf("\n\t\t__________________________________________");
			printf("\n\t\t名字:   %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s", per[i].QQ);
			printf("\n\t\t__________________________________________");
			if((i + 1) < num)
			{
				printf("\n 是否继续查找相同名字的联系人的信息?(1代表继续;2代表不继续)");
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
				printf("\n 请按任意数字键返回主菜单");
				scanf("%d", &j);
				return;
			}
		}
	}
	if(mark != 0)
	{
		printf("\n对不起!没有相同名字的该联系人的信息!!");
		printf("\n对任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
	else if(findmark == 0)
	{
		printf("\n 对不起!没有该联系人的信息!");
		printf("\n 请按任意数字键返回主菜单");
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
	printf("\n			按手机号码查找			\n");
	printf("\n请输入手机号:\n");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			printf("\n以下是您查找的联系人的信息");
			printf("\n______________________________");
			printf("\n名字： %s", per[i].name);
			printf("\n手机号码: %s", per[i].celephone);
			printf("\nQQ号码: %s", per[i].QQ);
			printf("\n______________________________");
			printf("\n请按任意数字键返回主菜单");
			mark++;
			scanf("%d", &j);
			return;
		}
	}
	if(mark == 0)
	{
		printf("\n对不起!没有该联系人的信息!");
		printf("\n请按任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
}

void searchbyqq()
{
	int mark = 0;
	int i, j;
	char QQ[20];
	printf("\n\t\t 按QQ号码查找			\n");
	printf("\n请输入QQ号码:");
	scanf("%s", QQ);
	for(i = 0; i < num; i++)
	{
		if(!strcmp(per[i].QQ, QQ))
		{
			printf("\n\t\t		以下是您查找的联系人的信息	");
			printf("\n\t\t__________________________________");
			printf("\n\t\t名字: %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s",per[i].QQ);
			printf("\n\t\t__________________________________");
			printf("\n\t\t请按任意数字键返回主菜单");
			mark++;
			scanf("%d", &j);
			return;
		}
	}
	if(mark == 0)
	{
		printf("\n\t\t 对不起!没有该联系人的信息!");
		printf("\n\t\t 请按任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
}

void xiugaimenu()
{
	int i, j;
	if(num == 0)
	{
		printf("\n\t\t 对不起!文件中无任何记录!");
		printf("\n\t\t 请按任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
	else
	{
		printf("\n\t\t 1-按姓名修改 2-按手机号码修改\n");
		printf("		请输入您的数字选择:	");
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
			printf("对不起!您的输入有误!请重新输入: ");
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
	printf("\n\t\t 请输入要修改联系人的姓名: ");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			printf("\n\t\t 以下是您要修改的联系人的记录: ");
			findmark++;
			printf("\n\t\t_____________________________");
			printf("\n\t\t名字: %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s", per[i].QQ);
			printf("\n\t\t_____________________________");
			printf("\n\t\t 是否修改？(1代表修改; 2代表不修改)");
			printf("	请输入您的数字选择 :");
			scanf("%d", &j);
			if(j == 1)
			{
				xiugaixiangmu(i);
				xiugaimark++;
				printf("\n\t\t 修改成功");
				if((i + 1) < num)
				{
					printf("\n\t\t 是否继续修改相同姓名的联系人的信息?(1代表继续 2不代表继续) ");
					printf("		请输入您的数字选择:		");
					scanf("&d", &j);
					if(j == 1)
					{
						a = i;
						findmark++;
						continue;
					}
				}
				printf("\n\t\t是否继续修改?(1代表继续; 2代表不继续)");
				printf("		请输入您的数字选择:        ");
				scanf("%d", &j);
				if(j == 1)
					xiugaibyname();
				return;
			}
		}
	}
	if((xiugaimark == 0) && (findmark == 0))
	{
		printf("\n\t\t 没有该联系人的记录");
		printf("\n\t\t 是否继续修改?(1代表继续;2代表不继续)");
		printf("		请输入您的数字选择:   ");
		scanf("%d", &j);
		if(j == 1)
			xiugaibyname();
		return;
	}
	else if (findmark != 0)
	{
		printf("\n\t\t 没有重名信息");
		printf("\n\t\t 是否继续修改?(1代表继续;2代表不继续)");
		printf("		请输入您的数字选择:    ");
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
	printf("\n\t\t 请输入要修改联系人的手机号码: ");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			printf("\n\t\t 以下是您要修改的联系人的记录: ");
			findmark++;
			printf("\n\t\t______________________________");
			printf("\n\t\t名字: %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s", per[i].QQ);
			printf("\n\t\t______________________________");
			printf("\n\t\t是否修改?(1代表修改; 2代表不修改) ");
			printf("	请输入您的数字选择:		");
			scanf("%d", &j);
			if(j == 1)
			{
				xiugaixiangmu(i);
				printf("\n\t\t修改成功");
				printf("\n\t\t是否继续修改?(1代表继续; 2 代表不继续)");
				printf("			请输入您的数字选择:		");
				scanf("%d", &j);
				printf("		请输入您的数字选择:   ");
				if(j == 1)
					xiugaixiangmu(i);
				break;
			}
		}
	}
	if(findmark == 0)
	{
		printf("\n\t\t对不起!没有该联系人的记录!");
		printf("\n\t\t是否继续修改?(1代表继续;2代表不继续)");
		printf("		请输入您的数字选择:     ");
		scanf("%d", &j);
		if(j == 1)
			xiugaibycelephone();
		return;
	}
}

void xiugaixiangmu(int a)
{
	int i;
	printf("\n\t\t		请输入您要修改的项目			");
	printf("\n\t\t\n");
	printf("\n\t\t1-手机号码\n");
	printf("\n\t\t2-姓名\n");
	printf("\n\t\t4-QQ号码\n");
	printf("\n\t\t8-回主菜单\n");
	printf("\n\t\t\n");
	printf("			请输入您的数字选择:			 ");
	scanf("%d", &i);
loop9:switch(i)
	  {
case 1:
	printf("请输入手机号码:");
	scanf("%s", &per[a].celephone);
	break;
case 2:
	printf("请输入姓名:");
	scanf("%s", &per[a].name);
	break;
case 4:
	printf("请输入QQ号码: ");
	scanf("%s", &per[a].QQ);
	break;
case 8:
	mainmenu();
	break;
default:
	printf("对不起!您输入有误!请重新输入:   ");
	goto loop9;
	  }
}

void deletemenu()
{
	int i,j;
	if(num == 0)
	{
		printf("\n\t\t对不起!文件中无任何记录!");
		printf("\n\t\t请先添加个人信息!");
		printf("\n\t\t请按任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
	else
	{
		printf("\n\t\t			删除菜单				");
		printf("\n\t\t			1-删除单个			");
		printf("\n\t\t			2-返回主菜单			");
		printf("\n\t\t								");
		printf("\n\t\t请输入您的数字选择:				");
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
			printf("对不起!您的输入有误!请重新输入:	");
			goto loop4;
		}
	}
}

void deleteall()
{
	int i,j;
	printf("\n\t\t确认删除?\n");
	printf("请按1和2(1代表确认;2代表不删除) \n");
	scanf("%d", &i);
	if(i == 1)
	{
		fclose(fp);
		if((fp = fopen("per.bin", "wb")) == NULL)
		{
			printf("\n\t\t不能打开文件,删除失败");
			readfromfile();
		}
		num = 0;
		printf("\n\t\t记录也删除!");
		printf("\n\t\t请按任意数字键返回主菜单");
		scanf("%d", &j);
		return;
	}
}

void deleteone()
{
	int i;
	printf("\n\t\t1-按手机号码删除 2-按姓名删除");
	printf("\n\t\t 请输入您的选择: ");
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
		printf("对不起!您的输入有误! 请重新输入: ");
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
	printf("\n\t\t请输入您要删除的联系人的姓名: ");
	scanf("%s", name);
	for(i = a; i < num; i++)
	{
		if(strcmp(per[i].name, name) == 0)
		{
			printf("\n\t\t以下是您要删除的联系人的记录: ");
			findmark++;
			printf("\n\t\t____________________________");
			printf("\n\t\t名字: %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s", per[i].QQ);
			printf("\n\t\t____________________________");
			printf("\n\t\t是否删除?(1代表删除; 2代表不删除)\n");
			printf("\n\t\t请输入您的数字选择:  ");
			scanf("%d", &k);
			if(k == 1)
			{
				for(j = i; j < num - 1; j++)
					per[j] = per[j+1];
				num--;
				deletemark++;
				printf("\n\t\t删除成功");
				if((i + i) < num)
				{
					printf("\n\t\t是否继续删除相同姓名的联系人的信息?(1代表删除;2代表不删除)");
					printf("\n\t\t请输入您的数字选择: ");
					scanf("%d", &k);
					if(k = 1)
					{
						a = i;
						findmark++;
						continue;
					}
				}
				printf("\n\t\t是否继续删除?(1 代表继续; 2代表不继续)");
				printf("\n\t\t请输入您的数字选择:  ");
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
		printf("\n\t\t 对不起!没有该联系人的记录!");
		printf("\n\t\t 是否继续删除?(1代表继续;2代表不继续)");
		printf("		请输入您的数字选择:   ");
		scanf("%d", &k);
		if(k == 1)
			deleteone();
	}
	else if(findmark != 0)
	{
		printf("\n\t\t 对不起!没有重名信息!");
		printf("\n\t\t 是否继续删除?(1代表继续; 2代表不继续)");
		printf("\n\t\t 请输入您的数字选择:   ");
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
	printf("\n\t\t请输入要删除的联系人的手机号码: ");
	scanf("%s", celephone);
	for(i = 0; i < num; i++)
	{
		if(strcmp(per[i].celephone, celephone) == 0)
		{
			deletemark++;
			printf("\n\t\t 以下是您要删除的联系人的记录: ");
			printf("\n\t\t_____________________________");
			printf("\n\t\t名字: %s", per[i].name);
			printf("\n\t\t手机号码: %s", per[i].celephone);
			printf("\n\t\tQQ号码: %s", per[i].QQ);
			printf("\n\t\t_____________________________");
			printf("\n\t\t是否删除?(1代表删除; 2代表不删除)\n");
			printf("		请输入您的数字选择:			");
			scanf("%d", &h);
			if(h == 1)
			{
				for(j = i; j < num -1; j++)
					per[j] =per[j + 1];
				num--;
				printf("\n\t\t删除成功");
				printf("\n是否继续删除?(1代表继续; 2代表不继续)\n");
				printf("			请输入您的数字选择:	");
				scanf("%d", &h);
				if(h == 1)
					deletebycelephone();
			}
		}
	}
	if(deletemark == 0)
	{
		printf("\n\t\t 对不起! 没有该联系人的记录!");
		printf("\n\t\t 是否继续删除?(1代表继续; 2代表不继续) \n");
		printf("		请输入您的数字选择:   ");
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
		printf("\n\t\t******************以下为通讯录所有信息**************");
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
		printf("\n\t\t对不起!通讯录中无任何记录!");
	printf("\n\t\t请按任意数字键返回主菜单");
	scanf("%d", &j);
	return;
}

