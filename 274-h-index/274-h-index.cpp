class Solution {
public:
    int hIndex(vector<int>& c) {
        if(c.empty()) return 0;
        int ppr=0;
        int n=c.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            if(c[i]>=n)
                v[n]++;
            else{
                v[c[i]]++;
                
            }
        }
        for(int i=n;i>=0;i--){
            ppr+=v[i];
            if(ppr>=i)
                return i;
        }
        return 0;
    }
};