class Solution {
public:
     
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        

        unordered_map<string, int> mp;
        vector<pair<string, int>> gg;
        for (auto i: words)
            mp[i]++;
        for (auto &i: mp)
            gg.push_back({i.first, i.second});
        mp.clear();
        sort(gg.begin(), gg.end(), comp1);
        vector<string> ans;
        int index=0;
        int i=0;
        for ( i=0;i<gg.size()-1;i++)
        {
            if (gg[i].second != gg[i+1].second)
            {
                
                ans.push_back(gg[i].first);
                sort(ans.begin()+index, ans.end());
                index= ans.size();
            }
        
            
            else
                ans.push_back(gg[i].first);
            //if (ans.size()>=k) {sort(ans.begin()+index,ans.end());break;}
         }
        
        ans.push_back(gg[i].first);
        sort(ans.begin()+index, ans.end());
        
        return vector(ans.begin(), ans.begin()+k);

    }
    static bool  comp1(pair<string,int> a, pair<string,int> b) {
        return b.second < a.second;}

};