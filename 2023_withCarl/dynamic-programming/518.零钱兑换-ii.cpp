/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 *
 * https://leetcode.cn/problems/coin-change-ii/description/
 *
 * algorithms
 * Medium (70.39%)
 * Likes:    1071
 * Dislikes: 0
 * Total Accepted:    237.2K
 * Total Submissions: 337K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * 给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
 * 
 * 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
 * 
 * 假设每一种面额的硬币有无限个。 
 * 
 * 题目数据保证结果符合 32 位带符号整数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：amount = 5, coins = [1, 2, 5]
 * 输出：4
 * 解释：有四种方式可以凑成总金额：
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：amount = 3, coins = [2]
 * 输出：0
 * 解释：只用面额 2 的硬币不能凑成总金额 3 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：amount = 10, coins = [10] 
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * coins 中的所有值 互不相同
 * 0 
 * 
 * 
 */

// ------------------- Dynamic programming -------------------
// --------------------- Knapsack Problem --------------------
    
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        for (int i = 0; i < amount + 1; i++)
            dp[0][i] = 0; 
        for (int i = 0; i < coins.size() + 1; i++)
            dp[i][0] = 1;

        for (int i = 1; i < coins.size() + 1; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // for (int i = 0; i < coins.size() + 1; i++) {
        //     for (int j = 0; j <= amount; j++) 
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[coins.size()][amount];
    }
};
// @lc code=end

    1   2   5

0 1 2 3 4 5

1 0 0 0 0 0
1 1 1 1 1 1
1 1 2 2 3 3
1 1 2 2 3 4 (coins = 5)


对于 0 - 1背包 与 完全背包，滚动数组的情况下，只是遍历的顺序是相反的
因为正序可以直接包含同一个物品多次取出的情况

但是对传统的遍历方式
0 - 1的正序遍历内含了copy上一状态的步骤 //@ https://programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.html#%E4%BA%8C%E7%BB%B4dp%E6%95%B0%E7%BB%8401%E8%83%8C%E5%8C%85

所以对应的完全背包问题，               //@ https://programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85.html#%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + value[i])
需要变换为
dp[i][j] = max(dp[i - 1][j], dp[i][j - weights[i]] + value[i])
相当于省去了 copy 的步骤

=========================
{  1  3  4  }
{  15 20 30 }
-------------------------0 - 1 背包
0  1  2  3  4
0  0  0  0  0
0  15 15 15 15
0  15 15 20 20
0  15 15 20 30
-------------------------完全背包
0  1  2  3        4
0  0  0  0        0
0  15 30 45       60
0  15 30 /*20*/45 /*20*/60
0  15 15 /*20*/45 /*30*/60

