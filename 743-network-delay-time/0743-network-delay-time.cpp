class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     vector<int> visited(n+1, 10000000);
        
     visited[k]=0;
     vector<vector<pair<int,int>>> adjc(n+1);
        
        for (auto i: times)
            adjc[i[0]].push_back({i[1],i[2]});
    
    queue<pair<int,int>> q;
        q.push({k,0});
      while (!q.empty()){
          pair<int,int> node1 = q.front();
          q.pop();
          int node = node1.first;
          
          int curr_dist = node1.second;
          for (auto i: adjc[node]){
              if (visited[i.first ] > curr_dist+ i.second){
                  q.push({ i.first, curr_dist+ i.second});
                  visited[i.first] = curr_dist+ i.second;
              }
          }
          
          
      }
        int ans=0;
        for (int i=1;i<visited.size();i++)
        { 
            if (visited[i]==10000000) return -1;
        
             ans = max(ans,visited[i]);
        }
        return ans;
    }
};