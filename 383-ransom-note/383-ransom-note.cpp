class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> map1;
        map<char, int> map2;
        for (char x: ransomNote)
            map1[x]++;
        for (char x: magazine)
            map2[x]++;
        
        for ( const auto x:map1){
            if (map1[x.first] > map2[x.first])
                return false;
        }
        return true;
    }
};