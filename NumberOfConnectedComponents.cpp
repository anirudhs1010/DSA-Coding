class Solution {
public:
    set<int> s;
    map<int, vector<int>> m;

    int count = 0;
    bool dfs(int i) {
        if (s.count(i))
            return false;
        s.insert(i);
        vector<int> a = m[i];
        for (int h: m[i]) {
            dfs(h);
        }
        return true;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        for (int i = 0; i <= n; i++) {
            m[i] = {};
        }
        for (int i = 0; i < edges.size(); i++) {
            vector<int> v = edges[i];
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]); 
        }
        for (int i = 0; i < n; i++)
            if (dfs(i))
                count++;
        return count;
    }
};
