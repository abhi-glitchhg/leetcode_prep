class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
        vector<int> ans;
        int s_col,  s_row=0;
        int e_row = matrix.size();
        int e_col = matrix[0].size();
        
        if (matrix.size() ==1) return matrix[0];
        else if (matrix.size()==2) {
            for (auto i : matrix[0]) ans.push_back(i);
            vector<int> b = matrix[1];
            reverse(b.begin(),b.end());
            for (auto i : b) ans.push_back(i);
            return ans;
        }
        
        while (s_col<=e_col && s_row <= e_row){
            
            vector<int> srow = matrix[s_row];
            for (int i=s_col; i < e_col;i++)  ans.push_back(srow[i]); //cout<< srow[i]<< "; ";} 
            s_row++;
            if (s_row>= e_row || s_col >= e_col) break;

            for (int i=s_row; i <e_row; i++)  ans.push_back(matrix[i][e_col-1]); // cout<< matrix[i][e_col-1] <<"coz ";} 
            e_col --;
            //cout << s_row << " "<< e_row<< " " << s_col << " " << e_col <<endl;
            
            if (s_row>= e_row || s_col >= e_col) break;
            
            vector<int> erow = matrix[e_row-1];
            for (int i=e_col-1; i>s_col-1 ;i--) ans.push_back(erow[i]);  //cout<< erow[i]<< " "<<"erorw";} 
            e_row--;
            if (s_row>= e_row || s_col >= e_col) break;

            for (int i=e_row-1; i>s_row -1; i--) ans.push_back(matrix[i][s_col]);// cout<< matrix[i][s_col] << " ";} 
            s_col++;
        }
        return ans;
        
        
        
    }
};