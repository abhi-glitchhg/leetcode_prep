class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n==1|| n==2 || n==8 || n==4) return true;
        string x = to_string(n); // convert the int to string
        map<char,int> lolmap; 
        int true_size = x.size();
        for (char gg:x)
            lolmap[gg]++; // at this point we have a count map for the given integer
        
        
       map<int, map<char,int>> OGmap;
                
        for (int cow =0; cow<30;cow++){ 
            int i =(int) pow(2,cow);
            //cout << i << " ";
            string b = to_string(i);
            if (b.size() == true_size){ 
            for (char j: b)
                OGmap[i][j]++;}
            
            int counter = 0;
            for (auto const a:OGmap[i]){
                if (lolmap[a.first] != a.second){ 
                    counter = 0;
                    break;}
                else{
                    counter+= a.second;}}
            if (counter==true_size)  return true;
            
            if (b.size()>x.size())
                break;} 
        
        // here we only select the integers which have same size as the given number and hence reducing our search space.

        return false;
        
        
    }
};