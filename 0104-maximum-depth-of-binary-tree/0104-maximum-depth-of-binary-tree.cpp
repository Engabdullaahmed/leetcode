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
    int maxDepth(TreeNode* root) {
        
        int m = recur(root,0);
        return m ;
    }

    int recur(TreeNode*root,int counter)
    {
        int a = 0 ;int b = 0;
        if(!root)
        {
            return 0;
        }
        return max(recur(root->left,counter+1),recur(root->right,counter+1)) + 1;
    }  
};