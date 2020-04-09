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
double findMedian(int *num, int numSize)
{
        if (numSize < 1)
              return -1;
        else if (numSize == 1)
              return *num;
        else {
                return ((numSize % 2 == 0) ? (((double)*(num + numSize/2) + (double)*(num+numSize/2 -1))/2) :(*(num+(numSize - 1)/2)));
        }
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
        //two way to get the number.
        if (nums1Size == 1 &&  nums2Size == 1)
        {
                printf("--%d--%d--\n", *nums1, *nums2);
              return ((double)(*nums1) + (double)(*nums2))/2;
        }

        if(nums1Size == 0)
              return findMedian(nums2, nums2Size);

        if(nums2Size == 0)
              return findMedian(nums1, nums1Size);

        if (*(nums1 + nums1Size -1) > *(nums2 +nums2Size -1))
              nums1Size --;
        else
              nums2Size --;

        if (*nums1 <= *nums2)
        {
                nums1 ++;
                nums1Size --;
        }
        else
        {
                nums2 ++;
                nums2Size --;
        }

        return findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
}

void main(void)
{
        int num1[2] = {1, 2};//, 3, 4, 6, 8, 9};
        int size1 = 2;
        int num2[2] = {3, 4};//, 7, 9, 10, 11};
        int size2 = 2;
        double a = findMedianSortedArrays(NULL, 0, num2, size2);
        printf("middle %2f \n", a);
}
