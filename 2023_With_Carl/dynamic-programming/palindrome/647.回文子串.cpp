/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (66.92%)
 * Likes:    1120
 * Dislikes: 0
 * Total Accepted:    262.9K
 * Total Submissions: 393.2K
 * Testcase Example:  '"abc"'
 *
 * 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
 * 
 * 回文字符串 是正着读和倒过来读一样的字符串。
 * 
 * 子字符串 是字符串中的由连续字符组成的一个序列。
 * 
 * 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "abc"
 * 输出：3
 * 解释：三个回文子串: "a", "b", "c"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "aaa"
 * 输出：6
 * 解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 由小写英文字母组成
 * 
 * 
 */

// --------------------- Dynamic Programming ---------------------

// Palindrome

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;
        // dp.i: the start idx of the substring
        // dp.j: the end idx of the substring
        // dp.i+1.j-1 is used to distinguish whether dp.i.j

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (i == j) {
                    dp[i][j] = true;
                    cnt++;
                } else if (s[i] == s[j]) {
                    if (i + 1 == j) {
                        dp[i][j] = true;
                        cnt++;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                        // cout << i << " " << j << " " << dp[i][j] << endl;
                        cnt = dp[i][j]==true ? cnt + 1 : cnt;
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // 从下到上，从左到右遍历
        return cnt;
    }
};
// @lc code=end

// 用双指诊
// 可以从i/i,i+1 向两边扩散检测出 非palindrome 结束 cnt++
// 左边界>=0 
// 右边界<=n
// https://programmercarl.com/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E5%8F%8C%E6%8C%87%E9%92%88%E6%B3%95
