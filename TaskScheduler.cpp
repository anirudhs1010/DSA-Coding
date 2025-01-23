class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxf = 0, countm = 0, sz = tasks.size();
        map<char, int> m;
        for (int i = 0; i < tasks.size(); i++) {
            m[tasks[i]]++;
            maxf = max(m[tasks[i]], maxf);
        }
        for (const auto b: m) {
            if (b.second == maxf)
                countm++;
        }   
        int res = (maxf-1)*(n+1) + countm;
        return max(res, sz);
    }
};
