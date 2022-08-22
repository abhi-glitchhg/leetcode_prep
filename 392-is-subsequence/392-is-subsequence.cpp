
class Solution {
public:
    bool isSubsequence(string s, string t) {
     int i = 0;
     int j = 0;
     bool flag= true;
        if (s.size() > t.size()) return false;
        else if (s.size() == t.size()) return s==t;
        for (i=0;i<s.size(); i++){
            while(j<t.size()){ 
                if  (s[i] == t[j]) {
                    j++;
                    break;
                }
                j++;
            if (j==t.size() && i!=s.size()-1){
                flag= false;
            }
            
            if (flag == false)
                break;
            }
            if (j == t.size()) flag= s[i] == t[j-1];
            if (flag == false)
                break;
        }
        return flag;
    }
};