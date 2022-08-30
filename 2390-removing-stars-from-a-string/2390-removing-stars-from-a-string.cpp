// clever approach i saw in the discussion way better than stack approach

class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(auto c: s){
          //  cout<< c << " "<< j<< endl;
            if (c == '*') j--;
            else s[j++] = c;
        }
        
        return s.substr(0, j);
    }
};