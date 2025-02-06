class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSubarrSum = 0, maxSubarrAns = 0;

        for(int i = 0; i < k; ++i) maxSubarrSum += nums[i];
        maxSubarrAns = maxSubarrSum;
    
        for(int i = 1; i <= nums.size() - k; ++i)
            {
                maxSubarrSum = maxSubarrSum - nums[i - 1] + nums[k + i - 1];
                maxSubarrAns = max(maxSubarrSum, maxSubarrAns);
            }
        return((double)maxSubarrAns / k);
    }
};
