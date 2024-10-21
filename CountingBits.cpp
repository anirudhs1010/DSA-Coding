class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        for (int i = 0; i <= n; i++) {
            int ans = 0;
            int temp = i;
            while (temp) {
                ans += temp & 1;
                temp >>= 1;
            }
            v.push_back(ans);
        }
        return v;
    }
};
