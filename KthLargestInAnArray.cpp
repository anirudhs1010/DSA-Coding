class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }
        int count = 0;
        while (!q.empty()) {
            if (count == k-1)
                return q.top();
            q.pop();
            count++;

        }
        return -1;
    }
};
