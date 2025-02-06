class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>zeroArr(nums.size());
        int zeroCount = 0, currentCount = 0, maxCount = 0;
        for(int ind = 0; ind < nums.size(); ind++)
        {
            if(nums[ind]) ++currentCount;
            else
            {
                zeroArr[zeroCount++] = ind;
                if(zeroCount > 1)
                    currentCount = zeroArr[zeroCount - 1] - zeroArr[zeroCount - 2] - 1;
                    // Taking difference between 2 consecutive 0s and removing place for the first 0 as only one 0 is allowed between the numbers
            }
            if(currentCount > maxCount)
                maxCount = currentCount;
        }
        return !zeroCount ? maxCount - 1 : maxCount;
    }
};
