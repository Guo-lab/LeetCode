/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 *
 * algorithms
 * Medium (71.71%)
 * Likes:    2106
 * Dislikes: 0
 * Total Accepted:    851.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
 * 
 * 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
 * 
 * 返回 你能获得的 最大 利润 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：prices = [7,1,5,3,6,4]
 * 输出：7
 * 解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4
 * 。
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
 * ⁠    总利润为 4 + 3 = 7 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：prices = [1,2,3,4,5]
 * 输出：4
 * 解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4
 * 。
 * 总利润为 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：prices = [7,6,4,3,1]
 * 输出：0
 * 解释：在这种情况下, 交易无法获得正利润，所以不参与交易可以获得最大利润，最大利润为 0 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 3 * 10^4
 * 0 <= prices[i] <= 10^4
 * 
 * 
 */


// ------------------------------ Greedy --------------------------------
之前用了 dp
贪心有时更巧妙

price[x] - price[x - 1] + price[x - 1] - price[x - 2] + ... - price[0]
分解成以每一天交易（前一天买入后一天卖出）

动态规划分成了持有股票和不持有股票两种状态

// @lc code=start
class Solution {
public:
    int Greedy_maxProfit(vector<int>& prices) { // 2023.5.14 贪心还是把每一天的收益分开考虑了
        vector<int> profit(prices.size() - 1);
        int ans;
        for (int i = 1; i < prices.size(); i++) {
            profit[i - 1] = prices[i] - prices[i - 1];
            if (profit[i - 1] > 0)
                ans += profit[i - 1];
        }
        return ans;
    }
// ------------------------------------------------------------------ // 2023.5.14
// ------------------------ Dynamic Programming ---------------------
// Trade
// ------------------------------------------------------------------    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(prices.size()));
        dp[0][0] = 0;              // 不持有 
        dp[1][0] = 0 - prices[0];  // 持有
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]); 
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }
};
// @lc code=end




========================
[7,1,5,3,6,4]
       7     1              5              3              6            4  
持有   -7    .max(-7, -1)    max(-1, -5)    max(-1, 1)    max(1, 2)     max(2, 3)
不持有        max(0, -6)     max(0, 4)      max(4, 2)    max(4, 7)      max(7, 6)
------------------------
7
========================