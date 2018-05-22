#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void get_next(int *next, char *a, int la)
{
	int i = 1, j = 0;
	next[1] = 0;
	while(i <= la)
	{
		if(a[i] == a[j] || j == 0)
		{
			j++;
			i++;
			if(a[i] == a[j])
				next[i] = next[j];
			else
				next[i] = j;
		}
		else
			j = next[j];
	}
}
int str_kmp(int *next, char *A, char *a, int lA, int la)
{
	int i, j;
	i = 1;
	j = 1;
	while(i <= lA && j <= la)
	{
		if(A[i] == a[j] || j == 0)
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if(j > la)
		return i - j + 1;
	else
		return -1;
}
int main()
{
	int k, lA = 0, la = 0, next[101];
	char A[101], a[101];
	memset(next, 0, sizeof(next));
	printf("请输入原字符串: \n");
	gets(A);
	printf("请输入要查找的字符串: \n");
	gets(a);

	lA = strlen(A);
	la = strlen(a);
	for(k = la - 1; k >= 0; k--)
		a[k + 1] = a[k];
	for(k = lA - 1; k >= 0; k--)
		A[k + 1] = A[k];
	get_next(next, a, la);
	k = str_kmp(next, A, a, lA, la);
	if(k == -1)
		printf("没有找到!");
	else
	{
		printf("找到的位置为: %d\n", k);
	}
	return 0;
}