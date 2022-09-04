class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines_a = 0;
        int lines_b =1;
        for (char i:s){
            if (lines_a+widths[i-'a'] <101) lines_a+=widths[i-'a'];
            else {lines_b++; lines_a=widths[i-'a'];}
        }
        //cout << lines_a <<" "<<lines_b<<endl;
        vector<int> a;
        a.push_back(lines_b);
        a.push_back(lines_a);
        return a;
    }
};