class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
    vector<vector<int>> adjc(isConnected.size());
    vector<int> isvisited(isConnected.size());
    int n = isConnected[0].size();
    for (int i=0;i<n;i++) {for (int j=0;j<n;j++) if (isConnected[i][j]==1 && j!=i) adjc[i].push_back(j);}
    
    int ans=0;
    for (int i=0;i<isConnected.size();i++){
        if (isvisited[i]==0){
            dfs(i,isvisited,adjc);
            ans++;
        }
    }
    return ans;
    }
    
    // dfs but track the number of components;
    
    void dfs(int n, vector<int> &isvisited, vector<vector<int>>& adjc){
        if (isvisited[n]==1)
            return;
        isvisited[n]=1;
        for (auto i : adjc[n])
            dfs(i, isvisited, adjc);
    }
    
};