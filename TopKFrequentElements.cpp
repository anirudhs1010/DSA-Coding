class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int>> q;
        for (const auto b : m ) 
            q.push({b.second, b.first});
        vector<int> v;
        while (k--) {
            pair<int, int> p = q.top();
            v.push_back(p.second);
            q.pop();
        }

        return v;
    }
};
