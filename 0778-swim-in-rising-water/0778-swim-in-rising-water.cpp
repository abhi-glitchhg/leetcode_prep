class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(),0));
        unordered_map<int, pair<int,int>> val_to_cordinates;
        for (int i=0;i<grid.size();i++)
            for (int j=0; j<grid[0].size();j++)
                val_to_cordinates[grid[i][j]] = {i,j};
        
        int global_t = 0;
        
        int n= grid.size();
        if (grid[n-1][n-1]==n*n -1) return n*n -1;
        priority_queue<int, vector<int>, greater<int> > pq;
        int max_occured=grid[0][0];
        int val=grid[0][0];
        int i, j; i=0; j=0;
        while (val!=grid[n-1][n-1]){
            dfs(i,j,grid, visited,pq,n);
            val = pq.top();
            pq.pop();
            pair<int,int> gg = val_to_cordinates[val];
            i = gg.first; j = gg.second;
            visited[i][j]=1;
            max_occured = max(max_occured, val);
            
            
        }
        return max_occured;
        
        
    }
    
    
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &visited, priority_queue<int, vector<int>, greater<int> > &pq, int &n){
        int up,down,left,right;
        up=n*n+1; left=n*n+1; right=n*n +1; down=n*n+1;
        
        
        if (i-1>=0) if (visited[i-1][j]==0) up=grid[i-1][j];
        if (j-1>=0) if (visited[i][j-1]==0) left = grid[i][j-1];
        if (i+1<n) if (visited[i+1][j]==0) down = grid[i+1][j];
        if (j+1<n) if (visited[i][j+1]==0) right = grid[i][j+1];
        
        pq.push(left);pq.push(right);pq.push(up);pq.push(down);
        
        
            
        
    }
    
   // void dfs(vector<vector<int>> &grid, vector<vector<int>> )
};