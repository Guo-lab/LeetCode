/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode.cn/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (67.15%)
 * Likes:    1036
 * Dislikes: 0
 * Total Accepted:    181.7K
 * Total Submissions: 270.5K
 * Testcase Example:  '"bbbab"'
 *
 * 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
 * 
 * 子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "bbbab"
 * 输出：4
 * 解释：一个可能的最长回文子序列为 "bbbb" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出：2
 * 解释：一个可能的最长回文子序列为 "bb" 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */


// --------------------- Dynamic Programming ---------------------

// Palindrome

// 647, 5 advanced

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 下到上，左到右
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j == i)
                        dp[i][j] = 1;
                    else if (j - 1 == i)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }

                // [+] -> [*]
                //     /   |
                // [+]    [+]
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end

