class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vowelCount = 0, maxVowelCount = 0;
        for(int i = 0; i < k; ++i)
            if(isVowel(s[i])) ++vowelCount;

        maxVowelCount = vowelCount;

        for(int i = 1; i <= (s.length() - k) ; ++i)
        {
            if(isVowel(s[i + k - 1]))
                ++vowelCount;
            if(isVowel(s[i - 1]))
                --vowelCount;
            maxVowelCount = max(maxVowelCount, vowelCount);
        }
        return maxVowelCount;
    }
};
