class Solution {
public:

    string reverseWords(string s) {
        string out;
        int endPos;
        bool strStarted = false;
        for(int i = s.size() - 1; i >= 0; --i)
        {
            if(s[i] != ' ' && !strStarted) 
            {
                endPos = i;
                strStarted = true;
            }
            else if(strStarted && s[i] == ' ')
            {
                if(!out.empty()) out += ' ';
                out += s.substr(i + 1, endPos - i);
                strStarted = false;
            }
        }
        if(strStarted) {
            if(!out.empty()) out += ' ';
            out += s.substr(0, endPos + 1);
        }
        return out;
    }
};
