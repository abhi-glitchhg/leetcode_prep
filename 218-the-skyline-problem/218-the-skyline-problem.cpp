class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& build) {
        priority_queue<pair<int,int>> q;
        int i = 1;
        int curr = build[0][2];
        int start = build[0][0];
        int end = build[0][1];
        vector<vector<int>> ans;
        while(i<build.size()){
            if (end<build[i][0]){
                ans.push_back({start,curr});
                while(!q.empty() && q.top().second<=end){
                    q.pop();
                }
                if (!q.empty()){
                    start = end;
                    curr = q.top().first;
                    end = q.top().second;
                    q.pop();
                }
                else{
                    ans.push_back({end,0});
                    start = build[i][0];
                    end = build[i][1];
                    curr = build[i][2];
                    i++;
                }
            }
            else {
                if (build[i][2]==curr){
                    end = max(end,build[i][1]);
                }
                else if(build[i][2]>curr){
                    if (start!=build[i][0])
                    ans.push_back({start,curr});
                    q.push({curr,end});
                    start = build[i][0];
                    curr = build[i][2];
                    end = build[i][1];
                }
                else{
                    q.push({build[i][2],build[i][1]});
                }
                i++;
            }
        }
        while(!q.empty()){
            while(!q.empty() && q.top().second<=end){
                q.pop();
            }
            if (!q.empty()){
                    ans.push_back({start,curr});
                    start = end;
                    curr = q.top().first;
                    end = q.top().second;
                    q.pop();
            }
        }
        ans.push_back({start,curr});
        ans.push_back({end,0});
        return ans;
    }
};