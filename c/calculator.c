#include <stdio.h>
#include <string.h>
static char m[9] = {' ', '_', ' ', '|', '_', '|', '|', '_', '|'};

static int b[10][9] = {
		{0, 1, 0, 1, 0, 1, 1, 1, 1},// 0 0 13456
		{0, 0, 0, 0, 0, 1, 0, 0, 1},// 1   36
		{0, 1, 0, 0, 1, 1, 1, 1, 0},// 2 0 2345
		{0, 1, 0, 0, 1, 1, 0, 1, 1},// 3 0 2356
		{0, 0, 0, 1, 1, 1, 0, 0, 1},// 4 1 236
		{0, 1, 0, 1, 1, 0, 0, 1, 1},// 5 0 1256
		{0, 1, 0, 1, 1, 0, 1, 1, 1},// 6 0 12456
		{0, 1, 0, 0, 0, 1, 0, 0, 1},// 7 0 36
		{0, 1, 0, 1, 1, 1, 1, 1, 1},// 8 0 123456
		{0, 1, 0, 1, 1, 1, 0, 1, 1},// 9 0 12356
};

static void cs (int a, int d)
{
		int i = d * 3;
		for(i ; i < d*3 + 3 ; i ++)
			  printf("%c", b[a][i] ? m[i]: ' ');
}

static void printcs(int a, int i)
{
		if(a != 0)
		{
				printcs(a/10, i);
				cs(a%10, i);
		}
}

void main(void)
{
		int a = 0;
		int i = 0;
		printf("please input a number!\n");
		scanf("%d", &a);
		printf("The number is: %d !\n", a);
		for (i = 0; i < 3; i++)
		{
				printcs(a, i);
				printf("\n");
		}
		return;
}

/*
 * @define m
 *  _    0
 * |_|  123
 * |_|  456
 *
 */

/*
   static int df(int a, int *b)
   {
   if (a != 0)
   {
 *b = 10* (*b) + a%10;
 df(a/10, b);
 }
 }

 void main(void)
 {
 int a =34567890;
 printf("The number is: %d !\n", a);
 int b = 0;
 df(a, &b);
 printf("a is : %d b is %d \n", a, b);
 return;
 }
 */
