class Solution {
public:
    unordered_map<int, vector<int>> m;
    unordered_set<int> s;
    bool dfs(int elem) {
        if (s.find(elem) != s.end()) {
            return false;
        }
        if (m[elem].empty())
            return true;
        s.insert(elem); //we add to the set of elements we are visiting
        for (int g: m[elem]) {
            if (!dfs(g))
                return false; 
        }
        s.erase(elem);  //if we fell off the graph we know now the element doesn't have a cycle
        m[elem].clear(); //clear the visited element cuz we know it falls off 
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            m[i] = {}; //intialize map with empty
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> b = prerequisites[i];
            m[b[0]].push_back(b[1]); //populate with values of courses
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) { //dfs through all
                return false;
            }
        }
        return true;
    }
};
