class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n));
        int upper_row=0;int left_column=0;
        int lower_row=n-1; int right_column = n-1;
        int to_be_added = 1;
        while (upper_row<=lower_row && left_column<=right_column){
            for (int i=left_column;i<=right_column;i++){
                ans[upper_row][i]= to_be_added;
                to_be_added++;

            }
            upper_row+=1;
            for (int i=upper_row;i<=lower_row;i++){
                ans[i][right_column]= to_be_added;
                to_be_added++;
            }
            right_column--;
            for (int i=right_column;i>=left_column;i--){
                ans[lower_row][i]=to_be_added;
                to_be_added++;
                
            }

            lower_row--;
            for (int i= lower_row;i>=upper_row;i--){
                ans[i][left_column] = to_be_added;
                to_be_added++;
            }

            left_column++;
        }
        return ans;
    }
};