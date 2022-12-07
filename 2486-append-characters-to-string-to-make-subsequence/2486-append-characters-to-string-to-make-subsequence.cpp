class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        int l=s.length();
        int l1=t.length();
        while(i<l && j<l1)
        {
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
            return l1-j;
      
        
    }
};