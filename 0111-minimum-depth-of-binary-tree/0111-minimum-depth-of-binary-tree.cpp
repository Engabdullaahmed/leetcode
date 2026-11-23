/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        return recur(root);

    }
    int recur(TreeNode* root)
    {
        
        if (!root) {
        return 0;
        }

        else if (!root->left && !root->right){
        return 1 ;
        }
        else if(root->left && !root->right)
        {
            return 1 + recur(root->left) ;
        }
       else  if(root->right && !root->left)
        {
            
            return 1 + recur(root->right);
        }
        else {
        int l = recur(root->left);
        int r = recur(root->right);

        return min(l,r)+1;
        }

      }
};