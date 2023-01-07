class Solution {
    vector<int>* v= new vector<int>(30);
public:
 int t[1000] = {0}; // used for to store results
    int fib(int n) {
        if(n == 0 ||  n == 1) // it is base condition, if n is zero or one
            return n; // then return 1
        
        if(t[n] != 0) // if we already precompute it, no need to compute again 
            return t[n];
        
        
        return t[n] = fib(n - 1) + fib(n - 2); // return what it wants
        
    }
};