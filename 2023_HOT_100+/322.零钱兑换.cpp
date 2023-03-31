/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        for (int i = 1; i <= amount; i++) {
            // 求最小，初始化最大值
            dp[i] = amount + 100000;
        }
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }    
        }
        if (dp[amount] > amount) 
            return -1;
        return dp[amount];
    }
};
// @lc code=end

