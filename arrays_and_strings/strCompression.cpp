class Solution {
public:
    int compress(vector<char>& chars) {
        if(!chars.size()) return 0;
        char prevCh = chars[0];
        int prevChCount = 1, charInd = 0;;

        for(int i = 1; i < chars.size(); ++i)
        {
            if(chars[i] == prevCh) ++prevChCount;
            
            else
            {
                chars[charInd++] = prevCh;
                if(prevChCount > 1)
                {
                    for(int i = 0; i < to_string(prevChCount).length(); ++i)
                        chars[charInd++] = to_string(prevChCount)[i];
                }            
                prevCh = chars[i];
                prevChCount = 1;
            }
        }
        chars[charInd++] = prevCh;
        if(prevChCount > 1)
        {
            for(int i = 0; i < to_string(prevChCount).length(); ++i)
                chars[charInd++] = to_string(prevChCount)[i];
        }

        return charInd;
    }
};
