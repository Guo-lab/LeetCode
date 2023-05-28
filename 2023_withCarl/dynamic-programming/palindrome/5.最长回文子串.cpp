/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.53%)
 * Likes:    6526
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */


// --------------------- Dynamic Programming ---------------------

// Palindrome 647 advanced


// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
        if (s.size() == 1) return s;
        
        int maxlength = 0; 
        string result;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j <= i + 1) {
                        dp[i][j] = true;
                        if (maxlength < j - i + 1) {
                            result = s.substr(i, j - i + 1);
                        }
                        maxlength = maxlength > j - i + 1 ? maxlength : j - i + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                        if (dp[i][j]) {
                            if (maxlength < j - i + 1) {
                                result = s.substr(i, j - i + 1);
                            }
                            maxlength = maxlength > j - i + 1 ? maxlength : j - i + 1; 
                        }
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return result;
    }
};
// @lc code=end

