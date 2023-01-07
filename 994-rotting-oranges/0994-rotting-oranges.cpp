class Solution {
public:
    vector<int> II = {0,1,0,-1};
    vector<int> JJ = {-1,0,1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair<int, int> > q;
        
        
        for (int i=0; i< grid.size(); i++)
            for (int j=0; j< grid[0].size(); j++)
                if (grid[i][j] ==2 ) q.push({i,j});
        
        int ans= 0;
        
        while (!q.empty()) {
            int g = q.size();
            //cout<< g << " \n";
            for (int _ =0; _ < g; _++){
                
                int i= q.front().first;
                int j= q.front().second;
                
                q.pop();
                //cout<< q.size() <<" ";
                for (int kk=0;kk<4;kk++)
                {
                    int local_i = i + II[kk];
                
                    int local_j = j + JJ[kk];
                    
                    if (local_i<0 || local_j < 0 || local_i >= grid.size() || local_j >=grid[0].size())
                        continue;
                    if (grid[local_i][local_j]==1){ 
                        q.push({local_i,local_j});
                        grid[local_i][local_j]=2;
                    }
                }
                
            }
            ans++;
            
        }
        
        for (int i=0; i< grid.size(); i++)
            for (int j=0; j< grid[0].size(); j++)
                if (grid[i][j] ==1)
                    return -1;
        if (ans==0) return 0;
        return ans-1;
        
    }
};