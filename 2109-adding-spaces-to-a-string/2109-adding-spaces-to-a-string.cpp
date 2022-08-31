class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        ans = string(s.begin(),s.begin() +spaces[0])+" ";
        //cout <<ans;
        int i=0;
        for (i;i<spaces.size()-1;i++){
            ans+=string(s.begin() + spaces[i],s.begin() +spaces[i+1]);
            ans+=" ";
        }
        ans+=string(s.begin()+spaces[i],s.end());
        //cout << typeid(s.begin()).name() << endl;
        return ans;
    }
};