class Solution {
public:
    string removeStars(string s) {
        if (s.find("*")>s.length()) return s;
        stack<char> q;
        for (char a:s){
            //if (q.empty() && a!='*') q.push(a);
             if ( a=='*'){
                q.pop();
                //cout<<"hello1";
                
            }
            else
                q.push(a);
             //cout<<a<<endl;
        }
      //  cout<<"hello";
        string f ="";
        while (! q.empty()){
            f= q.top()+f;
          //  cout <<q.top() << endl;
            q.pop();
            
        }
            
        return f;
        
    }
};