class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
        return true;
        return false;
    }
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(!isVowel(s[left])) ++left;
            else if(!isVowel(s[right])) --right;
            else
            {
                char temp = s[left];
                s[left++] = s[right];
                s[right--] = temp;
            }
        }
        return s;
    }
};
