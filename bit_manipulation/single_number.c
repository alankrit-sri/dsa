int singleNumber(int* nums, int numsSize) {
        int singleOccurence = 0;
        for(int i = 0; i < numsSize; ++i)
            singleOccurence ^= nums[i];
        return singleOccurence; 
}
