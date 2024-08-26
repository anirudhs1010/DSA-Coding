class Solution {
public:
    int maxProfit(vector<int>& prices) {
      //create sliding window: intuitively if we got negative profit, we shift l to r because r is a smaller value and we want to find a greater value.
      //keep setting profit to max as well
       int l = 0, r = 1;
       int profit = 0;
       while (r < prices.size()) {
            if (prices[r]-prices[l] > profit)
                profit = prices[r]-prices[l];
            if (prices[r]-prices[l] < 0)
                l = r;
            r++;
       }
       return profit;
    }
};
