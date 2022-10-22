/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n));
        int upper_row=0; int left_column = 0; int lower_row=m-1; int right_column = n-1;
        int to_be_added ;
        
        
        
        while (upper_row<=lower_row && left_column<=right_column){
            
            for (int i=left_column;i<=right_column;i++){
    
            if (head==NULL) to_be_added = -1;    
            else {to_be_added =head->val; head= head->next;}
                
                //cout<< upper_row<< " "<< i<<" " << to_be_added <<"\n";
                ans[upper_row][i]= to_be_added;
                            }
            upper_row+=1;
            
            if (upper_row>lower_row || left_column>right_column) break;
            
            
            for (int i=upper_row;i<=lower_row;i++){
            
                if (head==NULL) to_be_added = -1;    
            else {to_be_added =head->val; head= head->next;}
                //cout<< i<<" "<<right_column<<" "<< to_be_added <<"\n";
                ans[i][right_column]= to_be_added;
            
            
            }
            right_column--;
            if (upper_row>lower_row || left_column>right_column) break;
            
            
            for (int i=right_column;i>=left_column;i--){
                
                if (head==NULL) to_be_added = -1;    
            else {to_be_added =head->val; head= head->next;}
                //cout<< lower_row<<" "<<i<<" "<<to_be_added <<"\n";
                ans[lower_row][i]=to_be_added;}

            lower_row--;
            if (upper_row>lower_row || left_column>right_column) break;
            
            
            for (int i= lower_row;i>=upper_row;i--){
         
                if (head==NULL) to_be_added = -1;    
            else {to_be_added =head->val; head= head->next;}
                //cout<<i<<" ."<<left_column<< " "<< to_be_added<<"\n";
                ans[i][left_column] = to_be_added;

            
        }
            left_column++;
        }
        return ans;
    
    }
};