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
			printf("\t\t ��������ȷ������!\n\t\t������3�����ת�����˵�");
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
	printf("\t|-----------------------------��ӭ����----------------------------|\n");
	printf("\t|		ͼ��ݹ���ϵͳ												|\n");
	printf("\t|			���˵�													|\n");
	printf("\t|  1.ͼ�����ϵͳ													|\n");
	printf("\t|  2.���߹���ϵͳ													|\n");
	printf("\t|	 3.��/����Ǽ�													|\n");
	printf("\t|  0.�˳�ϵͳ														|\n");
	printf("\t|-----------------------------------------------------------------|\n");
	printf("\n");
	printf("\t\t��ѡ��(0-3): ");
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
			printf("\t\t��������ȷ������!\n\t\t");
		}
		printf("| ������������Ӳ˵� |");
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
	printf("\t|------------------------��ӭ����-------------------------------|\n");
	printf("\t|		ͼ�����ϵͳ												  |\n");
	printf("\t|		 �Ӳ˵�													  |\n");
	printf("\t|     1.��ʾͼ����Ϣ											  |\n");
	printf("\t|		2.����ͼ����Ϣ											  |\n");
	printf("\t|     3.ͼ����Ϣ��ѯ											  |\n");
	printf("\t|     4.ͼ����Ϣɾ��											  |\n");
	printf("\t|     5.ͼ����Ϣ�޸�											  |\n");
	printf("\t|     0.�������˵�												  |\n");
	printf("\t|---------------------------------------------------------------|\n");
	printf("\n");
	printf("\t\t ��ѡ��0 - 5): ");
}

void ShowBook()
{
	int i, iBookRecord;
	system("cls");
	iBookRecord = ReadBookFile("rb");
	if(iBookRecord == -1)
		printf("�ļ���ʧ��!��������ͼ����Ϣ!\n");
	else if(iBookRecord == 0)
		printf("�ļ���û��ͼ����Ϣ!\n");
	else
	{
		printf("\t|---------------------------------------------|\n");
		printf("\t % -6s% - 16s% -10s%  -20%s  -4s\n", "���", "����", "����", "������", "���");
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
		printf("�ļ���ʧ��!\n");
		return;
	}
	else if(iBookRecord == 0)
		printf("û��ͼ���¼!\n");
	else
		ShowBook();

	printf("��ѡ���Ƿ�������Ϣ(y/n):");
	cFlag = getchar();
	getchar();
	if(cFlag == '\n')
		return;
	pfBook = fopen("book.txt", "ab+");
	if(pfBook == NULL)
	{
		printf("�ļ���ʧ��!\n");
		return;
	}
	while(cFlag == 'y')
	{
		if(iBookRecord >= BOOK_NUM)
		{
			printf("��¼����!");
			fclose(pfBook);
			return;
		}
		printf("������ͼ����: ");
		do{
			iFlagExist = 0;
			scanf("%d", &astBook[iBookRecord].iNum);
			getchar();
			for(i = 0; i < iBookRecord; i++)
			{
				if(astBook[i].iNum == astBook[iBookRecord].iNum)
				{
					iFlagExist = 1;
					printf("��ͼ�����Ѿ�����, ����������:");
					break;
				}
			}
		} while(iFlagExist == 1);
		printf("������ͼ������: ");
		gets(astBook[iBookRecord].acName);
		printf("������ͼ������: ");
		gets(astBook[iBookRecord].acAuthor);
		printf("������ͼ�������: ");
		gets(astBook[iBookRecord].acPress);
		printf("������ͼ������: ");
		scanf(" % d", &astBook[iBookRecord].iAmount);
		getchar();
		if(fwrite(&astBook[iBookRecord], LEN_BOOK, 1, pfBook) != 1)
		{
			printf("�޷��������Ϣ!\n");
			return;
		}
		else
		{
			printf("% d ��ͼ����Ϣ�ѱ���!\n", astBook[iBookRecord].iNum);
			iBookRecord++;
		}
		printf("����������Ϣ��(y/n)";
		cFlag = getchar();
		getchar();
	}
	fclose(pfBook);
	printf("���ͼ��ִ�����!\n");
}

int SearchBook()
{
	int iBookNum, iBookRecord, iBookId, i;
	system("cls");
	iBookRecord = ReadBookFile("rb");
	if(iBookRecord == -1)
	{
		printf("�ļ���ʧ��!\n");
		printf("| ������������Ӳ˵� |");
		getch();
		return -2;
	}
	else if(iBookRecord == 0)
	{
		printf("û��ͼ���¼!\n");
		printf("|������������Ӳ˵� |");
		getch();
		return -3;
	}

	printf("������ͼ����: ");
	scanf(" %d", &iBookNum);
	getchar();
	for(i = 0; i < iBookRecord; i++)
	{
		if(iBookNum == astBook[i].iNum)
		{
			iBookId = i;
			printf("%d ��ͼ����Ϣ����:\n", iBookNum);
			printf("\t|--------------------------------------|\n");
			printf("\t % -6s% -16%s -10%s -20%s -4s\n","���", "����", "����", "������", "���");
			printf("\t % -6d% -16%s -10%s -20%s -4d\n",BOOK_DATA);
			printf("\t|--------------------------------------|\n");
			break;
		}
	}
	if(i == iBookRecord)
	{
		printf("�Ҳ���%d��ͼ����Ϣ!\n", iBookNum);
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
	printf("���ҵ���ͼ��,�Ƿ�ɾ��?(y/n)");
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
				printf("�޷��������Ϣ!\n");
				return;
			}
		}
		fclose(pfBook);
		printf("%d ��ͼ����Ϣ��ɾ��!\n", astBook[iBookId].iNum);
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
		printf("������ͼ����:");
		do {
			iFlagExist = 0;
			scanf("% d", &iNum);
			getchar();
			for(i = 0; i < iBookRecord; i++)
			{
				if(iNum == astBook[i].iNum && i != iBookId)
				{
					iFlagExist = 1;
					printf("����, ��ͼ�����Ѵ���,����������:");
					break;
				}
			}
		}while(iFlagExist == 1);
		astBook[iBookId].iNum = iNum;
		break;
	case 2:
		printf("������ͼ������: ");
		gets(astBook[iBookId].acName);
		break;
	case 3:
		printf("������ͼ������: ");
		gets(astBook[iBookId].acAuthor);
		break;
	case 4:
		printf("������ͼ�������: ");
		gets(astBook[iBookId].acPress);
		break;
	case 5:
		printf("������ͼ������: ");
		scanf("% d", &astBook[iBookId].iAmount);
		getchar();
		break;
	}
	SaveBookFile(iBookId);
	printf("ͼ����Ϣ�޸ĳɹ�!\n");
}

void ShowModifyBookMenu()
{
	printf("\n");
	printf("\t|					1.���					|\n");
	printf("\t|					2.����					|\n");
	printf("\t|					3.����					|\n");
	printf("\t|					4.������					|\n");
	printf("\t|					5.���					|\n");
	printf("\n");
	printf("��������Ҫ�޸ĵ���Ϣ(������Ӧ������: 1-5):");
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
			printf("�޷��������Ϣ!\n");
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
		printf("��������߱�� :");
		do {
			iFlagExist = 0;
			scanf("%d", &iNum);
			getchar();
			for(i = 0; i < iReaderRecord; i++)
				if(iNum == astReader[i].iNum && i != iReaderId)
				{
					iFlagExist = 1;
					printf("����, �ö��߱���Ѿ�����,����������:\n");
					break;
				}
		}while(iFlagExist == 1);
		astReader[iReaderId].iNum = iNum;
		break;
	case 2:
		printf("�������������: ");
		gets(astReader[iReaderId].acName);
		break;
	case 3:
		printf("����������Ա�: F/M:");
		while(gets(astReader[iReaderId].acSex) != NULL)
		{
			if(strcmp(astReader[iReaderId].acSex, "F") == 0 || strcmp(astReader[iReaderId].acSex, "M") == 0)
				break;
			printf("����,ֻ������'F'����'M',����������\n");
		}
		break;
	case 4:
		iBorrow = astReader[iReaderId].iMax - astReader[iReaderId].iAmount;
		printf("������������ɽ�����:(��ΧΪ5-10): ");
		while(scanf("%d", &iMax) == 1)
		{
			getchar();
			if(iMax >= 5 && iMax <= 10)
			{
				if(iBorrow > iMax)
				{
					printf("�ö���Ŀǰ����ͼ���������ڸ���Ŀ,��Ҫ�Ȼ�����޸�!\n");
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
			printf("����,��������������ΧΪ5-10,����������\n");
		}
		break;
	}
	SaveReaderFile(iReaderId);
	printf("������Ϣ�޸ĳɹ�!\n");
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
			printf("\t\t��������ȷ������!\n\t\t");
		}
		printf("|������������Ӳ˵�  |");
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
	printf("\t|--------------------------------��ӭ����-----------------------------------|\n");
	printf("\t|------------------------------��/����Ǽ�----------------------------------|\n");
	printf("\t|--------------------------------�Ӳ˵�-------------------------------------|\n");
	printf("\t|-------------------------------1.����Ǽ�-----------------------------------|\n");
	printf("\t|-------------------------------2.����Ǽ�-----------------------------------|\n");
	printf("\t|-------------------------------0.�������˵�---------------------------------|\n");
	printf("\n");
	printf("\t\t��ѡ��(0-2):");
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
		printf("�ö���Ŀǰû�н��κ���\n");
	else
	{
		printf("\t �ö��ߵ�ǰ������ͼ��Ϊ: ");
		for(i = 0; i < iBorrow; i++)
			printf("%d", astReader[iReaderId].aiBookId[i]);
		printf("\n\n");
	}
	if(astReader[iReaderId].iAmount == 0)
	{
		printf("�ö��߿ɽ�����Ϊ��,���ܼ�������!\n");
		return;
	}

	printf("\n�����������Ҫ���ĵ�ͼ����Ϣ\n");
	getch();

	iBookId = SearchBook();
	if(iBookId == -1)
		return;
	if(astBook[iBookId].iAmount == 0)
	{
		printf("��ͼ������Ϊ��!ͼ�鲻�ɽ�\n");
		return;
	}
	astReader[iReaderId].aiBookId[iBorrow] = astBook[iBookId].iNum;
	astBook[iBookId].iAmount--;
	astReader[iReaderId].iAmount--;

	SaveBookFile(iBookId);
	SaveReaderFile(iReaderId);
	printf("����ɹ�!\n");
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
		printf("\t �ö���û�н��κ���,����黹\n");
		return;
	}
	else
	{
		printf("\t �ö��ߵ�ǰ������ͼ��Ϊ:");
		for(i = 0; i < iBorrow; i++)
			printf("%d", astReader[iReaderId].aiBookId[i]);
		printf("\n\n");
	}
	printf("�����������Ҫ�黹��ͼ����Ϣ\n");
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
		printf("�ö���û�н��Ȿ��,����黹\n");
		return;
	}

	SaveBookFile(iBookId);
	SaveReaderFile(iReaderId);
	printf("����ɹ�\n");
}