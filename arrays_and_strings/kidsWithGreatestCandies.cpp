class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> greatestExtraCandies;
        int size = candies.size();
        int maxCandies = candies[0];

        for(int i = 1; i < size; ++i)
            if(candies[i] > maxCandies) maxCandies = candies[i];
        
        for(int i = 0; i < size; ++i)
            (candies[i] + extraCandies >= maxCandies) ? greatestExtraCandies.push_back(true) : greatestExtraCandies.push_back(false);
    
        return greatestExtraCandies;
    }
};
