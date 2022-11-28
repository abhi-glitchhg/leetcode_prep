class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       map<int,int>  winner;
       map<int,int> loser;
       for (auto it: matches)
       {
           winner[it[0]]++;
           loser[it[1] ]++;
           
       }
        
        vector<vector<int>> ans(2);
        for (auto it:winner){
            if (loser[it.first]==0)
                ans[0].push_back(it.first);
        }
        
        for (auto it:loser)
            if (it.second==1){
                ans[1].push_back(it.first);
            }
        //sort(ans[0].begin(),ans[0].end());
        //sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};