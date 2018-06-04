#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int monthDay(int, int);
int IsLeapYear(int);
main()
{
	int days, weekDay, year, month = 1, d, i;
	printf("ÇëÊäÈëÄê: \n");
	scanf("%d", &year);
	days = year - 1 + (year - 1) / 400 + (year - 1) / 4 - (year - 1) / 100;

	while(month <= 12)
	{
		printf("\t\t\t%d-%d\n", year, month);
		printf("Sun\tMon\tTues\tWed\tThur\Fir\tSat\n");
		d = 1, i = 1;
		weekDay = (days + 1) % 7;
		while(i <= weekDay)
		{
			printf("\t");
			i++;
		}
		while(d <= monthDay(month, year))
		{
			weekDay = (days + 1) % 7;
			if(weekDay == 6)
				printf("%d\n", d);
			else
				printf("%d\t", d);
			if(d == monthDay(month, year))
				printf("\n");
			d++;
			days++;
		}
		month++;
	}
	system("PAUSE");
	return 0;
}
int monthDay(int month, int year)
{
	switch(month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
		break;
	case 4: case 6: case 9: case 11:
		return 30;
		break;
	case 2:
		if((IsLeapYear(year)) == 1)
			return 29;
		else
			return 28;
		break;
	}
}
int IsLeapYear(int year)
{
	if((year % 4 == 0) && (year % 100 != 0))
		return 1;
	if(year % 400 == 0)
		return 1;
	return 0;
}