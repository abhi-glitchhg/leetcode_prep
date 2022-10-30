class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        priority_queue<pair<pair<int,int>,pair<int,int>>, vector<pair<pair<int,int>,pair<int,int>>>, greater<pair<pair<int,int>,pair<int,int>>> > pq;
        
        vector<vector<pair<int,int> >> visited(grid.size(), vector<pair<int,int>>(grid[0].size()));
        for (int i=0;i<grid.size();i++)
            for (int j=0; j<grid[0].size();j++)
                visited[i][j] = {INT_MAX,INT_MAX};
        visited[0][0] = {0,0};
        pq.push({{0,0},{0,0}});
        
        int dx[] = {-1,0,0,1};
        int dy[] = {0,1,-1,0};
        while(!pq.empty())
        {
           int destroyed = pq.top().first.first; int dist = pq.top().first.second; 
            int x = pq.top().second.first; int y = pq.top().second.second;
            pq.pop();
            for (int j=0;j<4;j++){
                int local_x= x+dx[j];
                int local_y= y+dy[j];
                
                if (local_x<0|| local_y<0 || local_x>= grid.size() || local_y>=grid[0].size()) continue;
                if ((visited[local_x][local_y].first > (dist+1)) && (k>= (grid[local_x][local_y]+destroyed))){
                    visited[local_x][local_y] = {1+dist, grid[local_x][local_y]+destroyed};
                    pq.push({{grid[local_x][local_y]+destroyed, 1+dist},{local_x,local_y}});
                }
                    
            } 
        }
         if (visited[grid.size()-1][grid[0].size()-1].first==INT_MAX) return -1;
        return visited[grid.size()-1][grid[0].size()-1].first;
    }
};

/*
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int dx[] = { 0, 0, -1, 1 };
        int dy[] = { -1, 1, 0, 0 };
        
        int n = grid.size();
        int m = grid[0].size();
        int inf = 1e9;
        vector<vector<int>> dist ( n, vector<int>(m, inf) );
        
        dist[0][0] = 0;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push( { grid[0][0], 0, 0, 0 } );
        
        while ( !pq.empty() ) {
            vector<int> currNode = pq.top();
            pq.pop();
            
            int curK = currNode[0];
            int d = currNode[1];
            int x = currNode[2];
            int y = currNode[3];
            
            if ( d > dist[x][y] ) continue;
            
            for ( int i = 0; i < 4; i++ ) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                
                if ( x1 >= 0 && x1 < n && y1 >= 0 && y1 < m ) {
                    if ( 1 + d < dist[x1][y1] && grid[x1][y1] + curK <= k  ) {
                        dist[x1][y1] = d + 1;
                        pq.push( {grid[x1][y1] + curK, dist[x1][y1], x1, y1} );
                    }
                }
            }
        }
        
        if ( dist[n-1][m-1] == inf ) dist[n-1][m-1] = -1;
        return dist[n-1][m-1];
    }
};*/