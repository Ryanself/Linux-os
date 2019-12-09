#include <stdio.h>
#include <string.h>

int main(void)
{
	char *ssid = "1111";
	//int a = strlen(ssid);
	//printf("%d", a);
	int i = 0;
	char *argv[3];
	char b[5];
	int a = 513;
	sprintf(argv[i], "%d", a);
	//argv[i++] = b;
	printf("%s ", argv[0]);
	int d =120;
	d =  atoi(argv[0]) > 120 ? atoi(argv[0]) : 120;
	printf("%d", d);

	return 0;

}
