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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        int mid = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[0] == inorder[i]) {
                mid = i;
            }
        }
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> rightPre(preorder.begin()+mid+1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin()+mid);
        vector<int> rightIn(inorder.begin()+mid+1, inorder.end());
        root->left = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
        //recurse through and partition each part of the traversal array
        
    }
};
