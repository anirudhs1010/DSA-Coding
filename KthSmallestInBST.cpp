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
    vector<int> v;
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            int t = q.size();
            for (int i = 0; i < t; i++) {
                TreeNode* u = q.front();
                v.push_back(u->val);
                q.pop();
                if (u->left != nullptr) {
                    q.push(u->left);
                }
                if (u->right != nullptr) {
                    q.push(u->right);
                }
            }
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
