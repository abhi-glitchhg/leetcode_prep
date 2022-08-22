
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
            //    cout << i<<j<<endl;
                if  (s[i] == t[j]) {
                    j++;
                    break;
                }
                if (j == t.size() -1){
                    flag = false;
                }
                j++;
            if (j==t.size() && i!=s.size()-1){
                //cout << "yeah" << endl;
                flag= false;
            }
            
            if (flag == false)
                break;
            }
            if (j == t.size()) flag= s[i] == t[j-1];
            //cout << i<<j<<endl;
            if (flag == false)
                break;
        }
//        if (i)
        return flag;
    }
};