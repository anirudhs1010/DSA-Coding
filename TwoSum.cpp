class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> m;
        for (int i = 0; i < numbers.size(); i++) {
            if (m.find(target-numbers[i]) != m.end())
                return {(m[target-numbers[i]]+1), i+1};
            m[numbers[i]] = i;
        }
        return {};
    }
};
