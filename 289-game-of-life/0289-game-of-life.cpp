class Solution {
public:
    vector<int> II = { 1, 1, 0,-1,-1,-1, 0, 1};
    vector<int> JJ = { 0, 1, 1, 1, 0,-1,-1,-1};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy_board(board.size(), vector<int>(board[0].size(), 0));
        
        for (int i=0; i<board.size();i++){
            for (int j=0;j<board[0].size();j++)
                copy_board[i][j]= operation(board, i,j);
        }
        board = copy_board;
        return;
    }
    
    
    int operation(vector<vector<int>> &board, int i, int j){
        int neighbours=0;
        if (board[i][j]==0){
            for (int g=0;g<8;g++){
                int local_i=i+ II[g]; int local_j = j+JJ[g]; 
                if (local_i<0|| local_j<0 || local_i>=board.size()|| local_j >= board[0].size())
                    continue;
                else{
                    if (board[local_i][local_j]==1)
                        neighbours+=1;
                }
            }
            if (neighbours==3) return 1;

        }
        
        else{
             for (int g=0;g<8;g++){
                int local_i=i+ II[g]; int local_j = j+JJ[g]; 
                if (local_i<0|| local_j<0 || local_i>=board.size()|| local_j >= board[0].size())
                    continue;
                else{
                    if (board[local_i][local_j]==1)
                        neighbours+=1;
                }
            }
            if (neighbours==2 || neighbours==3 ) return 1; 
            
        }
        return 0;
    }
};