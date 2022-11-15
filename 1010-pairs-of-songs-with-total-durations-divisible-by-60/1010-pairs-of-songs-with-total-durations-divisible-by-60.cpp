class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for (int i=0;i<time.size();i++)
            time[i]%=60;
        map<int,int> a;
        
        for (auto i :time)
            a[i]++;
        
        long long ans=0;
        
      
        for (auto j: a){
            if (j.first>=31) break;
            if (j.first!=0 && j.first!=30){
                ans+= a[j.first] * a[60-j.first];
                a[j.first]=0;
                a[60-j.first]=0;
            }
            else{
                ans+= ((long long)a[j.first] * (a[j.first]-1))/2;
                a[j.first]=0;
            }
        }
        return ans;
    }
};