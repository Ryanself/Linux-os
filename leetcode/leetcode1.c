#include <stdio.h>

/**
 * leetcode No.1
 *  * Note: The returned array must be malloced, assume caller calls free().
 * */
static int result[2] = {0};
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
        int i, j;
        i = j = 0;
        for(i = 0;i < numsSize -1; i++)
              for(j = i + 1; j < numsSize; j++){
                      if( target != (nums[i] + nums[j]))
                            continue;
                      result[0] = i;
                      result[1] = j;
                      return result;
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
 * */
