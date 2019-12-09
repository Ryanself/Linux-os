#include <stdio.h>
#include <stdint.h>

void main(void)
{
	int a = 255;
	int b = (int8_t)a;
	uint32_t d = (uint32_t)b;
	int f = (int)d;
	int e = d;
	printf("a= %d b= %d\n", a, b);
	printf("d= %d d= %d\n", d, d);
	printf("e= %d f= %d\n", e, f);
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	int week = (day + 2*month + 3*(month + 1)/5 + year + year/4 - year/100 + year/400)%7 + 1;
	printf("%d-%d-%d in week is %d .\n", year, month, day, week);
}
