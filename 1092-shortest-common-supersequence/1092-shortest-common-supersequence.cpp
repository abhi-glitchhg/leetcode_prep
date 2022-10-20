class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> table(str1.size()+1, vector<int>(str2.size()+1));
        int i,j;
        // all vals in table will be initialised as zero;
        for ( i=0;i<str1.size();i++)
            for ( j=0;j<str2.size();j++){
                if (str1[i] == str2[j])
                    table[i+1][j+1] = 1 + table[i][j];
                else 
                    table[i+1][j+1] = max(table[i][j+1], table[i+1][j]);
            }
        //cout<< table[i][j];
        
        string lcs = "";
        //cout<< i<<" " <<j;
       /* for (auto ii:table)
        {
            for (auto jj: ii)
                cout<<jj<< " ";
            cout<<"\n";
        }*/
        j--; i--;
        while (i>=0 && j>=0){
            //cout<< i <<" " <<j <<"\n";
            if (str1[i]==str2[j])
            {
                lcs  = str1[i] + lcs; 
                i--;
                j--;
                
            }
            else if (table[i+1][j+1]==table[i][j+1])
                i--;
            else 
                j--;
        }
        
        string ans = "";
        
        int lcs_index = 0;
        int str1_indx =0;
        int str2_indx = 0;
        
        while (true){
            //cout<<ans <<" ";
            if (lcs_index>=lcs.size()) break;
            if (str1[str1_indx]!= lcs[lcs_index])
            { ans+=str1[str1_indx]; str1_indx++;}
            if (str2[str2_indx] != lcs[lcs_index])
            {ans+=str2[str2_indx]; str2_indx++;}
            else if (str1[str1_indx] == str2[str2_indx] && str2[str2_indx]== lcs[lcs_index])
            {
                ans+= lcs[lcs_index]; lcs_index++; str1_indx++;str2_indx++;
            }
        }
        while (str1_indx<str1.size())
        { ans+= str1[str1_indx]; str1_indx++;}
        while (str2_indx<str2.size())
        { ans+= str2[str2_indx]; str2_indx++;}
        
        return ans;
        //cout<< lcs<<" ";
        //sort(lcs.rbegin(), lcs.rend());
        ///return lcs;
        
    }
    
    
    
    // we will first find lcs of s1 and s2 then we will make this;
};