/*
Given an array of integers, return indices of the two numbers such that they
add up to a specific target.

You may assume that each input would have exactly one solution, and you may
not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, *result = NULL, sum_found = 0;

    for ( i = 0; i < numsSize-1; i++ ) {
        for ( j = i+1; j < numsSize; i++ ) {
           if( nums[i] + nums[j] == target ) {
               result = (int*)malloc(2*sizeof(int));
               result[i] = i;
               result[j] = j;
               sum_found = 1;
               break;
           }
           if (sum_found) break;
        }
    }
    return result;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9, *result_arr = NULL;

    result_arr = twoSum(&nums, sizeof(nums), target);
    if (result_arr) {
        printf("Resultant array indices which add upto %d are (%d,%d)\n",
            target, result_arr[0], result_arr[1]);
        free(result_arr);
    } else {
        printf("There are no indices which add upto %d\n", target);
    }
}
