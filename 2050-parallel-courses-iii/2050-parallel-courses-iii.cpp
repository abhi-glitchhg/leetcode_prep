class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        vector<vector<int>> adjc(n);
        vector<int> indegree(n,0);
        vector<int> dist(n,0);
        
        for (auto i: relations)
        {
            indegree[i[1]-1]++;
            adjc[i[0]-1].push_back(i[1]-1);
        }
        queue<int> q;
        for (int i=0;i<n;i++){
            if (indegree[i]==0) q.push(i);
        }
        while (!q.empty()){
            int size_ = q.size(); 
            for (int i_=0;i_<size_;i_++){
                int i = q.front();q.pop();
                if (indegree[i]==0)
                {
                    dist[i] += time[i];
                    for (auto j: adjc[i]){
                        indegree[j]--;
                        if  (indegree[j]==0) q.push(j);
                        dist[j] = max(dist[j], dist[i]);
                    }
                }
            }
        }
        int ans=0;
        for (auto i:dist)
            ans = max(i,ans);
        return ans;
        
    }
};