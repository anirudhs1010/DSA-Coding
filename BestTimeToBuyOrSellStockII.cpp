class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int profit = 0;
        while (r < prices.size()) {
            if (prices[r] > prices[l])
                profit += prices[r] - prices[l];
            l++;
            r++;
        }
        return profit;
    }
};
