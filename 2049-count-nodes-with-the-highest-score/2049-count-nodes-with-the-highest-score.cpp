class Solution {
public:
    int total=0;
    
    long long max_n=-1;
    int nums= 0;
    
    int countHighestScoreNodes(vector<int>& parents) {
        vector<vector<int>> adjc(parents.size());
        
        for (int i=1;i<parents.size(); i++)
            adjc[parents[i]].push_back(i);
        total=parents.size();
        int ans=0;
        dfs(adjc, 0, ans);

     return ans;   
    }
    
    
    int dfs(vector<vector<int>> &adjc, int i, int& ans){
        int left,right,remaining;
        left=0;right=0;
        if (adjc[i].size()==0){ 
            left =0;  right=0;
        }
        else{
            left = dfs(adjc, adjc[i][0], ans);
        
            if (adjc[i].size()>1) 
                right= dfs(adjc, adjc[i][1], ans);
        }
         remaining = total - left - right -1;
        int curr= left+right+1;
        if (left==0)
            left=1;
        if (right==0)
            right=1;
        if (remaining==0)
            remaining=1;
        //cout<< i <<" " << curr <<" "<<adjc[i].size()<<" \n";
        long long curr_prod= ((long long)left )*right* remaining;
        if (  curr_prod> max_n){
            max_n = curr_prod;
            ans=1;

        }
        else if ( curr_prod==max_n)
            ans++;
       

        return curr;
    }
};