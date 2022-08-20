class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res;
        
        res.push_back(0);
        res.push_back(1);
        
        for (int i=0; i<n-1;i++){
            for (int j=0;j<pow(2,i+1);j++){
                res.push_back( (int)(pow(2,i+1)) | res[pow(2,i+1)-1 -j] );
            }
        }      
        return res;
    }
};