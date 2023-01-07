class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> memoise(matrix.size(), vector<int>(matrix[0].size(),INT_MAX));
        
        for (int ll=0; ll<matrix[0].size();ll++)
            memoise[matrix.size()-1][ll] = matrix[matrix.size()-1][ll];
        
        for (int ll=0; ll<matrix[0].size();ll++)
            int smile = dp(0,ll,memoise,matrix);
        
        int ans=INT_MAX;
        for (auto i:memoise[0])
            ans = min(ans, i);
    return ans;
    }
    
    int dp(int i, int j, vector<vector<int>> &memoise, vector<vector<int>> &matrix){
        
        if (i<0 || i>=matrix.size()|| j<0 || j>=matrix[0].size()) return INT_MAX;
        if (memoise[i][j]!=INT_MAX) return memoise[i][j];
        return memoise[i][j]= matrix[i][j] + min(min(dp(i+1,j+1,memoise, matrix), dp(i+1,j-1,memoise,matrix)), dp(i+1, j, memoise, matrix));
        
        
        
    
    }
    
    
    
};