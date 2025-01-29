class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highestAlt, prevSum = gain[0];
        highestAlt = max(0, gain[0]);
        for(int i = 1; i < gain.size(); ++i)
        {
            prevSum += gain[i]; 
            if(highestAlt < prevSum)
                highestAlt = prevSum;
        }
        return highestAlt;
    }
};
