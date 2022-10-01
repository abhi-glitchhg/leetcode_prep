class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adc) {
        //vector<int> visited(adc.size(), 0);
        vector<vector<int>> ans;
        vector<int>path;
        path.push_back(0);
        //unordered_map<int,bool>
        dfs(0,adc,ans,path);
        return ans;
    }
    
    void dfs(int node, vector<vector<int>>&adjc, vector<vector<int>> &ans, vector<int> &path){
        
        //dfs in graph; add node while doing dfs on its children; when done remove from path;
        
        for (auto i: adjc[node]){
                path.push_back(i);
                if (i==adjc.size()-1) ans.push_back(path);
                dfs(i, adjc,ans,path);
                path.pop_back();
        }
}
};
