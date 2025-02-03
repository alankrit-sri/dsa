class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>>maxHeap;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>minHeap;

        long long maxSum = INT_MIN;
        long long score = 0;
        long long sum = 0;

        for(int i = 0; i < nums1.size(); ++i)
            maxHeap.push({nums1[i], i});

        while(!maxHeap.empty() && k > 0)
        {
            pair<int, int> maxValuePair = maxHeap.top();
            sum += maxValuePair.first;
            minHeap.push({nums2[maxValuePair.second], maxValuePair.second});
            maxHeap.pop();
            k--;
        }

        int minElement = minHeap.top().first;
        score = sum * minElement;
        maxSum = max(maxSum, score);

        while(!maxHeap.empty())
        {
            pair<int, int> minTop = minHeap.top();
            sum -= nums1[minTop.second];
            minHeap.pop();

            pair<int, int> maxTop = maxHeap.top();
            sum += maxTop.first;

            minHeap.push({nums2[maxTop.second], maxTop.second});
            maxHeap.pop();

            minElement = minHeap.top().first;

            score = sum * minElement;
            maxSum = max(maxSum, score);
        }
        return maxSum;
    }
};
