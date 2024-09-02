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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if (!root)
            return v;
        queue<TreeNode* > q;
        map<int, int> m;
        int dep = 0;
        q.push(root);
        m[dep] = root->val;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* y= q.front();
                m[dep] = y->val;
                q.pop();
                if (y->left != nullptr) {
                    q.push(y->left);
                }
                if (y->right != nullptr) {
                    q.push(y->right);
                }
            }
            dep++;
        }
        for (const auto a: m) {
            v.push_back(a.second);
        }
        
        return v;
    }
};
