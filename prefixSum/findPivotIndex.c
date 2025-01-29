int pivotIndex(int* nums, int numsSize) {
    int numsSum = 0, leftSum = 0, rightSum;
    for(int i = 0; i < numsSize; ++i)
        numsSum += nums[i];
    rightSum = numsSum;
    for(int i = 0; i < numsSize; ++i)
    {
        if(leftSum == rightSum - nums[i])
            return i;
        leftSum += nums[i];
        rightSum -= nums[i];
    }
    return -1;
}
