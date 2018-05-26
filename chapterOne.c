#include <stdio.h>
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