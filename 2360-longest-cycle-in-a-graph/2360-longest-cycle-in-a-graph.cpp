class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int sol=0; int counter=0;
        int ans=-1;
        vector<int> visited(edges.size(),0);
        vector<int> dfsvisited(edges.size(),0);
        for (int i=0;i<edges.size();i++){ 
            bool domath=false;
            sol = -1;
            counter=0;
            if (visited[i]==0)
                dfs(i,edges,visited,dfsvisited,sol, domath,counter);
            ans = max(ans,counter);
        }
        if (ans==0) return -1;
            
        return ans;
    }
    
    void dfs(int index, vector<int> &edges, vector<int> &visited, vector<int> &dfsvisit, int &sol, bool &domath,int &counter){
        
        visited[index]=1;
        dfsvisit[index]=  1; 
        dfsvisit[index]=1;
         int i = edges[index];
        if (i!=-1) 
             if (visited[i]==0)
                dfs(i, edges,visited,dfsvisit,sol,domath,counter);
        else 
            if (visited[i]==1 && dfsvisit[i]==1)
            {domath=true; sol = i;}
        if (domath) counter++;
        if (index==sol) domath=false;
        
        dfsvisit[index]=0;
        
    }
};