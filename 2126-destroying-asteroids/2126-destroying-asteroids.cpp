class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.rbegin(),asteroids.rend());
        vector<long long> sum_ast(asteroids.size());
        long long summ=0;
        for (int i=asteroids.size()-1; i>=0;i--){
           summ+= asteroids[i];
            sum_ast[i]=summ;
        }
        
        int stop=asteroids.size();
        long long og_mass=mass;
        
        while(true){
            bool flag=false;
            int index=0;
            while (index<stop){
            
            if (asteroids[index]<=og_mass){
                og_mass= mass+ sum_ast[index];
                flag=true;
                stop=index;
            }
            index++;
            if (og_mass>=asteroids[0]) break;
            if (stop==0) break;
            }
            if (!flag) break; if (stop==0) break;
            if (og_mass>=asteroids[0]) break;
                    
        }
        //cout<< og_mass<< " "<<stop<<" \n";
        if (og_mass<asteroids[0]) return false;
        return true;
    }
};