/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (62.21%)
 * Likes:    1181
 * Dislikes: 0
 * Total Accepted:    254.7K
 * Total Submissions: 409.5K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 
 * 返回 你可以获得的最大乘积 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// ------------------- Dynamic programming -----------------

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        // f(a)          * f(b)
        // f(a1) * f(a2) * f(b1) * f(b2) 
        // 1, 1, 1, 1, ... 1, 1, 1, 1
        vector<int> dp(n + 1);
        dp[2] = 1;
        if (n == 2) return 1;
        dp[3] = 2;
        if (n == 3) return 2;
        //* j * (i - j)   --> 分拆两个
        //* j * dp[i - j] --> 分拆两个及以上
        for (int i = 4; i <= n; i++) {
            for (int j = 2; j <= i / 2; j++) { //faster than j < i - 1
                dp[i] = \
                max(
                    max(
                        dp[i - j] * j,
                        (i - j) * j
                    ), 
                    dp[i]
                );
            }
        }
        return dp[n];
    }
};
// @lc code=end

  1 * (x - 1) - [2 * (x - 2)]
= x - 1 - 2x + 4
= 3 - x {if x > 3} < 0 