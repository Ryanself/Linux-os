#include <stdio.h>

/**
 *  * Note: The returned array must be malloced, assume caller calls free().
 *   */
static int a[2010][3] = {0}; //we shal use list here.
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int j, k, i, l;
	if(a[0][2] == 0)
	{
		l = 0;
		for(j = 0;j < numsSize; j++)
			for(k = j; k < numsSize; k++){
				a[l][0] = j;
			        a[l][1] = k;
			        a[l][2] = nums[j]+nums[k];
				l++;
		        }
	}

	for(i = 0; a[i][2]!=0; i++){
		if(a[i][2] == target) {
			int b[2];
			*(returnSize++) = a[i][0];
			*(returnSize++) = a[i][1];
			return returnSize;
                 }
	}
	return NULL;
}

int main(){
	int nums[4] ={2, 7, 11, 15};
	int c[2] = {0};
	int *ret = twoSum(nums, 4, 9, c);
	if (ret)
	      printf("[%d, %d]\n", c[0], c[1]);
	else
	      printf("no this vlaue!");
	return 0;
}
/*
 * TODO: acturally we shall use hash table, but so long time not recover datastructure,
 * I have forgotten how to wirte with it.
 * this .c need to be update.
 * /
