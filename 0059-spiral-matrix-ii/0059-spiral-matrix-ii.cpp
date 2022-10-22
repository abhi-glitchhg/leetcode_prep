class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> visited(n,vector<int>(n)); //get rid of this eventually
        int upper_row=0;int left_column=0;
        int lower_row=n-1; int right_column = n-1;
        int to_be_added = 1;
        while (upper_row<=lower_row && left_column<=right_column){
            for (int i=left_column;i<=right_column;i++){
                ans[upper_row][i]= to_be_added;
                to_be_added++;
                  //              cout<<upper_row<<" "<<i<<" "<<to_be_added-1 <<"\n";

            }
            upper_row+=1;
            //if ()
                      //  cout<<" \n";

//            if (to_be_added>=n*n) break;

            for (int i=upper_row;i<=lower_row;i++){
                ans[i][right_column]= to_be_added;
                to_be_added++;
                //cout<< i<< " "<< right_column<< " "<<to_be_added-1 <<"\n";
            }
          //  cout<<" \n";
            //if (to_be_added>=n*n) break;
            right_column--;
            for (int i=right_column;i>=left_column;i--){
                ans[lower_row][i]=to_be_added;
                to_be_added++;
                //cout<< lower_row<< " " << i<<" " <<to_be_added-1 <<" \n";
            }
          //              cout<<" \n";

            lower_row--;
            //if (to_be_added>=n*n) break;
            for (int i= lower_row;i>=upper_row;i--){
                ans[i][left_column] = to_be_added;
                to_be_added++;
                //cout<< i<< " "<< left_column<< " "<<to_be_added-1 <<"\n";
            }
            //            cout<<" \n";

            left_column++;
            //if (to_be_added>=n*n) break;
        }
        return ans;
    }
};