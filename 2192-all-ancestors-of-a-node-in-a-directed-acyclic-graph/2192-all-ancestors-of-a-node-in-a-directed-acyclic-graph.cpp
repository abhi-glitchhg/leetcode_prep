class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        vector<vector<int>> adjc(n);
        //vector<vector<int>> rev_adjc(n);
        for (auto i: edges){
         
            adjc[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
    
        vector<int> toposort;
        queue<int> q;
        for (int i=0;i<n;i++)
            if (indegree[i]==0)
                q.push(i);
        
        while (!q.empty()){
            int top = q.front();
            q.pop();
            toposort.push_back(top);
            for (auto i: adjc[top])
            {        indegree[i]--;
            if (indegree[i]==0) q.push(i);
            }
        }
        
        vector<vector<int>> ans(n);
        for (auto i: toposort){
            for (auto g: adjc[i]){ // i->0 g-> 3;  
                for (auto p: ans[i])
                    if (find(ans[g].begin(),ans[g].end(),p)== ans[g].end())
                        ans[g].push_back(p);
                ans[g].push_back(i);                
                }
        }
        
        for (int i=0;i<n;i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};