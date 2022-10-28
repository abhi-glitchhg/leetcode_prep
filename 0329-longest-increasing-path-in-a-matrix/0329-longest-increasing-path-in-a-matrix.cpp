class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int ans=0;
        vector<vector<int>> memoise(matrix.size(), vector<int>(matrix[0].size(),-1)) ;
        for (int x=0; x<matrix.size();x++){
            for (int y=0; y<matrix[0].size();y++){
                int temp = dp(-1, x,y,matrix, memoise);
                //memoise[x][y]=temp;
                ans= max(ans,temp);
            }
        }
         return ans;
    }
    
    
    int dp(int parent_val, int i, int j, vector<vector<int>> &grid, vector<vector<int>> &memoise){
        if (i<0 || i>=grid.size()||j<0 ||  j>=grid[0].size()) return 0;
        
        if (memoise[i][j]!=-1 && grid[i][j]>parent_val) return memoise[i][j];
        
        if (grid[i][j]>parent_val)
        { 
            //cout<< i <<j <<" ";
            return memoise[i][j] = 1+max(max(dp(grid[i][j], i-1, j, grid, memoise), dp(grid[i][j], i+1,j, grid, memoise)), max(dp(grid[i][j],i,j-1,grid, memoise),dp(grid[i][j],i,j+1,grid, memoise)));
         }
        return 0;
        
    }
    
    
    
};