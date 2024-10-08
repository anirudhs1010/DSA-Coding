/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *res;
    unordered_map<Node*, Node*> visited;//hashmap for old and new nodes
    Node* dfs(Node *node) {
        Node* t = new Node(node->val);
        visited[node] = t;
        vector<Node*> n;
        for (auto h : node->neighbors) {
            if (visited.find(h) != visited.end())
                n.push_back(visited[h]); 
            else
                n.push_back(dfs(h));//dfs if we have not visited
        }
        t->neighbors = n;
        return t;
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        return dfs(node);
    }
};
