#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<string.h>

#define LEN_BOOK sizeof(struct Book)
#define LEN_READER sizeof(struct Reader)
#define BOOK_DATA astBook[i].iNum, astBook[i].acName, astBook[i].acAuthor, astBook[i].acPress, astBook[i].iAmount
#define READER_DATA astReader[i].iNum, astReader[i].acName, astReader[i].acSex, astReader[i].iAmount, astReader[i].iMax, astReader[i].aiBookId
#define BOOK_NUM 200
#define READER_NUM 100

struct Book
{
	int iNum;
	char acName[15];
	char acAuthor[15];
	char acPress[15];
	int iAmount;
};
struct Reader
{
	int iNum;
	char acName[15];
	char acSex[4];
	int iMax;
	int iAmount;
	int BookId[10];
};
struct Book astBook[BOOK_NUM];
struct Reader astReader[READER_NUM];

void ShowMainMenu();


void ManageBook();
void ShowBookMenu();
void ShowBook();
void AddBook();
int SearchBook();
void DeleteBook();
void ModifyBook();
void ShowModifyBookMenu();
int ReadBookFile(char * pcMode);
void SaveBookFile(int iBookId);

void ManageReader();
void ShowReaderMenu();
void ShowReader();
void AddReader();
int SearchReader();
void DeleteReader();
void ModifyReader();
void ShowModifyReaderMenu();
int ReadReaderFile(char * pcMode);
void SaveReaderFile(int ibook);


void BorrowReturnManage();
void ShowBorrowReturnMenu();
void BorrowBook();
void ReturnBook();

int main()
{
	int iItem;
	ShowMainMenu();
	scanf(" %d", &iItem);
	getchar();
	while(iItem)
	{
		switch(iItem)
		{
		case 1:
			ManageBook();
			break;
		case 2:
			ManageReader();
			break;
		case 3:
			BorrowReturnManage();
			break;
		default:
			printf("\t\t 请输入正确的数字!\n\t\t程序将于3秒后跳转到主菜单");
			Sleep(3000);
		}
		ShowMainMenu();
		scanf(" % d", &iItem);
		getchar();
	}
	return 0;
}

void ShowMainMenu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t|-----------------------------欢迎进入----------------------------|\n");
	printf("\t|		图书馆管理系统												|\n");
	printf("\t|			主菜单													|\n");
	printf("\t|  1.图书管理系统													|\n");
	printf("\t|  2.读者管理系统													|\n");
	printf("\t|	 3.借/还书登记													|\n");
	printf("\t|  0.退出系统														|\n");
	printf("\t|-----------------------------------------------------------------|\n");
	printf("\n");
	printf("\t\t请选择(0-3): ");
}

void ManageBook()
{
	int iItem;
	ShowBookMenu();
	scanf(" % d", &iItem);
	getchar();
	while(iItem)
	{
		switch(iItem) 
		{
		case 1:
			ShowBook();
			break;
		case 2:
			AddBook();
			break;
		case 3:
			SearchBook();
			break;
		case 4:
			DeleteBook();
			break;
		case 5:
			ModifyBook();
			break;
		default:
			printf("\t\t请输入正确的数字!\n\t\t");
		}
		printf("| 按任意键返回子菜单 |");
		getch();

		ShowBookMenu();
		scanf(" % d", &iItem);
		getchar();
	}
}

void ShowBookMenu()
{
	system("cls");
	printf("\n\n\n\n");
	printf("\t|------------------------欢迎进入-------------------------------|\n");
	printf("\t|		图书管理系统												  |\n");
	printf("\t|		 子菜单													  |\n");
	printf("\t|     1.显示图书信息											  |\n");
	printf("\t|		2.新增图书信息											  |\n");
	printf("\t|     3.图书信息查询											  |\n");
	printf("\t|     4.图书信息删除											  |\n");
	printf("\t|     5.图书信息修改											  |\n");
	printf("\t|     0.返回主菜单												  |\n");
	printf("\t|---------------------------------------------------------------|\n");
	printf("\n");
	printf("\t\t 请选择（0 - 5): ");
}

void ShowBook()
{
	int i, iBookRecord;
	system("cls");
	iBookRecord = ReadBookFile("rb");
	if(iBookRecord == -1)
		printf("文件打开失败!请先新增图书信息!\n");
	else if(iBookRecord == 0)
		printf("文件中没有图书信息!\n");
	else
	{
		printf("\t|---------------------------------------------|\n");
		printf("\t % -6s% - 16s% -10s%  -20%s  -4s\n", "编号", "书名", "作者", "出版社", "库存");
		for(i = 0; i < iBookRecord; i++)
			printf("\t  % -6d%  -16s%  -10s%  -20s%  -4d\n", BOOK_DATA);
		printf("\t|---------------------------------------------|\n");
	}
}

void AddBook()
{
	FILE * pfBook;
	int iBookRecord, iFlagExist, i;
	char cFlag;

	system("cls");
	iBookRecord = ReadBookFile("ab+");
	if(iBookRecord == -1)
	{
		printf("文件打开失败!\n");
		return;
	}
	else if(iBookRecord == 0)
		printf("没有图书记录!\n");
	else
		ShowBook();

	printf("请选择是否输入信息(y/n):");
	cFlag = getchar();
	getchar();
	if(cFlag == '\n')
		return;
	pfBook = fopen("book.txt", "ab+");
	if(pfBook == NULL)
	{
		printf("文件打开失败!\n");
		return;
	}
	while(cFlag == 'y')
	{
		if(iBookRecord >= BOOK_NUM)
		{
			printf("记录已满!");
			fclose(pfBook);
			return;
		}
		printf("请输入图书编号: ");
		do{
			iFlagExist = 0;
			scanf("%d", &astBook[iBookRecord].iNum);
			getchar();
			for(i = 0; i < iBookRecord; i++)
			{
				if(astBook[i].iNum == astBook[iBookRecord].iNum)
				{
					iFlagExist = 1;
					printf("该图书编号已经存在, 请重新输入:");
					break;
				}
			}
		} while(iFlagExist == 1);
		printf("请输入图书名称: ");
		gets(astBook[iBookRecord].acName);
		printf("请输入图书作者: ");
		gets(astBook[iBookRecord].acAuthor);
		printf("请输入图书出版社: ");
		gets(astBook[iBookRecord].acPress);
		printf("请输入图书库存量: ");
		scanf(" % d", &astBook[iBookRecord].iAmount);
		getchar();
		if(fwrite(&astBook[iBookRecord], LEN_BOOK, 1, pfBook) != 1)
		{
			printf("无法保存该信息!\n");
			return;
		}
		else
		{
			printf("% d 号图书信息已保存!\n", astBook[iBookRecord].iNum);
			iBookRecord++;
		}
		printf("继续输入信息吗(y/n)";
		cFlag = getchar();
		getchar();
	}
	fclose(pfBook);
	printf("添加图书执行完毕!\n");
}

int SearchBook()
{
	int iBookNum, iBookRecord, iBookId, i;
	system("cls");
	iBookRecord = ReadBookFile("rb");
	if(iBookRecord == -1)
	{
		printf("文件打开失败!\n");
		printf("| 按任意键返回子菜单 |");
		getch();
		return -2;
	}
	else if(iBookRecord == 0)
	{
		printf("没有图书记录!\n");
		printf("|按任意键返回子菜单 |");
		getch();
		return -3;
	}

	printf("请输入图书编号: ");
	scanf(" %d", &iBookNum);
	getchar();
	for(i = 0; i < iBookRecord; i++)
	{
		if(iBookNum == astBook[i].iNum)
		{
			iBookId = i;
			printf("%d 号图书信息如下:\n", iBookNum);
			printf("\t|--------------------------------------|\n");
			printf("\t % -6s% -16%s -10%s -20%s -4s\n","编号", "书名", "作者", "出版社", "库存");
			printf("\t % -6d% -16%s -10%s -20%s -4d\n",BOOK_DATA);
			printf("\t|--------------------------------------|\n");
			break;
		}
	}
	if(i == iBookRecord)
	{
		printf("找不到%d号图书信息!\n", iBookNum);
		iBookId = -1;
	}
	return iBookId;
}

void DeleteBook()
{
	FILE * pfBook;
	int iBookId, iBookRecord, i;
	char cFlag;

	system("cls");
	iBookId = SearchBook();
	if(iBookId == -1)
		return;
	iBookRecord = ReadBookFile("rb");
	printf("已找到该图书,是否删除?(y/n)");
	cFlag = getchar();
	getchar();
	if(cFlag == 'n')
		return;
	else if(cFlag == 'y')
	{
		for(i = iBookId; i < iBookRecord - 1; i++)
			astBook[i] = astBook[i + 1];
		iBookRecord--;
	}

	pfBook = fopen("book.txt", "wb");
	if(pfBook != NULL)
	{
		for(i = 0; i < iBookRecord; i++)
		{
			if(fwrite(&astBook[i], LEN_BOOK, 1, pfBook) != 1)
			{
				printf("无法保存该信息!\n");
				return;
			}
		}
		fclose(pfBook);
		printf("%d 号图书信息已删除!\n", astBook[iBookId].iNum);
	}
}

void ModifyBook()
{
	int iBookId, iBookRecord, iFlagExist, iItem, iNum, i;
	system("cls");
	iBookId = SearchBook();
	if(iBookId == -1)
		return;
	iBookRecord = ReadBookFile("rb");
	ShowModifyBookMenu();
	scanf("% d",&iItem);
	getchar();
	switch(iItem)
	{
	case 1:
		printf("请输入图书编号:");
		do {
			iFlagExist = 0;
			scanf("% d", &iNum);
			getchar();
			for(i = 0; i < iBookRecord; i++)
			{
				if(iNum == astBook[i].iNum && i != iBookId)
				{
					iFlagExist = 1;
					printf("错误, 该图书编号已存在,请重新输入:");
					break;
				}
			}
		}while(iFlagExist == 1);
		astBook[iBookId].iNum = iNum;
		break;
	case 2:
		printf("请输入图书名称: ");
		gets(astBook[iBookId].acName);
		break;
	case 3:
		printf("请输入图书作者: ");
		gets(astBook[iBookId].acAuthor);
		break;
	case 4:
		printf("请输入图书出版社: ");
		gets(astBook[iBookId].acPress);
		break;
	case 5:
		printf("请输入图书库存量: ");
		scanf("% d", &astBook[iBookId].iAmount);
		getchar();
		break;
	}
	SaveBookFile(iBookId);
	printf("图书信息修改成功!\n");
}

void ShowModifyBookMenu()
{
	printf("\n");
	printf("\t|					1.编号					|\n");
	printf("\t|					2.书名					|\n");
	printf("\t|					3.作者					|\n");
	printf("\t|					4.出版社					|\n");
	printf("\t|					5.库存					|\n");
	printf("\n");
	printf("请输入所要修改的信息(输入相应的数字: 1-5):");
}

int ReadBookFile(char * pcMode)
{
	int iBookRecord = 0;
	FILE * pfBook;
	pfBook = fopen("book.txt", pcMode);
	if(pfBook == NULL)
		return -1;
	while(!feof(pfBook))
	{
		if(fread(&astBook[iBookRecord], LEN_BOOK, 1, pfBook))
			iBookRecord++;
	}
	fclose(pfBook);
	return iBookRecord;
}
void SaveBookFile(int iBookId)
{
	FILE *pfBook;
	pfBook = fopen("book.txt", "rb+");
	if(pfBook != NULL)
	{
		fseek(pfBook, LEN_BOOK * iBookId, SEEK_SET);
		if (fwrite(&astBook[iBookId], LEN_BOOK, 1, pfBook) != 1)
			printf("无法保存该信息!\n");
	}
	fclose(pfBook);
}


//Reader model

void ModifyReader()
{
	int iReaderId, iReaderRecord, iBorrow, iItem, iNum, iMax, iFlagExist, i;
	system("cls");
	iReaderId = SearchReader();
	if(iReaderId == -1)
		return;
	iReaderRecord = ReadReaderFile("rb");
	ShowModifyReaderMenu();
	scanf("%d", &iItem);
	getchar();
	switch(iItem)
	{
	case 1:
		printf("请输入读者编号 :");
		do {
			iFlagExist = 0;
			scanf("%d", &iNum);
			getchar();
			for(i = 0; i < iReaderRecord; i++)
				if(iNum == astReader[i].iNum && i != iReaderId)
				{
					iFlagExist = 1;
					printf("错误, 该读者编号已经存在,请重新输入:\n");
					break;
				}
		}while(iFlagExist == 1);
		astReader[iReaderId].iNum = iNum;
		break;
	case 2:
		printf("请输入读者名字: ");
		gets(astReader[iReaderId].acName);
		break;
	case 3:
		printf("请输入读者性别: F/M:");
		while(gets(astReader[iReaderId].acSex) != NULL)
		{
			if(strcmp(astReader[iReaderId].acSex, "F") == 0 || strcmp(astReader[iReaderId].acSex, "M") == 0)
				break;
			printf("错误,只能输入'F'或者'M',请重新输入\n");
		}
		break;
	case 4:
		iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
		printf("请输入读者最大可借书数:(范围为5-10): ");
		while(scanf("%d", &iMax) == 1)
		{
			getchar();
			if(iMax >= 5 && iMax <= 10)
			{
				if(iBorrow > iMax)
				{
					printf("该读者目前借阅图书数量大于该数目,需要先还书后修改!\n");
					return;
				}
				else
				{
					astReader[iReaderId].iMax  = iMax;
					astReader[iReaderId].iAmount = iMax - iBorrow;
					for(i = iBorrow; i < iMax; i++)
						astReader[iReaderId].aiBookId[i] = 0;
					break;
				}
			}
			printf("错误,读者最大借阅数范围为5-10,请重新输入\n");
		}
		break;
	}
	SaveReaderFile(iReaderId);
	printf("读者信息修改成功!\n");
}

void BorrowReturnManage()
{
	int iItem = 0;
	ShowBorrowReturnMenu();
	scanf("%d", &iItem);
	getchar();

	while(iItem)
	{
		switch(iItem)
		{
		case 1:
			BorrowBook();
			break;
		case 2:
			ReturnBook();
			break;
		default:
			printf("\t\t请输入正确的数字!\n\t\t");
		}
		printf("|按任意键返回子菜单  |");
		getch();
		ShowBorrowReturnMenu();
		scanf("%d", &iItem);
		getchar();
	}
}

void ShowBorrowReturnMenu()
{
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t|--------------------------------欢迎进入-----------------------------------|\n");
	printf("\t|------------------------------借/还书登记----------------------------------|\n");
	printf("\t|--------------------------------子菜单-------------------------------------|\n");
	printf("\t|-------------------------------1.借书登记-----------------------------------|\n");
	printf("\t|-------------------------------2.还书登记-----------------------------------|\n");
	printf("\t|-------------------------------0.返回主菜单---------------------------------|\n");
	printf("\n");
	printf("\t\t请选择(0-2):");
}

void BorrowBook()
{
	system("cls");
	int iBookId, iReaderId, iBorrow, i;
	iReaderId = SearchReader();
	if(iReaderId == -1)
		return;
	iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
	if(iBorrow == 0)
		printf("该读者目前没有借任何书\n");
	else
	{
		printf("\t 该读者当前所借阅图书为: ");
		for(i = 0; i < iBorrow; i++)
			printf("%d", astReader[iReaderId].aiBookId[i]);
		printf("\n\n");
	}
	if(astReader[iReaderId].iAmount == 0)
	{
		printf("该读者可借书量为零,不能继续借书!\n");
		return;
	}

	printf("\n按任意键输入要借阅的图书信息\n");
	getch();

	iBookId = SearchBook();
	if(iBookId == -1)
		return;
	if(astBook[iBookId].iAmount == 0)
	{
		printf("该图书库存量为零!图书不可借\n");
		return;
	}
	astReader[iReaderId].aiBookId[iBorrow] = astBook[iBookId].iNum;
	astBook[iBookId].iAmount--;
	astReader[iReaderId].iAmount--;

	SaveBookFile(iBookId);
	SaveReaderFile(iReaderId);
	printf("借书成功!\n");
}

void ReturnBook()
{
	int iBookId, iReaderId, iBorrow, i, j;
	system("cls");
	iReaderId = SearchReader();
	if(iReaderId == -1)
		return;
	iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
	if(iBorrow == 0)
	{
		printf("\t 该读者没有借任何书,无须归还\n");
		return;
	}
	else
	{
		printf("\t 该读者当前所借阅图书为:");
		for(i = 0; i < iBorrow; i++)
			printf("%d", astReader[iReaderId].aiBookId[i]);
		printf("\n\n");
	}
	printf("按任意键输入要归还的图书信息\n");
	getch();
	iBookId = SearchBook();
	if(iBookId == -1)
		return;
	for(i = 0; i < iBorrow; i++)
		if(astReader[iReaderId].aiBookId[i] == astBook[iBookId].iNum)
		{
			for(j = i; j < iBorrow - 1; j++)
				astReader[iReaderId].aiBookId[j] = astReader[iReaderId].aiBookId[j + 1];
			astReader[iReaderId].aiBookId[iBorrow] = 0;

			astBook[iBookId].iAmount++;
			astReader[iReaderId].iAmount++;
			break;
		}
	if(i == iBorrow)
	{
		printf("该读者没有借这本书,无须归还\n");
		return;
	}

	SaveBookFile(iBookId);
	SaveReaderFile(iReaderId);
	printf("还书成功\n");
}