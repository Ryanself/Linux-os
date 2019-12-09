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
	int n1 = 0, n2 = 0;
	//two way to get the number.
	if(nums1Size > nums2Size)
	{
		int mid = (nums1Size + nums2Size)/2
		while (n1 < mid && n2 < nums2Size)
		{
			if(*(nums1 + n1) > *(nums1 + n2))
			{

			}
			else
			{

			}
		}

	}
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
