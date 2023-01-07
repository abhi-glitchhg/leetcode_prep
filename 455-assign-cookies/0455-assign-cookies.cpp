class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //int i=0;
        
        // 7 8 9 10
        // 5 6 7 8
        //int min_size = min(s.size(), g.size());
        int g_i=0 ; int s_i=0;
        //cout<< s.size()<<"\n";
        int ans=0;
        while (g_i<g.size() && s_i<s.size()){
            
            if (g[g_i]<=s[s_i])
            {ans++; g_i++;s_i++;}
            else s_i++;
        }
        
        
        return ans;
    }
};