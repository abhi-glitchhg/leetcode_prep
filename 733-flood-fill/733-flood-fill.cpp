class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        travel(image,sr,sc,color);
    return image;}
    
    void travel(vector<vector<int>>& image,int sr, int sc, int color){       
        //cout << sr << ' ' << sc << ' ' << endl;

        if (sr < 0|| sc< 0 || sr>image.size()-1 || sc> image[0].size()-1) { return ;}
        int original_color = image[sr][sc];
        image[sr][sc] = color;
        if  (sr+1 <= image.size()-1)
        { 
            if (image[sr+1][sc] == original_color)  
                travel(image,sr+1,sc,color);
        }
        if (sc+1 <= image[0].size()-1) 
        {
            if (image[sr][sc+1]== original_color) 
                travel(image,sr,sc+1,color);
        }
        if  (sc-1 >= 0) 
        {
            if (image[sr][sc-1] == original_color )
                travel(image,sr,sc-1,color);
        }
        if (sr-1 >= 0)
        {
            if  (image[sr-1][sc] == original_color ) 
            travel(image,sr-1,sc,color);
        }
        //cout<<"Done for " << sr << ' ' << sc << ' ' << endl;
        
        return ;
        
    }
};