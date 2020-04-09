#include <stdio.h>

//ascll
//0-9  48-57
//A-Z 65-90
//a-z 97-122

/* 之后涉及的就是大数（除）减法 。
 * 然后好像就没有难度了。
 */
static	int ab[21] = {2, 3, 5, 7 , 11,  13, 17, 19, 23, 29,  31, 34, 37, 41, 43,  47,53,57,59,61,  67};
static int pr(int p)
{
		if (p <= 9)
			  p += 48;
		else if (p <= 35)
			  p += 55;
		else
			  p += 61;
		return p;
}
static int zj(int n, char s){
		int d[20][2] = {0};
		int a = (int)s;
		if (a<= 57)
			  a = a -48;
		else if (a <= 90){
				a = a - 65;
				a = a + 10;
		} else {
				a = a -97;
				a = a + 36;
		};
		int i = 0;
		int m = 0;
		for (i = 0;n !=0;i ++)
		{
				m  = n%a;
				n = n/a;
				d[i][0] = 1;
				d[i][1] = m;
		}
		i --;
		for (i;i>=0;i--)
			  printf("%c",pr(d[i][1]));

		printf("  ");


		return 0;
}
static int zj2(char j)
{
		int m = 0;
		if (j<= 57)
			  m =57;
		else if (j < 90){
				m = 90;
		} else {
				m =122;}
		int i = 0;

		for (j; j <=m;j++)
		{
				i = 0;
				printf("%c ",j);
				for(i; i < 21;i++){
						zj(ab[i], j);
						printf(" ");
				}
				printf("\n");
		}
}

int main(void){
		int i = 0;
		//add a func to get a[];
		for(i; i < 21;i++)
			  printf("%d ",ab[i]);
		printf("\n");

		zj2('2');
		zj2('A');
		zj2('a');
		return 0;
}
