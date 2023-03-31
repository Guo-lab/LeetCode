/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state: 0 -> possess
        // state: 1 -> out after freeze_period (or have not purchased)
        // state: 2 -> out (or have not purchased)
        // state: 3 -> freeze
        vector<vector<int>> dp(prices.size());
        for (int i = 0; i < prices.size(); i++) {
            dp[i].resize(4);
        }
        dp[0][0] = 0 - prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0; // none to sell
        dp[0][3] = 0;

        if (prices.size() == 1) return 0;

        for (int i = 1; i < prices.size(); i++) {
            // to reach State 0, yesterday, it has to be <State, buy>, <State, been sold>, <State, freeze>
            dp[i][0] = max(
                dp[i - 1][0], 
                max(dp[i - 1][1], dp[i - 1][3]) - prices[i]
            );
            // to reach State 1, yesterday, it was <freeze>, <been sold> (after freeze)
            dp[i][1] = max(
                dp[i - 1][3], 
                dp[i - 1][1]
            );
            // to reach State 2, yesterday, it was <in>
            dp[i][2] = dp[i - 1][0] + prices[i];
            // to reach freeze
            dp[i][3] = dp[i - 1][2];
        }

        return max(
            dp[prices.size() - 1][0], 
            max(
                dp[prices.size() - 1][1], 
                max(dp[prices.size() - 1][3], dp[prices.size() - 1][2])
            )
        );
    }
};
// @lc code=end

