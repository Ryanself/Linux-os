/**
 * leetcode No.4
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
*/
#include <stdio.h>
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
	double m1 = 0, m2 = 0;
	int mid1 = 0, n1 = 0, n2 = 0;
	//two way to get the number.
	if((nums1Size + nums2Size)%2 == 0)
	{
		mid1 = (nums1Size + nums2Size)/2;
		while((n1 + n2)  < mid1 + 1)
		{
			if(*(nums1 + n1) < *(nums2 +n2))
			{
				m2 = m1;
				m1 = *(nums1 + n1);
				n1 ++;
			}
			else
			{
				m2 = m1;
				m1 = *(nums2 + n2);
				n2 ++;
			}
			printf(" n1 %d n2 %d \n", n1, n2);
		}
		printf( " mid1 %d m1 %2f m2 %2f \n", mid1,  m1, m2);

	}
	else
	{
		mid1 = (nums1Size + nums2Size + 1)/2;
		while((n1 + n2)  < mid1)
		{
			if(*(nums1 + n1) < *(nums2 +n2))
			{
				m1 = *(nums1 + n1);
				n1 ++;
			}
			else
			{
				m1 = *(nums2 + n2);
				n2 ++;
			}
		}
		m2 = m1;
		printf( " mid1 %d m1 %2f m2 %2f \n", mid1,  m1, m2);
	}
	return (m1+m2)/2;
}

void main(void)
{
	int num1[7] = {1, 2, 3, 4, 6, 8, 9};
	int num1_size = 7;
	int num2[6] = {2, 3, 7, 9, 10, 11};
	int num2_size = 6;
	double a = findMedianSortedArrays(num1, num1_size, num2, num2_size);
	printf("middle %2f \n", a);
}
