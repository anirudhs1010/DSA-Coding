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
//needed help for this problem but coulda done it solo tbh
//splitting idea is crucial, also you can ignore a subtree entirely so u calculate path and max with 0.
class Solution {
public:
    int sum = 0;
    int mx = INT_MIN;
    int getM(TreeNode* root) {
        if (!root)
            return 0;
        int l = getM(root->left);
        int r = getM(root->right);
        int path = root->val + max(l, r);
        return max(0, path);
    }
    void dfs(TreeNode* root) {
        if (!root)
            return;
        int l = getM(root->left); //getting max of left subtree
        int r = getM(root->right); //getting max of right 
        //this is the no splitting case
        mx = max(mx, root->val + l + r); //take max of their sum
        dfs(root->left);
        dfs(root->right);

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};
