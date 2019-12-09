#include <stdio.h>

int gcd(int a, int b)
{
	printf("%d and %d gcd\n", a, b);
	int c = 0;
	if (a < b)
	{
		c = a;
		a = b;
		b = c;
	}
	if((a%b) == 0)
	      return b;
	else
	      return gcd(b, a%b);
}

int main (void)
{
	int a, b, c = 0;
	scanf("%d %d", &a, &b);
	c = gcd(a, b);
	printf("%d and %d gcd is : %d .\n", a, b, c);
	return 0;
}
