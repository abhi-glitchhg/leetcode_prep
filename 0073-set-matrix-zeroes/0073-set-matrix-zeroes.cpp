class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector< pair<int,int>> a;
        
        for (int i=0; i< matrix.size(); i++)
            for (int j=0;j<matrix[0].size();j++)
                if (matrix[i][j]==0) a.push_back({i,j});
        
        for (auto i: a){
            matrix[i.first] = vector<int>(matrix[0].size(), 0); 
        }
        
        for (auto j: a)
            for (int i=0;i<matrix.size();i++)
                matrix[i][j.second] =0;
        return ;
    }
};