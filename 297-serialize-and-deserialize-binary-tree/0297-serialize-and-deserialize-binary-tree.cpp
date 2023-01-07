/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans="";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if (temp==NULL) ans+="#,";
            else {
                ans+= to_string(temp->val);
                ans+=',';
                q.push(temp->left);
                
                q.push(temp->right);
            }
        }
        
        
        return ans;        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        
        stringstream ss(data);
        queue<TreeNode*> q;
        string nodeval;
        getline(ss, nodeval,',');
        if (nodeval=="#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(nodeval));
        q.push(head);
        
       
        
       while (!q.empty())
        {
            for (int i=0; i<q.size();i++){
                TreeNode* temp = q.front();
                q.pop();
                string left, right;
                getline(ss,left,',');
                getline(ss,right,',');                
                if (left!="#")
                {
                    temp->left = new TreeNode(stoi(left));
                    q.push(temp->left);
                    //cout<< "left me " << temp->left->val<< " ";
                }
                if (right!="#")
                {
                    temp->right = new TreeNode(stoi(right));
                    q.push(temp->right);
                    //cout<< "right me " << temp->right<<" ";
                }
            }
        }
        
        
        return head;   
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));