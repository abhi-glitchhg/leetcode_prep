class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
     
        int res; int cur;
        cur=0;res=0;
        
        for (auto i : values){
            // prev best candidate was kept tracked; and then update it acc;
            
            res = max(cur+i, res);
            cur = max(cur, i) -1;
        }
        return res;
    }
};