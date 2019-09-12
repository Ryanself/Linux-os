#include <stdio.h>

static int find_element(int *a, int size)
{
	int i = 0;
	int e = 0;
	for(i = 0; i < size; i++)
	{
		e ^= a[i];
	}

	return e;
}

void main(void)
{
	int array[9] = {3, 5, 1, 5, 6, 3, 4, 1, 6};
	int e = find_element(array, 9);
	int i = 0;
	int size = 9;
	for (i = 0; i < size; i ++)
	{
		printf("%d ", array[i]);
	}
	printf("the single element is %d .\n", e);
}

/*
 * 给定一个数组，数组元素成对出现，现插入一个单独的元素，请找出它。
 * 要求：
 * 1. 不适用额外内存空间
 * 2. 线性时间复杂度
 *
 * eg. 输入 [2, 2, 1]
 * 输出 1
 *
 * 主要考察异或
 * 异或你可以理解为不进位的加法
 * 你把数组里所有的全异或一遍
 * 最后只剩下孤独的那个
 * 其他的全因为相同加上去变成0了
 *
 * 我本来想的是排序之类，但想到快排的时间复杂度也nlogn 届不到届不到
 * */
