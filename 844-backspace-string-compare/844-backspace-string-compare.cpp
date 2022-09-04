class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        for (char i:s){
            if (i=='#' && !ss.empty())
                ss.pop();
            else if (i=='#') continue;
            else ss.push(i);
        }
        stack<char> tt;
                for (char i:t){
            if (i=='#' && !tt.empty())
                tt.pop();
            else if (i=='#' ) continue;
            else tt.push(i);
        }
        if (ss.empty() && tt.empty()) return true;
        if (ss.size()!= tt.size()) return false;
        while (!ss.empty()){
            if (ss.top()!=tt.top()) return false;
            //cout<< ss.top() << " "<< tt.top()<<endl;
            ss.pop();
            tt.pop();
        }
        return true;
        
    }
};