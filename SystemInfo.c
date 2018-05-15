#include<stdio.h>
#include<time.h>
#include<dos.h>
#include<Windows.h>
struct SYSTEMINFO
{
	unsigned char current_second;
	unsigned char alarm_second;
	unsigned char current_minute;
	unsigned char alarm_minute;
	unsigned char current_hour;
	unsigned char alarm_hour;
	unsigned char current_day_of_week;
	unsigned char current_day;
	unsigned char current_month;
	unsigned char current_year;
	unsigned char status_registers[4];
	unsigned char diagnostic_status;
	unsigned char shutdown_code;
	unsigned char drive_types;
	unsigned char reserved_x;
	unsigned char disk_l_type;
	unsigned char reserved;
	unsigned char equipment;
	unsigned char lo_mem_base;
	unsigned char hi_mem_base;
	unsigned char lo_exp_base;
	unsigned char hi_exp_base;
	unsigned char fdisk_0_type;
	unsigned char fdisk_1_type;
	unsigned char reserved_2[9];
	unsigned char hi_check_sum;
	unsigned char lo_check_sum;
	unsigned char hi_actual_exp;
	unsigned char lo_actual_exp;
	unsigned char century;
	unsigned char information;
	unsigned char reserved3[12];
};
void Stime() 
{
	time_t now;								/*声明time_t类型变量*/
	time(&now);								/*获取当前系统日期与时间*/
	printf("\n Now is:%s", ctime(&now));	/*输出当前系统日期与时间*/
}
/**
void DetectHDD()
{
	struct dfree diskfree;
	struct fatinfo fatinfo;
	puts("The information of the current disk is:\n");
	getdfree(0, &diskfree);
	getfat(0, &fatinfo);
	puts("-----------------------hard disk space----------------------");
	printf(">>The num of avaible clusters is : %d\n", diskfree.df_avail);
	printf(">>The num of all clusters is: %d\n", diskfree.df_total);
	printf(">>The num of bytes of every sector is: %d\n", diskfree.df_bsec);
	printf(">>The num of sectors of every cluster is: %d\n", diskfree.df_sclus);
	puts("-----------------------file allocation table-----------------");
	printf(">>The num of sectors of every cluster is :%d\n", fatinfo.fi_sclus);
	printf(">>The num of bytes of file allocation table is: %d\n", fatinfo.fi_fatid);
	printf(">>The num of clusters is: %d\n", fatinfo.fi_nclus);
	printf(">>The num of ytes of every sector is :%d\n", fatinfo.fi_bysec);
}
**/
void Paths()
{
	char *path, *ptr;
	int i = 0;
	puts("This program is to get the information of environ.");
	while(environ[i])
		printf(">>%s\n", environ[i++]);
}
/**
void Systeminfo()
{
	struct SYSTEMINFO systeminfo;
	int i, size;
	char *ptr_sysinfo, byte;
	puts("*****************************************************************");
	puts("* Get configure information of your system*");
	puts("*****************************************************************");
	size = sizeof(systeminfo);
	ptr_sysinfo = (char*) &systeminfo;
	for(i = 0; i < size; i++)
	{
		outportb(0x70, (char)i);
		byte=inportb(0x71);
		*ptr_sysinfo++=byte;
	}
	printf("--The current data is: %x/%x/0%x.\n",systeminfo.current_day, systeminfo.current_month, systeminfo.current_year);
	printf("--The current time is: %x:%x:%x. \n",systeminfo.current_hour, systeminfo.current_minute, systeminfo.current_second);
	printf("--The alarm time is: %x:%x :%x.\n", systeminfo.alarm_minute, systeminfo.alarm_second);
}
**/
void main() 
{
	while(1) {
		int flag;
		printf("1.Show the time!\n");
		printf("2.Show the information of the current disk\n");
		printf("3.Show the inof of the system!\n");
		printf("4.Show the path info!\n");
		printf("5.Show the of inofmation of display card!\n");

		printf("input your choice:");
		scanf("%d", &flag);
		switch(flag)
		{
		case 1:
			Stime();
			break;
		case 2:
			break;
		case 3:
			Paths();
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	}
}


