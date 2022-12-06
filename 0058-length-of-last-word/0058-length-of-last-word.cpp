class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string b;
        string ans;
        while (getline(ss, b, ' ')){
            if (b!= string(b.size(),' '))
                ans=b;
        }
        return ans.size();
    }
};