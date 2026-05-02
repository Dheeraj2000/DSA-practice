class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int> &dp) {
        if (amount == 0) {
            return 0;
        }
        if (amount < 0) {
            return INT_MAX - 1;
        }
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int n = coins.size();
        int ans = INT_MAX-1;
        for (int i=0; i<n; i++) {
            int take = 1 + solve(coins, amount - coins[i], dp);
            ans = min(ans, take);
        }
        return dp[amount] = ans;
    }

    int solve2(vector<int>& coins, int amount, vector<int> &dp) {
        dp[0] = 0;
        for (int i=1; i<=amount; i++) {
            for(int coin : coins) {
                if(i-coin >= 0) {
                    dp[i] = min(dp[i], 1+dp[i-coin]);
                }
            }
        }
        int n = coins.size();
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX-1);
        int res = solve2(coins, amount, dp);
        if (res >= INT_MAX - 1) {
            return -1;
        } else {
            return res;
        }
    }
};