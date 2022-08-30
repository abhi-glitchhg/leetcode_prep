class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        int n = mat.size();
        for (int i=0;i<n-1;i++){
            for (int j =0;j<n-i-1;j++){
                //cout << i <<" "<< j << endl;   
                int temp;
                temp = mat[i][j];
                mat[i][j] =mat[n-1-j][n-1-i] ;
                mat[n-1-j][n-1-i] = temp;
            }
        }
        reverse(mat.begin(), mat.end());
        if (mat == target ) return true;
        else  { 
        for (int i=0;i<n-1;i++){
            for (int j =0;j<n-i-1;j++){
                //cout << i <<" "<< j << endl;   
                int temp;
                temp = mat[i][j];
                mat[i][j] =mat[n-1-j][n-1-i] ;
                mat[n-1-j][n-1-i] = temp;
            }
        }
        reverse(mat.begin(), mat.end());}
        if (mat == target ) return true;
           else  { 
        for (int i=0;i<n-1;i++){
            for (int j =0;j<n-i-1;j++){
                //cout << i <<" "<< j << endl;   
                int temp;
                temp = mat[i][j];
                mat[i][j] =mat[n-1-j][n-1-i] ;
                mat[n-1-j][n-1-i] = temp;
            }
        }
        reverse(mat.begin(), mat.end());}
        return mat == target;
               
        
        
        
    }
};