#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1000
int getline(char line[], int maxline);
int remove(char s[]);
//remove trailing blanks and tabs, and delete blank lines
main()
{
	char line[MAXLINE];
	while(getline(line, MAXLINE) > 0)
		if(remove(line) > 0)
			printf("%s", line);
	return 0;
}
int remove(char s[])
{
	int i;
	i = 0;
	while(s[i] != '\n')
		++i;
	--i;
	while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
		--i;
	if(i >= 0) {
		++i;
		s[i] = '\n';
		++i;
		s[i] = '\0';
	}
	return i;
}
/**
#define LONGLINE 80

int getline(char line[], int maxline);
//print lines longer the LONGLINE
main()
{
	int len;
	char line[MAXLINE];
	while((len = getline(line, MAXLINE)) > 0)
		if(len > LONGLINE)
			printf("%s", line);
	return 0;
}
/**
#define MAXLINE 1000
int getline(char line[], int maxline);
void copy(char to[], char from[]);
//print longest input line
main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	max = 0;
	while((len = getline(line, MAXLINE)) > 0) {
		printf("%d , %s", len, line);
		if(len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if(max > 0)
		printf("%s", longest);
	return 0;
}
//getline: read a line into s, return length
int getline(char s[], int lim)
{
	int c, i, j;
	j = 0;
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
		if(i < lim -2) {
			s[j] = c;
			++j;
		}
		if(c == '\n') {
			s[j] = c;
			++j;
			++i;
		}
		s[j] = '\0';
		return i;
}
//copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
/**
float celsius(float fahr);
main()
{
	float fahr;
	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;
	
	fahr = lower;
	while(fahr <= upper) {
		printf("%3.0f  %6.1f\n", fahr, celsius(fahr));
		fahr = fahr + step;
	}
}

//celsius : convert fahr into celsius
float celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}
/**
#define MAXHIST 15
#define MAXCHAR 120
//print horizontal histogram freq. of different characters
main()
{
	int c, i;
	int len;
	int maxvalue;
	int cc[MAXCHAR];
	for(i = 0; i < MAXCHAR; ++i)
		cc[i] = 0;
	while((c = getchar()) != EOF)
		if(c < MAXCHAR)
			++cc[c];
	maxvalue = 0;
	for(i = 1; i < MAXCHAR; ++i)
		if(cc[i] > maxvalue)
			maxvalue = cc[i];
	for(i = 1; i < MAXCHAR; ++i) {
		if(isprint(i))
			printf("%5d - %c - %5d : ", i, i, cc[i]);
		else
			printf("%5d -    - %5d : ", i, cc[i]);
		if(cc[i] > 0) {
			if((len = cc[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		}
		else
			len = 0;
		while(len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
}
/**
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
//print vertical histogram
main()
{
	int c, i, j, nc, state;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	state = OUT;
	nc = 0;
	ovflow = 0;
	for(i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if(nc > 0) 
				if(nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		} else if (state = OUT) {
			state = IN;
			nc = 1;
		} else
			++nc;
	}
	maxvalue = 0;
	for(i = 1; i < MAXWORD; ++i)
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	for(i = MAXHIST; i > 0; --i) {
		for(j = 1; j < MAXWORD; ++j)
			if(wl[j] * MAXHIST / maxvalue >= i)
				printf(" * ");
			else
				printf("   ");
		putchar('\n');
	}
	for(i = 1; i < MAXWORD; ++i)
		printf("%4d ", i);
	putchar('\n');
	for(i = 1; i < MAXWORD; ++i)
		printf("%4d ", wl[i]);
	putchar('\n');
	if(ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
/**
//print horizontal histogram
main()
{
	int c, i, nc, state;
	int len;
	int maxvalue;
	int ovflow;
	int wl[MAXWORD];
	state = OUT;
	nc = 0;
	ovflow = 0;
	for(i = 0; i < MAXWORD; ++i)
		wl[i] = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ' ||c == '\n' || c == '\t') {
			state = OUT;
			if(nc > 0)
				if(nc < MAXWORD)
					++wl[nc];
				else
					++ovflow;
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1;
		} else
			++nc;
	}
	maxvalue = 0;
	for(i = 1; i < MAXWORD; ++i)
		if(wl[i] > maxvalue)
			maxvalue = wl[i];
	for(i = 1; i < MAXWORD; ++i) {
		printf("%5d - %5d : ", i, wl[i]);
		if(wl[i] > 0) {
			if((len = wl[i] * MAXHIST / maxvalue) <= 0)
				len = 1;
		} else
			len = 0;
		while(len > 0) {
			putchar('*');
			--len;
		}
		putchar('\n');
	}
	if(ovflow > 0)
		printf("There are %d words >= %d\n", ovflow, MAXWORD);
}
/**
//replace tabs and backspaces with visible characters
main() {
	int c;
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			printf("\\t");
		if (c == '\b')
			printf("\\b");
		if (c == '\\')
			printf("\\\\");
		if (c != '\b')
			if (c != '\t')
				if (c != '\\')
					putchar(c);
	}
}
/**
#define NONBLANK 'a'
main() {
	int c, lastc;
	lastc = NONBLANK;
	while((c = getchar()) != EOF) {
		if (c != ' ' || lastc != ' ')
			putchar(c);
		lastc = c;
	}
}
/**
//replace string of blanks with a single blank
main(){
	int c = 0, lastc;
	lastc = NONBLANK;
	while((c = getchar())!=EOF) {
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if(lastc != ' ')
				putchar(c);
		lastc = c;
	}
}
/**
// count blacks, tabs, and newlines
main() {
	int c, nb, nt, nl;
	nb = 0;
	nt = 0;
	nl = 0;
	while((c = getchar()) != EOF) {
		if(c == ' ')
			++nb;
		if(c == '\t')
			++nt;
		if(c == '\n')
			++nl;
	}
	printf("%d	%d	%d\n", nb,nt,nl);
}
/**
main() {
	printf("EOF is %d\n", EOF);
}
/**
main() {
	int c;
	while (c = getchar() != EOF)
		printf("%d\n", c);
	printf("%d - at EOF\n", c);
}
/**
main() {
	int fahr;
	for(fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%3d		%6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
/**
main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Celsius		Fahr\n");
	celsius = lower;
	while(celsius <= upper) {
		fahr = (9.0 * celsius) / 5.0 + 32.0;
		printf("%3.0f	%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
/**
main() {
	float fathr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("Fahr	Celsius\n");
	fathr = lower;
	while(fathr <= upper) {
		celsius = (5.0 / 9.0) * (fathr - 32.0);
		printf("%3.0f	%6.1f\n", fathr, celsius);
		fathr = fathr + step;
	}
}
**/