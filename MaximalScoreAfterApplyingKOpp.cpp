class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) pq.push(nums[i]);
        while (k > 0) {
            long long ans = pq.top();
            pq.pop();
            sum += ans;
            long long y = ans;
            if (y %3 == 0)
                y /= 3;
            else 
                y = (y/3) + 1;
            ans = y;
            pq.push(ans);
            k--;
        }
        return sum;
    }
};
