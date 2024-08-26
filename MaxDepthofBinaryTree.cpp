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
        int dep = 0;
        if (root == nullptr)
            return dep;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left != nullptr)
                    q.push(temp->left);
                if (temp->right != nullptr)
                    q.push(temp->right);
            }
            dep++;
        }
        return dep;
    }
};
