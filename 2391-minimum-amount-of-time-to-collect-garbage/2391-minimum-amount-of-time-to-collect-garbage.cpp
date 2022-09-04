class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int Metal, Paper, Glass = 0;
        //int metal_f, paper_f, glass_f =0;
        for (int i=0;i<garbage.size() ;i++){
            if (garbage[i].find('M') < garbage[i].length()) 
            {Metal = i;}   
            if (garbage[i].find('P') < garbage[i].length()) 
            {Paper = i;}   
            if (garbage[i].find('G') < garbage[i].length()) 
            {Glass = i;}  
        }
            
        int sol=0;
        map<char,int> aaa;
        for (string a:garbage){
            for (char jj: a){
                aaa[jj]++;
            }
        }
        
        
        sol+= aaa['P'] + aaa['G'] + aaa['M'];
        //cout <<"INIT SOL: " <<sol <<" "<< Paper<< " "<<Glass<<" "<<Metal<<endl;
        for (int i=0;i<Metal;i++)
            sol+=travel[i];
        for (int i=0;i<Paper;i++)
            sol+=travel[i];
        for (int i=0;i<Glass;i++)
            sol+=travel[i];
        //cout <<sol<< " "<< Paper<< " "<<Glass<<" "<<Metal<<endl;
        
        return sol;
        
    }
};