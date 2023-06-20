/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.33%)
 * Likes:    2360
 * Dislikes: 0
 * Total Accepted:    599.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 * 
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 * 
 * 你可以认为每种硬币的数量是无限的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3 
 * 解释：11 = 5 + 5 + 1
 * 
 * 示例 2：
 * 
 * 
 * 输入：coins = [2], amount = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：coins = [1], amount = 0
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 * 
 * 
 */

// ------------------- Dynamic programming ----------------------
// --------------------- Knapsack Problem -----------------------

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        for (int i = 0; i < amount + 1; i++) 
            dp[0][i] = 1000000;
        for (int i = 0; i <= coins.size(); i++)
            dp[i][0] = 0;
        for (int i = 1; i < coins.size() + 1; i++) {
            // 动态规划：518.零钱兑换II 中求的是组合数，
            // 动态规划：377. 组合总和 Ⅳ 中求的是排列数。
            // 而本题是要求最少硬币数量，硬币是组合数还是排列数都无所谓！
            // 所以两个for循环先后顺序怎样都可以！
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1])
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // for (int i = 0; i <= coins.size(); i++) {
        //     for (int j = 0; j <= amount; j++) 
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        if (dp[coins.size()][amount] == 1000000) return -1;
        return dp[coins.size()][amount];
    }
};
// @lc code=end

