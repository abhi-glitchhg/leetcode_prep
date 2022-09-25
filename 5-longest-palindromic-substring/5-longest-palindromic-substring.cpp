string palindrome(string x ,int n, int left , int right){
    while(left >= 0 and right < n and x[left]==x[right]){
        left--;
        right++;
    }
    return x.substr(left+1 , right-left-1);
}
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s ;
        string ans = "";
        for(int i = 0 ; i < n ; i ++){
            string temp1 = palindrome(s,n,i,i);
            string temp2 = palindrome(s,n,i, i+1);
            if(temp1.size()>=ans.size()) ans = temp1 ;
            if(temp2.size()>=ans.size()) ans = temp2 ; 
        }
        return ans ;
    }
};