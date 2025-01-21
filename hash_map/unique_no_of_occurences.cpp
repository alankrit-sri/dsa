class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int arr_size = arr.size();
        unordered_map<int,int> umap;
        unordered_set<int> S;
        for(int i = 0; i < arr_size; ++i)
            ++umap[arr[i]];
        for(auto itr: umap)
            S.insert(itr.second);
        if(umap.size() == S.size())
            return true;
        return false;
    }
};
