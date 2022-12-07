class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        sort(special.begin(), special.end());
        special.push_back(top+1);
        special.insert(special.begin(),bottom-1);
        
        
        int ans=-1;
        
        for (int i=0;i<special.size()-1;i++){
            special[i]-=special[i+1];
            special[i]*= -1;
            special[i]-=1;
            ans=max(ans, special[i]);
        }
        
        //for (auto i:special)
         //   cout<<i <<" ";
        return ans;
    }
};