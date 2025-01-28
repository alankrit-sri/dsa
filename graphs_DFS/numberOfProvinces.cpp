class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int matrix_len = isConnected.size();

        vector<vector<int>>connectedCities;
        vector<bool> visited(matrix_len + 1, false);
        stack<int> S;
        int provinces = 0;

        connectedCities.resize(matrix_len + 1);
    
        for(int row = 1; row <= matrix_len; ++row)
        {
            for(int col = 1; col <= matrix_len; ++ col)
            {
                if(isConnected[row - 1][col - 1] && row != col)
                {
                    if(find(connectedCities[row].begin(), connectedCities[row].end(), col) == connectedCities[row].end())
                    connectedCities[row].push_back(col);

                    if(find(connectedCities[col].begin(), connectedCities[col].end(), row) == connectedCities[col].end())
                    connectedCities[col].push_back(row);
                }
            }
        }

        for(int city = 1; city <= matrix_len; ++city)
        {
            if(!visited[city])
            {
                ++provinces;
                S.push(city);
                while(!S.empty())
                {
                    int cityName = S.top();
                    S.pop();

                    for(int i = 0; i < connectedCities[cityName].size(); ++i)
                    {
                        if(!visited[connectedCities[cityName][i]])
                        {
                            visited[connectedCities[cityName][i]] = true;
                            S.push(connectedCities[cityName][i]);
                        }
                    }
                }
            }
        }

        return provinces;
    }
};
