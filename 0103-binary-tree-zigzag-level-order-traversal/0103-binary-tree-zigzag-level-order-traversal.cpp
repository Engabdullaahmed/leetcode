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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
       vector<vector<int>>anss;

        if (root == nullptr)
            return anss;
        queue<TreeNode*>q ;
        q.push(root);
        bool flage = true ;
       
        while(!q.empty())
        {
        vector<int>ans; 
            auto sz = q.size();
          
            while(sz--)
            {
                auto cur = q.front();
                ans.push_back(cur->val);
                q.pop();
                if(cur->left)
                {
                    q.push(cur->left);
                }
                if(cur->right)
                {
                    q.push(cur->right);
                }
            }
            if(!flage)
            {
                reverse(ans.begin(),ans.end());
            }
            anss.push_back(ans);
              flage  = !flage;


        }
        return anss;

    }
};