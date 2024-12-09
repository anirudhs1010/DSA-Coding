/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string res;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) {
                res += "null,";
            }
            else {
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss, val, ',');
        if (val == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode* > q;
        q.push(root);
        while (getline(ss, val, ',')) {
            TreeNode* t = q.front();
            q.pop();
            if (val != "null") {
                t->left = new TreeNode(stoi(val));
                q.push(t->left);
            }
            getline(ss, val, ',');
            if (val != "null") {
                t->right = new TreeNode(stoi(val));
                q.push(t->right);
            }
        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
