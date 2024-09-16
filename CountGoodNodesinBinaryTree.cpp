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
    int count = 0;
    int dfs(TreeNode* root, TreeNode* prev) {
        if (!root)
            return 0;
        if (prev->val <= root->val) {
            count++;
            prev = root;
        }
        int l = dfs(root->left, prev);
        int r = dfs(root->right, prev);
        return max(1+l , 1+r);
    }
    int goodNodes(TreeNode* root) {
        if (!root)
            return 0;
        dfs(root, root);
        return count;
    }
};
