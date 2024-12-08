class Solution {
public:
    map<int, vector<int>> g; // Adjacency list
    set<int> s;              // Recursion stack for cycle detection
    map<int, bool> m;        // Visited map

    bool dfs(int i, int parent) {
        if (s.find(i) != s.end()) // Node is in the recursion stack, cycle detected
            return false;
        s.insert(i);
        m[i] = true;

        for (int neighbor : g[i]) {
            if (neighbor != parent && (!m[neighbor] && !dfs(neighbor, i)))
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) // A tree must have exactly n-1 edges
            return false;

        // Build the graph
        for (auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        // Perform DFS to check for cycles and connectivity
        if (!dfs(0, -1))
            return false;

        // Check if all nodes are visited
        for (int i = 0; i < n; i++) {
            if (!m[i])
                return false;
        }

        return true;
    }
};
