class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> adjc;
        vector<int> visited(n);
        long long ans = (long long)(n) * (n-1) /2;
        for (auto i: edges){
            adjc[i[0]].push_back(i[1]);
            adjc[i[1]].push_back(i[0]);
        }
        
        for (int i=0;i<n;i++){
            if (visited[i]==0)
            {
                int count=0;
                dfs(i, adjc, visited, count);
                ans-= ((long long)count) * (count-1)/2;
            }
            
        }
        return ans;
        


    }
    
    void dfs(int from, unordered_map<int, vector<int>> &adjc, vector<int> &visited, int &count){
        
        visited[from]=1;
        count++;
        for (auto i: adjc[from]){
            if (visited[i]==0)
                dfs(i, adjc, visited,count);
        }   
    }
};