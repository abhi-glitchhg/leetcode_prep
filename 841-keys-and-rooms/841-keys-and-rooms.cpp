class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> isVisited(rooms.size());
        dfs(0, isVisited, rooms);
        for (auto i: isVisited)
            if (i==0) return false;
        return true;
    }
    
    void dfs(int n, vector<int> &isvisited, vector<vector<int>>& rooms){
        isvisited[n]=1;
        
        for (auto i: rooms[n]){
            if (isvisited[i]==0)
                dfs(i,isvisited,rooms);
        }
    }
};