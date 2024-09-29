/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *ptr = NULL;
    *returnSize = 2;
    ptr = (int *) malloc (2*sizeof(int));
    for (int i = 0; i<numsSize ;++i){
        for (int j =i+1;j<numsSize;++j){
            if (target == nums[i]+nums[j]){
                ptr[0] = i;
                ptr[1] = j;
                return ptr ;
            }
            
        }

    }
    *returnSize = 0;
    return NULL;
}