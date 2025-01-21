class Solution {
public:
        int equalPairs(vector<vector<int>>& grid) {
        int pair_count = 0;
        vector<vector<int>> col_grid;
        col_grid.resize(grid[0].size());

        for(int i = 0; i < grid[0].size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                col_grid[i].push_back(grid[j][i]);

        for(int i = 0; i < grid[0].size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i] == col_grid[j])
                   ++pair_count; 

        return pair_count;
    }
};
