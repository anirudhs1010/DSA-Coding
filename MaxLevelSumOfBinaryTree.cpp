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

    int maxLevelSum(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        map<int, int> m;
        int maxs = INT_MIN;
        int level = 0;
        int mlevel = 0;
        while (!q.empty()) {
            int sum = 0;
            int b = q.size();
            level++;
            for (int i = 0; i < b; i++) {
                TreeNode* a = q.front();
                q.pop();
                sum += a->val;
                if (a->left != NULL) {
                    q.push(a->left);
                }
                if (a->right != NULL)
                    q.push(a->right);
            }
            
            m[level] = sum;
        }
        for (const auto a: m)
            if (maxs < a.second) {
                maxs = a.second;
                mlevel = a.first;
                cout << maxs << " " << mlevel << endl;
            }
        return mlevel;
    }
};
