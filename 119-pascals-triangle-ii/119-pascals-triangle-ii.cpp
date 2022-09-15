class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int i=0;
        int gg = rowIndex;
        // n-i / i +1 formula for nc(i+1)/nci
        
        if (rowIndex==0)
            ans.push_back(1);
        else {
            if (rowIndex%2 == 1) gg++;
            ans.push_back(1);
            long int jj = 1;
            for (i; i< (gg/2) ; i++){
                
                jj = jj * (rowIndex-i)/(i+1);
                ans.push_back((int)jj);
                ///cout<<jj<< " ";
            }
            cout<<i;
            if (rowIndex%2==1) i--;
            i--;
            for (;i>-1;i--){
                ans.push_back(ans[i]);
            }
        }
        return ans;
        
    }
};