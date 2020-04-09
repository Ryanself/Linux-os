#include <stdio.h>
#include <time.h>
//n 层楼梯 每次爬1层 或2 层，共有多少种爬法。
//firstly, we thought to solve the question by use recursion.(递归）
//f(1) = 1
//f(2) = 2
//f(n) = f(n-1) + f(n-2)
//O()
static int f(int n)
{
		if (n <= 0)
			  return 0;
		if (n == 1)
			  return 1;
		if (n == 2)
			  return 2;

		return f(n - 1) + f(n - 2);
}
//DP 的时间 在n>43之后能够清晰的察觉到递归对时间的消耗更大 O(n)
static int dp(int n)
{
		if (n == 1)
			  return 1;
		if (n == 2)
			  return 2;
		if (n > 100)
			  return -1;
		int a[100] = {0};
		a[0] = 0;
		a[1] = 1;
		a[2] = 2;
		int m = 0;
		int i = 0;
		for(i = 3; i <= n; i ++)
		{
				a[i] = a[i-1] + a[i -2];
		}
		return a[n];

}

void main(void)
{
		int a = 0;
		printf("please input floor number!\n");
		scanf("%d", &a);
		time_t t;
		struct tm * lt;
		time (&t);//获取Unix时间戳。
		lt = localtime (&t);//转为时间结构。
		printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec );//输出结果
		printf("there is %d kinds of ways to the top of the building.\n", f(a));
		time (&t);//获取Unix时间戳。
		lt = localtime (&t);//转为时间结构。
		printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec );//输出结果
		printf("there is %d kinds of ways to the top of the building.\n", dp(a));
		time (&t);//获取Unix时间戳。
		lt = localtime (&t);//转为时间结构。
		printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec );//输出结果
		return ;
}

/*
 * DP learning
 * */
