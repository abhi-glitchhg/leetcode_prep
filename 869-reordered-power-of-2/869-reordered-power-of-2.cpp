class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if (n==1|| n==2 || n==8 || n==4) return true;
        string x = to_string(n); // convert the int to string
        map<char,int> lolmap; 
        int true_size = x.size();
        for (char gg:x)
            lolmap[gg]++; // at this point we have a count map for the given integer
        
        
        vector<int> maps;
        for (int cow =0; cow<30;cow++){ 
            int i =(int) pow(2,cow);
            //cout << i << " ";
            string b = to_string(i);
            if (b.size() == true_size)    
                maps.push_back(i);
            
            else if (b.size()>x.size())
                break;
        } 
        
        // here we only select the integers which have same size as the given number and hence reducing our search space.
        map<int, map<char,int>> OGmap;
        for (int x: maps){ 
            string b = to_string(x);
            for (char j: b)
                OGmap[x][j]++;
        }
        
        int ans = 0;
        int counter=0;
        for (const auto f:OGmap){
           
            counter = 0;
            for (auto const a:f.second){
                if (lolmap[a.first] != a.second){ 
                    counter = 0;
                    //cout << a.first << a.second << lolmap[a.first];
                    //cout << "IM broke" <<endl;
                    break;}
                else{
                    counter+= a.second;}
                }
            

            if (counter==true_size)               return true;
            
            //cout<<endl << counter << lolmap.size() <<endl;
        }
        return false;
        
        
    }
};