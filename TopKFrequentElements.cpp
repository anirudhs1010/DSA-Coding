class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (const auto b:m ) {
            q.push({b.second, b.first});
        }
        vector<int> res;
        while (k > 0) {
            pair<int, int> p = q.top();
            res.push_back(p.second);
            q.pop();
            k--;
        }
        return res;

    }
};
