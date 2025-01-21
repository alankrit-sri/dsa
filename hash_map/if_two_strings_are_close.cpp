class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int word1_len = word1.length(), word2_len = word2.length();
        if(word1_len != word2_len)
            return false;

        vector<int> alphabet_list1(26, 0), alphabet_list2(26, 0);
        unordered_set<char> word1_set, word2_set;
        int ind_count = word1_len < word2_len ? word1_len : word2_len;

        for(int i = 0; i < ind_count; ++i)
            {
                word1_set.insert(word1[i]);
                word2_set.insert(word2[i]);
                ++alphabet_list1[word1[i] - 'a'];
                ++alphabet_list2[word2[i] - 'a'];
            }

        if(ind_count < word1.length())
            {
                for(int i = ind_count; i < word1_len; ++i){
                    word1_set.insert(word1[i]);
                    ++alphabet_list1[word1[i] - 'a'];}
            }

        if(ind_count < word2.length())
            {
                for(int i = ind_count; i < word2_len; ++i){
                    word2_set.insert(word2[i]);
                    ++alphabet_list2[word2[i] - 'a'];
                }
            }
        if(word1_set != word2_set)
            return false;

        /*
        	1	Check if both words are of same length, if not return False
	        2	Check if both words have same alphabets (by comparing set(word1) and set(word2)
	        3	Make two lists having count of all alphabets one for word1 and one for word2, sort the lists, check if the lists are equal, if yes return True, else return False
        */
        sort(alphabet_list1.begin(),alphabet_list1.end());
        sort(alphabet_list2.begin(),alphabet_list2.end());

        for(int i = 0 ; i < 26; ++i)
        {
            if(alphabet_list1[i] != alphabet_list2[i])
                return false;
        }
        return true;
    }
};
