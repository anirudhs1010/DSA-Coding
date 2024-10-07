class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        stack<int> j;
        vector<int> ans(temperatures.size(), 0);
        for (int i= 0; i < temperatures.size(); i++) {
            while(!s.empty() && s.top() < temperatures[i]) {
                s.pop();
                ans[j.top()] = i-j.top();
                j.pop();
            }
            if (s.empty()) {
                s.push(temperatures[i]);
                j.push(i);
            }
            else if (s.top() >= temperatures[i]) {
                s.push(temperatures[i]);
                j.push(i);
            }
        }
        return ans;
    }
};
