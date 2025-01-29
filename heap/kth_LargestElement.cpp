class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int kth_largest;
        for(int i = 0; i < nums.size(); ++i)
            pq.push(nums[i]);
        while(!pq.empty())
        {
            kth_largest = pq.top();
            pq.pop();
            --k;
            if(!k)
                break;
        }
        return kth_largest;
    }
};
