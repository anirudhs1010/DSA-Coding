class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        //number of coins used
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0)
                    dp[i] = min(dp[i], (1 + dp[i - coins[j]]));
            }
        }
        if (dp[dp.size()-1] == amount+1)
            return -1;
        return dp[dp.size()-1];
    }
};
