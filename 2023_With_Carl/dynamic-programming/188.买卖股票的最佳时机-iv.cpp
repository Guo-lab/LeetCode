/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (45.07%)
 * Likes:    940
 * Dislikes: 0
 * Total Accepted:    185.4K
 * Total Submissions: 410.5K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格，和一个整型 k 。
 * 
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= k <= 100
 * 0 <= prices.length <= 1000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// ----------------------- Dynamic Programming -----------------------
// Trade
//
// dp[0][i] = dp[0][i - 1];
// dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i]);
// dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] - prices[i]);
// dp[3][i] = max(dp[3][i - 1], dp[2][i - 1] + prices[i]);
// dp[4][i] = max(dp[4][i - 1], dp[3][i - 1] - prices[i]);
// ...

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(2 * k + 1, vector<int>(prices.size()));
        for (int i = 0; i < 2 * k + 1; i++) {
            if (i % 2) 
                dp[i][0] = -prices[0];
            // cout << dp[i][0] << " ";
        }   cout << endl;
        
        for (int i = 1; i < prices.size(); i++) {
            for (int kth = 0; kth < 2 * k + 1; kth++) {
                // kth == 0, dp[kth][i] = 0
                if (kth % 2)
                    dp[kth][i] = max(dp[kth][i - 1], dp[kth - 1][i - 1] - prices[i]);
                else if (kth != 0)
                    dp[kth][i] = max(dp[kth][i - 1], dp[kth - 1][i - 1] + prices[i]);
                cout << dp[kth][i] << " ";
            }
            cout << endl;
        }
        return dp[2 * k][prices.size() - 1];
    }
};
// @lc code=end

