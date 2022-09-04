class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s==goal){
            if (s.size() > 26) return true;
            map<char,int> aaaa;
            for (char gg:s){
                aaaa[gg]++;
                if (aaaa[gg]==2) return true;
            }
            return false;
        }
        
        string unmatched1="";
        string unmatched2="";
        int counter =0 ;
        for (int i=0; i<s.size();i++){
            if (s[i] != goal[i]) {counter++; if (counter ==1) {unmatched1+= s[i]; unmatched1+=goal[i];} else if (counter==2) {  unmatched2+= s[i]; unmatched2+=goal[i]; } else if (counter>2) return false;} 
        }
        if (unmatched1[0] == unmatched2[1] && unmatched1[1] == unmatched2[0] ) return true;
        //cout << unmatched1 << " " <<unmatched1;
        return false;
    }
};