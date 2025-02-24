class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged_string;
        int number_of_equal_characters = min(word1.length(), word2.length());

        for(int i = 0; i < number_of_equal_characters; ++i)
        {
            merged_string += word1[i];
            merged_string += word2[i];           
        }
        if(number_of_equal_characters < word1.length())
            merged_string.append(word1, number_of_equal_characters, word1.length() -        number_of_equal_characters);

        if(number_of_equal_characters < word2.length())
            merged_string.append(word2, number_of_equal_characters, word2.length() -        number_of_equal_characters);

        return merged_string;
    }
};
