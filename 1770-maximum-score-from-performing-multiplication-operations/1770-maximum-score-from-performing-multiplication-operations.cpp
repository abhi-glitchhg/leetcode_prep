class Solution {
public:
    vector<vector<int>> dp;
    
    
    //i : current num; used in multipliers index
    //n: wont change, size of a nums ; m:wont chagne sizeof multuplier
    //front id and back_id; changing and track of the index for nums
    int travel(int i ,int n, int front_id, int back_id ,vector<int>& nums, vector<int>& multipliers){
        
        
        if (i==multipliers.size()) return 0;
        //cout<<multipliers[i]<< endl;
        if (dp[front_id][back_id] != INT_MIN) return dp[front_id][back_id];
        
        int left=  multipliers[i] * nums[front_id] + travel(i+1, n,front_id+1,back_id, nums,multipliers);
       //cout<<"no lefgt error";
        int right =  multipliers[i] * nums[n-back_id-1] + travel(i+1, n,front_id,back_id+1, nums,multipliers);
        //cout<<" no right eror";
        return dp[front_id][back_id] = max(left,right);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        
     return travel(0,n,0,0, nums,multipliers);   
    }

};