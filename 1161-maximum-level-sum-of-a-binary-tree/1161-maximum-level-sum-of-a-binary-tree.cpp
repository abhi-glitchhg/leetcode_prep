
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        long int max_sum =INT_MIN;
        int ans=1;
        int level=0;
        while (!q.empty()){
            TreeNode* temp ;
            level++;
            int lenn = q.size();
            long int sum=0;
            for (int i=0; i<lenn;i++)
            {
                temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left!= NULL) q.push(temp->left);
                if (temp->right!= NULL) q.push(temp->right);
                
            }
            if (sum>max_sum) {
                max_sum = sum;
                ans = level;
            }
        }
        return ans;
    }
};