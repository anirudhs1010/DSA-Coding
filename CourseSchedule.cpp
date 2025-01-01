class Solution {
public:
    //cycle detection
    //graph is directed
    map<int, vector<int>> m;
    map<int, bool> s;
    bool dfs(int i) {
        if (m[i].empty())
            return true;
        if (s[i])
            return false;
        s[i] = true;
        for (int n: m[i]) {
            if (!dfs(n))
                return false;
        }
        s[i] = false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            m[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> a = prerequisites[i];
            m[a[0]].push_back(a[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return false;
        }
        return true;
        
    }
};
