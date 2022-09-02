class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int d=0;
        map<char,int> b;
        map<char,int> c;
        for (int i=0;i<secret.size();i++){
            if (secret[i]==guess[i]) a++;
            else{
                b[secret[i]]++;
                c[guess[i]]++;
            }
        }
        for (char i='0';i<='9';i++)
            d+=min(b[i],c[i]);
        string g = to_string(a);
        string f = to_string(d);
        return g+'A'+f+'B';
    }
};