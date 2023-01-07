class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        vector<vector<int>> adjc(quiet.size());
        
        for (auto i: richer)
            adjc[i[1]].push_back(i[0]);
        vector<int> ans(quiet.size(), -1);
        
        
        for (int i=0;i<quiet.size();i++){
            if (ans[i] !=-1) continue;
            int min_ = INT_MAX;
            
            ans[i] = dfs(i, min_, quiet,adjc ,ans);
            //ans.push_back(index);
        }
        
        return ans;
    }
    
    int dfs(int i , int &min_, vector<int>& quiet, vector<vector<int>> &adjc, vector<int> &ans){
        
        int index = i;
        if (ans[i] != -1) return ans[i];
        for (int ll: adjc[i])
        {
            int gg = dfs(ll, min_, quiet, adjc, ans);
            if (quiet[gg]<quiet[index]){
                index=gg;
                min_ = quiet[gg];
            }
        }
        
        if (min_ > quiet[i])
        {
            index = i;
            min_ = quiet[i];
        }
        
        return ans[i] = index;
        
    }
};