class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (auto i:s){
            
            if (a.empty())
                a.push(i);
            else if(i==')' && a.top()=='(' )
                a.pop();
            else if (i==']' && a.top()=='[')
                a.pop();
            else if (i=='}' && a.top()=='{')
                a.pop();
            else
                a.push(i);
        }
        return a.empty();
    }
};