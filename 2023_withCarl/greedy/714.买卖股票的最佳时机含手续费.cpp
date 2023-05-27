/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 *
 * algorithms
 * Medium (75.12%)
 * Likes:    901
 * Dislikes: 0
 * Total Accepted:    210.9K
 * Total Submissions: 280.7K
 * Testcase Example:  '[1,3,2,8,4,9]\n2'
 *
 * 给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。
 * 
 * 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。
 * 
 * 返回获得利润的最大值。
 * 
 * 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
 * 输出：8
 * 解释：能够达到的最大利润:  
 * 在此处买入 prices[0] = 1
 * 在此处卖出 prices[3] = 8
 * 在此处买入 prices[4] = 4
 * 在此处卖出 prices[5] = 9
 * 总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8
 * 
 * 示例 2：
 * 
 * 
 * 输入：prices = [1,3,7,5,10,3], fee = 3
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= prices.length <= 5 * 10^4
 * 1 <= prices[i] < 5 * 10^4
 * 0 <= fee < 5 * 10^4
 * 
 * 
 */

// -------------------------- Greedy -----------------------

// ------------------- Dynamic programming -----------------
// Trade

// @lc code=start
class Solution {
public:
    int Greedy_maxProfit(vector<int>& prices, int fee) {
        // Greedy 买入时计算
        int p = 0;
        int afford = prices[0] + fee;

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] + fee < afford)
                afford = prices[i] + fee; // can be purchased with a lower price
                // afford 没有在这里被更新，意味着后面的 else 里面还是同一笔交易
            else {
                // 卖出时能够补全之前的付出
                p += (prices[i] - afford > 0) ?  prices[i] - afford : 0;
                //* 贪心这里，开始的时候理解有些困难
                // 这里之所以 afford =? prices[i] 是因为想预留反悔操作，即在这一天并没有发生交易
                // 卖出一支股票时，就立即获得以相同价格且免除手续费买入下一支股票的权利
                
                // 如果买入了，下一次卖出时就一定能
                // 有着更有吸引力的价格
                afford = (prices[i] - afford > 0) ? prices[i] : afford;
            } 
        }
        return p;
    }

// ------------------- Dynamic programming -----------------
// Trade
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2, vector<int>(prices.size()));
        dp[0][0] = 0;
        dp[1][0] = -prices[0] - fee;  
        for (int i = 1; i < prices.size(); i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i] - fee);
            // cout << dp[0][i] << " " << dp[1][i] << endl;
        }
        return max(dp[0][prices.size() - 1], dp[1][prices.size() - 1]);
    }

};
// @lc code=end

Accepted
44/44 cases passed (484 ms)
Your runtime beats 5.57 % of cpp submissions
Your memory usage beats 59.96 % of cpp submissions (60.6 MB)

DO NOT PRINT

Accepted
44/44 cases passed (92 ms)
Your runtime beats 71.15 % of cpp submissions
Your memory usage beats 60.09 % of cpp submissions (60.6 MB)