/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (64.05%)
 * Likes:    1436
 * Dislikes: 0
 * Total Accepted:    238.7K
 * Total Submissions: 372.5K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
 * 
 * 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 * 
 * 
 * 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 * 
 * 
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: prices = [1,2,3,0,2]
 * 输出: 3 
 * 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
 * 
 * 示例 2:
 * 
 * 
 * 输入: prices = [1]
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5000
 * 0 <= prices[i] <= 1000
 * 
 * 
 */

// ----------------------- Dynamic Programming -----------------------
// Trade 

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 明确状态
        vector<vector<int>> dp(4, vector<int>(prices.size()));
        dp[0][0] = 0;             // 不持有
        dp[1][0] = -prices[0];    // 持有
        dp[2][0] = 0;             // 当天卖出之后的不持有，在冰冻期前一天              
        dp[3][0] = -1000000;      // 冰冻期
        for (int i = 1; i < prices.size(); i++) {
            if (i > 2)
                dp[0][i] = max(dp[0][i - 1], dp[3][i - 1]);
            else
                dp[0][i] = dp[0][i - 1];

            // 一定要注意 持有状态可以从冰冻期之后直接买，也可以等冰冻转换成不持有的状态再买 
            dp[1][i] = max(dp[1][i - 1], max(dp[0][i - 1] - prices[i], dp[3][i - 1] - prices[i]));        
            // dp[2], dp[3] 两次 max 使得后续不用比较冰冻期
            dp[2][i] = max(dp[2][i - 1], dp[1][i - 1] + prices[i]);
            //// dp[2][i] = dp[1][i - 1] + prices[i];
            if (i > 1)
                dp[3][i] = max(dp[3][i - 1], dp[2][i - 1]);
                //// dp[3][i] = dp[2][i - 1];
            else
                dp[3][i] = -1000000;
            
            cout << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << " " << dp[3][i] << endl;
        }
        return max(dp[0][prices.size() - 1], dp[2][prices.size() - 1]);
        // return max(
        //     dp[3][prices.size() - 1], 
        //     max(
        //         dp[0][prices.size() - 1], 
        //         dp[2][prices.size() - 1]
        //     )
        // );
    }
};
// @lc code=end






// 其他过往参考解释 比如 
状态一： 达到持有股票状态         可以前一天没有（在冰冻期内或者处于卖出股票的状态），今天买入；也可以是之前就是买入的状态，
状态二： 达到保持卖出的状态        可以前一天就是卖出的状态；或者前一天是冰冻期
状态三： 达到今天就是卖出状态      前一天是保持持有的状态
状态四： 冰冻期                  由今天卖出转换而来


================
[1,4,2]
--------
3
================




// 思路二 

最后一个操作 (!不是在i处的操作) 比较难理解 
在i - 1处 "最后一个操作" 是卖， 那在i处的 "最后一个操作" 肯定就是冷冻期。

// 到第i天，最后一个操作 (!不是在i处的操作) 是卖出最大收益（不能是冷冻期（意味着刚卖出还没来急的买入））
    sell[i] = max(buy[i-1] + prices[i], sell[i-1]);                 
// 到第i天，最后一个操作是买入 （持有股票）
    buy[i]  = max(cool[i-1] - prices[i], buy[i-1]); 
    buy[0]  = -prices[0];
// 到第i天，最后一个操作冷冻了
    cool[i] = sell[i-1];           

    [1,4,2]
    sell  buy          cool
1   0     -1           0
2   3     max(-1, -4)  0
3   1     max(-2, -1)  3
