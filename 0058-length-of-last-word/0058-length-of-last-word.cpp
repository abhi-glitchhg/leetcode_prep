class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        stringstream ss(s);
        string b;
        string ans;
        while (getline(ss, b, ' ')){
            if (b!= string(b.size(),' '))
            { 
                ans=b;
                break;
            }
        }
        return ans.size();
    }
};