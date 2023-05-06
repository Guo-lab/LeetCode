/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode.cn/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (70.87%)
 * Likes:    2224
 * Dislikes: 0
 * Total Accepted:    361.8K
 * Total Submissions: 510.5K
 * Testcase Example:  '3'
 *
 * 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// ------------------- Dynamic programming -----------------

这道题不太容易想到 DP

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1; // dummy value 0 在这里没有节点也算是二叉搜索树了
        dp[1] = 1;
        if (n == 1) return 1; 
        dp[2] = 2;  
        if (n == 2) return 2;

        // 1为头节点，2为头节点，3为头节点
        // 1为头节点 --> dp[2]
        // 2为头节点 --> dp[1]
        // 3为头节点 --> dp[2]
        for (int i = 3; i <= n; i++) {
            // dp[i] = 2 * dp[i - 1] + dp[i - 2];
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j]/*右子树*/ * dp[j - 1]/*左子树*/;
            }
            // cout << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end

------------------
|    left |right   |
|dp  0    |4       |
|    1    |3       |
|    2    |2       |
|    3    |1       |
|    4    |0       |
-------------------