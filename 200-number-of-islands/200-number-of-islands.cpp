//similar to the https://leetcode.com/problems/flood-fill/ q. 
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
//         Based on connected components
//         run a loop throughout matrix and if we find 1(island) then we run dfs on it and
//         when dfs is over we increment ans by 1
//         
        for(int currentRow=0;currentRow<m;currentRow++)
        {
            for(int currentCol=0;currentCol<n;currentCol++)
            {
                if(grid[currentRow][currentCol]=='1')
                {
                    totalIslands(grid, currentRow, currentCol, m, n);
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void totalIslands(vector<vector<char>>& grid, int currentRow, int currentCol, int m, int n)
    {
//         base condition
        if(currentRow<0 || currentRow>=m || currentCol<0 || currentCol>=n || grid[currentRow][currentCol]=='0')
            return;
        
//         to mark a cell visited we change its value from '1' to '0'
        grid[currentRow][currentCol]='0';
        
//         we run dfs for 4 sides
        totalIslands(grid, currentRow+1,currentCol, m,n);
        totalIslands(grid, currentRow-1,currentCol, m,n);
        totalIslands(grid, currentRow,currentCol+1, m,n);
        totalIslands(grid, currentRow,currentCol-1, m,n);
        
        return;
    }
    
};