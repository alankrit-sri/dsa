class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited (rooms.size(), false);
        stack<int> S;
        int roomVisitedCount = 0;
        S.push(0);
        visited[0] = true;

        while(!S.empty())
        {
            int room = S.top();
            S.pop();

            if(room > 0 && visited[room] || room == 0)
            {
                for(int j = 0; j < rooms[room].size(); ++j)
                {
                    if(!visited[rooms[room][j]])
                    {
                        S.push(rooms[room][j]);
                        visited[rooms[room][j]] = true;
                        roomVisitedCount++;
                    }
                }
            }
        }
        return (roomVisitedCount + 1 == rooms.size()) ? true : false;
    }
};
