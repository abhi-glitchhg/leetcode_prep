class Solution {
public:
    int partitionString(string s) {
        map<char, int> aa;
        int ans=1;
        for (auto i: s){
            if (aa[i] ==1){ 
                ans++;
                aa.clear();} 
            aa[i]++;
            
        }
        return ans;
    }
};