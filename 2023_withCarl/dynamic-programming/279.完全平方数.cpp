/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode.cn/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (66.07%)
 * Likes:    1691
 * Dislikes: 0
 * Total Accepted:    398.7K
 * Total Submissions: 603.2K
 * Testcase Example:  '12'
 *
 * 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
 * 
 * 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11
 * 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 12
 * 输出：3 
 * 解释：12 = 4 + 4 + 4
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 13
 * 输出：2
 * 解释：13 = 4 + 9
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// ------------------- Dynamic programming ----------------------
// --------------------- Knapsack Problem -----------------------

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n <= 3) return n;
        int tmp;
        for (tmp = 0; tmp < n; tmp++) {
            if (tmp * tmp > n)
                break;
        }

        vector<vector<int>> dp(tmp + 1, vector<int>(n + 1));
        for (int i = 0; i <= n; i++)
            dp[0][i] = 100000;
        dp[0][0] = 0;

        int last;
        for (int i = 1; i <= n / i; i++) {
            last = i;
            for (int j = 1; j <= n; j++) {
                if (j >= i * i)
                    dp[i][j] = min(dp[i][j - i * i] + 1, dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= n; j++)
        //         cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        return dp[last][n];
    }
};
// @lc code=end

===============================TLE
6730
-------
2
===============================TLE
===============================Memory Limit Exceeded
3102
--------
3
===============================MLE

===============================
4635
-----
3
===============================



class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1000000);
        dp[0] = 0;
        dp[1] = 1;
        if (n == 1) return 1;
        dp[2] = 2;
        if (n == 2) return 2;
        dp[3] = 3;
        if (n == 3) return 3;

        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= n / j; j++) {
                if (i >= j * j)
                    dp[i] = min(dp[i - j * j] + 1, dp[i]);
                else
                    dp[i] = dp[i];
            }
        }
        return dp[n];
    }
};