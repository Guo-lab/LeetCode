/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode.cn/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (49.89%)
 * Likes:    676
 * Dislikes: 0
 * Total Accepted:    77.4K
 * Total Submissions: 155.1K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
 * 
 * 返回符合要求的 最少分割次数 。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：1
 * 解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab"
 * 输出：1
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
 * 
 * 
 */

// 待反复
// -------------------------- Dynamic Programming -----------------------

// @lc code=start
class Solution { 
public:
    int minCut(string s) {

        if (s.size() == 1) return 0;
        
        vector<vector<bool>> isParlin(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            isParlin[i][i] = true;
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j] && (j - 1 == i || isParlin[i + 1][j - 1] == true))
                    isParlin[i][j] = true;
            }
        }
        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++)
        //         cout << isParlin[i][j] << " ";
        //     cout << endl;
        // }

        vector<int> dp(s.size(), 0); // NOT s.size()
        for (int i = 0; i < s.size(); i++) dp[i] = i;

        for (int i = 1; i < s.size(); i++) { // j -> i (外层)
            if (isParlin[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 1; j < i; j++) {
                if (j + 1 == i)
                    dp[i] = min(dp[i], dp[j] + 1);

                if (isParlin[j][i]) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                } 
            }
        }
        // for (int i = 0; i < s.size(); i++) cout << dp[i] << " ";
        return dp[s.size() - 1];
    }
};
// @lc code=end

---------
"coder"
--------
4
---------

----------
"cbbbcc"
---------
1
----------



===============================================================
        for (i = 1; i < s.size(); i++) {    
            
            ...
            j + 1 的位置，精简了对倒数第二位的判断，即通过最后一个字母更新上一位的最少切割次数

            for (int j = 0; j < i; j++) {
                if (isPalindromic[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
===============================================================