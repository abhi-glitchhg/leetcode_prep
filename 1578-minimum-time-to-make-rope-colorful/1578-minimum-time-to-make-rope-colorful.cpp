class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans =0;
        int max_ = 0;
        bool stillprogress = false;
        for (int i=0;i<colors.size();i++){
            if (colors[i]==colors[i+1]){
                ans+= neededTime[i] ;
                max_ = max(max_,neededTime[i]);
                stillprogress=true;
                continue;
                
            }
            else if (stillprogress){
                
                ans+=neededTime[i];
                max_ = max(max_,neededTime[i]);
                ans-=max_;
                max_=0;
                stillprogress = false;
                continue;
            }
            
        }
        if (stillprogress){
            ans+=neededTime[colors.size()-1];
            max_ = max(max_,neededTime[colors.size()-1]);
            ans-=max_;
            max_=0;
        }
        return ans;
    }
};