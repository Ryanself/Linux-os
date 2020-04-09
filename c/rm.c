#include <stdio.h>
/*
 * Remove Duplicates from Sorted Array
 * 描述Given a sorted array, remove the duplicates in place such that each element
 * appear only once and returnthe new length.Do not allocate extra space for
 * another array, you must do this in place with constant memory.For example,
 * Given input array A = [1,1,2],
 * Your function should return length = 2, and A is now [1,2].
 * */
// array[0] is the length of the array.
static int *rmDup(int *array)
{
		int i = 0;
		int j = 1;
		int max = array[0];
		for( i = 2; i <= max ; i ++)
		{
				if(array[i] != array[j])
				{
						j ++;
						array[j] = array[i];
				}
		}
		array[0] = j;
		return array;
}


void main(void)
{
		int array[10] = {9, 1, 1, 4, 5, 6, 6, 6, 8, 9};
		int i = 0;
		rmDup(array);
		for(i;i <=array[0] ;i++)
			  printf("%d ", array[i]);
}
