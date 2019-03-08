#include <stdio.h>
void main()
{
	int a = 3, b = 4;
	a ^= b; //a = a + b;// int c = b;
	b ^= a; //b = a - b;// b = a;
	a ^= b; //a = a - b;// a = c;
	printf("%d%d", a, b);
}
