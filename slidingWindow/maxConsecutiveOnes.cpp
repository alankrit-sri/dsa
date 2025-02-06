class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int currentCount = 0, maxCount = 0, zeroPos = 0, nextZeroPlace = 0;
        vector<int>zeroInd(nums.size());
        for(int ind = 0; ind < nums.size(); ++ind)
        {
            if(nums[ind]) ++currentCount;
            else
            {
                zeroInd[zeroPos++] = ind;
                if(k)
                {
                    --k;
                    ++currentCount;
                }
                else currentCount = ind - zeroInd[nextZeroPlace++];
            }
            if(currentCount > maxCount) 
                maxCount = currentCount;
        }
        return maxCount;
    }
};
