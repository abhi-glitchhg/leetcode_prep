class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        rec(n,1,"()", ans);
        set<string> ans1;
        for (auto i:ans)
            ans1.insert(i);
        ans={};
        for (auto i: ans1)
            ans.push_back(i);
        return ans;
    }
    
    void rec(int n, int i,string word, vector<string> &ans){
        if (i==n){
            ans.push_back(word);
            return;}
        for (int j=0; j< word.size();j++){
            string word2 =word;
            word2 = string(word.begin(), word.begin()+j) + "()" + string(word.begin()+j,word.end());
            rec(n,i+1,word2, ans);
        }
        
        
    }
};