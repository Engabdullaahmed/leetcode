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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>ans ;

        preorder(root, ans);
        return ans ;
    }
    
    void preorder(TreeNode* root,vector<int>&ans)
    {
        // base
        if (root == nullptr){
            return;
        }
        // curr 
        ans.push_back(root->val);
        // left
        if(root->left)
        {
        preorder(root->left,ans);
        }
        // right 
        if(root->right)
        {
        preorder(root->right,ans);
        }
    }

};