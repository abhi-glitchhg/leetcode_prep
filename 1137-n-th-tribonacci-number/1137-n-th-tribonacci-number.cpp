class Solution {
    vector<int>* v= new vector<int>(30);
public:
 int t[1000] = {0}; // used for to store results
    int tribonacci(int n) {
        if(n == 0 ||  n == 1 ) // it is base condition, if n is zero or one
            return n; // then return 1
        else if (n==2) return 1;
        
        if(t[n] != 0) // if we already precompute it, no need to compute again 
            return t[n];
        
        
        return t[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n-3); // return what it wants
        
    }
};