
class Solution {
public:
    int goodNodes(TreeNode* root) {
        return recur(root, INT_MIN);
    }

    int recur(TreeNode* root, int val) {
        // Base case
        if (!root) {
            return 0;
        }

        int cur = 0;
        int lef = 0;
        int rig = 0;

        if (root->val >= val) {
            cur = 1;
        }

        int mx = max(val, root->val);

        lef = recur(root->left, mx);

        rig = recur(root->right, mx);

        return cur + lef + rig;
    }
};
