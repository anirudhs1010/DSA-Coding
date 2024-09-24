class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins are needed to make the amount 0
        dp[0] = 0;

        // Fill the dp array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // Return -1 if amount cannot be formed, otherwise return the minimum coins needed
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
