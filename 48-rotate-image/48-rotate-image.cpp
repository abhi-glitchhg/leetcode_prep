class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0;i<n-1;i++){
            for (int j =0;j<n-i-1;j++){
                cout << i <<" "<< j << endl;
                int temp;
                temp = matrix[i][j];
                matrix[i][j] =matrix[n-1-j][n-1-i] ;
                matrix[n-1-j][n-1-i] = temp;
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};