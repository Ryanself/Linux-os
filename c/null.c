#include <stdio.h>

struct aa{
	int a[6];
	int b;
};

void main()
{
	struct aa test;
	test.a[0] =  32;
	test.a[1] = 44;
	const int *d = test.a;
	printf(">>>>>>>>>test.a %d\n", d[0]);
	if (NULL) {
		printf("nullllllllllll");
	}
	else
	{
		printf("zzzzzzzzzzzzzzzz");
	}
	return;
}
