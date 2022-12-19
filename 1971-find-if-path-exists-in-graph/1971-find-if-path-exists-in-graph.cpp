class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source==destination )return true;
        vector<vector<int>> adjc(n+1);
        for (auto i :edges)
        {
            adjc[i[0]].push_back(i[1]);
            adjc[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(n+1);
        int flag=0;
        dfs(source, visited,adjc, destination, flag);
        return flag;
    }
    
    void dfs(int n, vector<int> &visited, vector<vector<int>> &adjc,int &target, int &flag){
        for (int i: adjc[n]){
            visited[n]=1;
            if (i==target) flag=1;
            else if (visited[i]==0)
                dfs(i, visited,adjc, target, flag);
            
        }
    }
};