class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bitCountArray(n + 1, 0);

        for(int i = 1; i <= n; ++i)
            bitCountArray[i] = bitCountArray[i/2] + (i & 1);
        
        return bitCountArray;
    }
};
