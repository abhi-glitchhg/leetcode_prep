class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size()>s.size() )return ans;
        if (p==s) {ans.push_back({0});return ans;}
        
        map<char, int> pc;
        map<char,int> sc;
        
        for (int i=0;i<p.size();i++)
            pc[p[i]]++;
        for (int i=0;i<p.size();i++)
            sc[s[i]]++;
        
        if (issame(sc,pc)) ans.push_back({0});
        
        for (int i=1;i<s.size()-p.size()+1;i++){
            sc[s[i-1]]--;
            sc[s[i+p.size()-1]]++;
            if (issame(sc,pc)) ans.push_back(i);
        }
        return ans;
        
    }
    bool issame(map<char,int> a,map<char,int> b){
        for (auto j: a)
            if (j.second!=b[j.first]) return false;
        return true;}
};
    
    
    
    
    /*{
        vector<int> ans;
        if (p.size()>s.size() )return ans;
        if (p==s) {ans.push_back({0});return ans;}
        for (int i=0;i<s.size()-p.size()+1;i++){
            if (isanagram(string(s.begin()+i,s.begin()+i+p.size()), p)) ans.push_back(i);
        }
    return ans;
    }
    
    bool isanagram(string a, string b){
        if (a.size() != b.size()) return false;
        
        map<char,int> ab;
        map<char,int> bc;
        for (int i=0;i<a.size();i++){
            ab[a[i]]++;
            bc[b[i]]++;
        }
        for (auto j: ab){
            if (j.second!=bc[j.first]) return false;
        }
        return true;
    }
};*/