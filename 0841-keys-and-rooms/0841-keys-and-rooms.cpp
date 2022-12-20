class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(),-1);
        dfs(rooms, visited, 0);
       // for (auto i: visited)
          //  cout<<i<<" ";
        for (auto i: visited)
            if (i!=1) return false;
        return true;
    }
    
    
    void dfs(vector<vector<int>> &rooms, vector<int>& visited, int curr){
        visited[curr] = 1;
        for (auto i: rooms[curr])
        {
            if (visited[i]!=1) dfs(rooms, visited, i);
        }
    }
};