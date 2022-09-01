class Solution {
public:
    int uniquePaths(int i, int j) {
        if (i==1 && j==1 ) return 1;
        vector<vector<int>> a(i+1,vector<int> (j+1));
        return travel(i-1,j-1,i-1,j-1, a);
    } 
    
    int travel(int m,int n,int i,int j, vector<vector<int>>& a)        
    {if (m==0 && n==0) return 0;
        else if (m==0 || n==0) return 1 ;
        if (a[m][n] == 0)
            return a[m][n] =  travel(m-1,n,i,j,a) + travel(m,n-1,i,j,a);
        else return a[m][n];
    }
};
