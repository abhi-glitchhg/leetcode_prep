class Solution {
public:
    vector<int> grayCode(int n) {
        
        vector<int> res;
        
        res.push_back(0);
        res.push_back(1);
        
        for (int i=0; i<n-1;i++){
            for (int j=0;j<pow(2,i+1);j++){
                //cout << pow(2,i+1)<<" is the power of 2 (part one for calculating f) \n";
                //cout << res[pow(2,i+1)-1-j]<<" part two for calculating f \n" ;
                //int f = (int)(pow(2,i+1)) | res[pow(2,i+1)-1 -j]; //taking bitwise or 
                //cout << f << " is the value that we are appending\n";
                res.push_back( (int)(pow(2,i+1)) | res[pow(2,i+1)-1 -j] );
            }
        }      
        return res;
    }
};