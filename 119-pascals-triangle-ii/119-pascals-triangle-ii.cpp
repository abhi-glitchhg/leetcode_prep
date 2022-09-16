class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int i=0;
        ans.push_back(1);
        long int jj = 1;
        for (i; i< rowIndex ; i++){
            jj = jj * (rowIndex-i)/(i+1);
            ans.push_back((int)jj);
            }
        return ans;
        
    }
};