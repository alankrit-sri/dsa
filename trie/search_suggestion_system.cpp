class TrieNode
{
public:
unordered_map<char, TrieNode*>children;
bool isEndOfWord;

TrieNode() : isEndOfWord(false){}
};

class Trie
{
TrieNode *root;
public:
Trie()
{
    root = new TrieNode();
}
void insert(string word)
{
    TrieNode* node = root;
    for(auto ch : word)
    {
        if(node->children.find(ch) == node->children.end())
        {
            node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool search(string word)
{
    TrieNode* node = root;
    for(auto ch : word)
    {
        if(node->children.find(ch) == node->children.end())
            return false;
        node = node->children[ch];
    }
    return node->isEndOfWord;
}

/*

*/
bool startsWith(string prefix)
{
    TrieNode* node = root;
    for(auto ch : prefix)
    {
        if(node->children.find(ch) == node->children.end())
            return false;
        node = node->children[ch];
    }
    return true;
}
vector<string> startsWith(string prefix, vector<string> &products)
{
    vector<string> words;
    if(startsWith(prefix))
    {
        for(auto element : products)
        {
            if(element.compare(0, prefix.length(), prefix) == 0 && words.size() < 3)
                words.push_back(element);
        }
    }
    return words;
}

};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>res;
        Trie trie;
        for(int i = 0; i < products.size(); ++i){
            if(!trie.search(products[i]))
                trie.insert(products[i]);
        }

        sort(products.begin(), products.end());

        for(int i = 0; i < searchWord.length(); ++i)
            res.push_back(trie.startsWith(searchWord.substr(0, i + 1), products));
            
        return res;
    }
};
