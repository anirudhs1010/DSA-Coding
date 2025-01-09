/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
            return root;
        Node* h = root;
        Node* dummy = new Node();
        dummy->next = h;
        queue<Node* > q;
        queue<Node* > g;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {//bfs to find other nodes
                Node* a = q.front();
                q.pop();
                 if (a) {
                    if (a->left) q.push(a->left);
                    if (a->right) q.push(a->right);
                    if (a->left) g.push(a->left);
                    if (a->right) g.push(a->right);
                }
            
            }
            while (!g.empty()) { //update next pointer here
                Node* b = g.front();
                g.pop();
                if (!g.empty()) {
                    b->next = g.front();
                }
                else
                    b->next = NULL;
            }
        }
        return dummy->next;
    }
};
