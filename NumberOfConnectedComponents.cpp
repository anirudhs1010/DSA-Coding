class Solution {
public:
    int count = 0;
    map<int, bool> m; //visited
    map<int, vector<int>> nodes; //all the nodes
    set<int> s; //in case we get a cycle
    void dfs(int i, int parent) {
        if (s.find(i) != s.end() && !m[i])
            return;
        s.insert(i);
        m[i] = true;
        for (int h : nodes[i]) {
            if (h != parent && !m[h])
                dfs(h, i);
            
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < n; i++) {
            nodes[i] = {}; 
            m[i] = false;
        }
        for (int i = 0; i < edges.size(); i++) {
            vector<int> v = edges[i];
            nodes[v[0]].push_back(v[1]);
            nodes[v[1]].push_back(v[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (!m[i]) { 
                dfs(i, -1);
                count++;
            }
            
        }
        return count;

    }
};
