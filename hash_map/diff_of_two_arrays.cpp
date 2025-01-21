class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answers;
        vector<int>::iterator itr;
        unordered_set<int> S1, S2;
        
        answers.resize(2);

        for(itr = nums1.begin(); itr != nums1.end(); ++itr)
            S1.insert(*itr);
        
        for(itr = nums2.begin(); itr != nums2.end(); ++itr)
            S2.insert(*itr);

        for(auto itr : S1)
        {
            if(S2.find(itr) == S2.end())
                answers[0].push_back(itr);  
        }

        for(auto itr : S2)
        {
            if(S1.find(itr) == S1.end())
                answers[1].push_back(itr);
        }    
        return answers;
    }
};
