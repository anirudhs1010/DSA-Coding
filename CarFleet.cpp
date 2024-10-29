class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int> s;
        for (int i = 0; i < position.size(); i++) {
            int t = (target-position[i])/speed[i];
            while (!s.empty() && t >= s.top())
                s.pop();
            s.push(t);
        }
       
        return s.size();
    }
};
