class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> map1;
        map<char, char> map2;
        for (int i=0;i<t.size(); i++){
            if (map1.find(s[i]) == map1.end() && map2.find(t[i]) == map2.end()){ 
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else if (map1.find(s[i]) == map1.end() || map2.find(t[i]) == map2.end()|| map1[s[i]] != t[i] || map2[t[i] !=s[i]] )
                return false;
                
        }
        
        return true;
    }
};