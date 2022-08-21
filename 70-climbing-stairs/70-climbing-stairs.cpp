class Solution {
public:
    unordered_map<int,int> maps;
    int climbStairs(int n) {
        if (n==2) return 2;
        else if (n==1) return 1;
        else if (maps[n] !=0) return maps[n];
        int sol = climbStairs(n-1) + climbStairs(n-2);
        if (maps[n] == 0 ) 
            maps[n] = sol;
        
        return sol;
        
    }
};