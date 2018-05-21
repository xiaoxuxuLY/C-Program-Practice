#include<stdio.h>
#include<stdlib.h>
//����һ��������������
//���ڽṹ��
typedef struct D
{
	int year;
	int month;
	int day;
} Date;

int getDays(Date date1, Date date2); //��ȡ�������ڼ������
int IsLeapYear(int year);			 //�Ƿ�Ϊ����
int GetMaxDay(int year, int month);  //��ȡĳ���µ����ʵ�ʣ�����
int main(int argc,  char** argv)
{
	int days;
	Date start, end;
	printf("�������һ������(1949.10.1):");
	scanf("%d.%d.%d",&start.year, &start.month, &start.day);

	printf("������ڶ�������(2018.5.21):");
	scanf("%d.%d.%d",&end.year, &end.month, &end.day);

	days = getDays(start, end);
	printf("�������ڼ����%d��\n", days);
	return 0;
}
int IsLeapYear(int year)
{
	return (year % 400 == 0 || year % 4 == 0 && year % 100 != 0);
}
int GetMaxDay(int year, int month)
{
	switch(month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		return IsLeapYear(year) ? 29 : 28;
	default:
		return -1;
	}
}

int getDays(Date date1, Date date2)
{
	int days = 0;
	if(date1.year == date2.year && date1.month == date2.month && date1.day == date2.day)
		return 0;
	else
	{
		if(date1.year == date2.year && date1.month == date2.month)
		{
			days = date2.day - date1.day;
			return days;
		}
		else if(date1.year == date2.year)
		{
			int start_maxday = GetMaxDay(date1.year, date1.month);
			days = start_maxday - date1.day;
			if(date2.month == date1.month + 1) //���һ��
			{
				days += date2.day;
				return days;
			}
			else
			{
				int m = date2.month, n = date1.month + 1;
				while(n != m)
				{
					days += GetMaxDay(date1.year, n);
					n++;
				}
				days += date2.day;
				return days;
			}
		}
	}
}
