#include <stdio.h>
//入门例子 面额11 5 1的钞票 需要付款w 最少张数
static min(int a, int b, int c)
{
	a = (a > b) ? b : a;
	return (a > c) ? b : a;
}

static int f(int w)
{
	if(w == 11 || w == 5 || w == 1)
	      return 1;
	else if(w < 5)
	      return w;
	else if(w <11)
	      return 1+f(w-5);
	else
	      return 1+min(f(w - 11), f(w - 5), f(w - 1));
}

int main(void)
{
	int w = 15;
	int a = f(w);
	printf("------%d-----]\n", a);
	return 0;
}

// f(i) 没有保存导致运行时间会变大
