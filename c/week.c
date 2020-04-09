#include <stdio.h>
#include <stdint.h>

void main(void)
{
	int year, month, day;
	printf("please input year month day !\n");
	scanf("%d%d%d", &year, &month, &day);
	int week = (day + 2*month + 3*(month + 1)/5 + year + year/4 - year/100 + year/400)%7 + 1;
	printf("%d-%d-%d in week is %d .\n", year, month, day, week);
}
