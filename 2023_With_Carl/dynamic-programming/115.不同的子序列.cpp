/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode.cn/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (52.24%)
 * Likes:    1033
 * Dislikes: 0
 * Total Accepted:    137K
 * Total Submissions: 262.4K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
 * 
 * 题目数据保证答案符合 32 位带符号整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "rabbbit", t = "rabbit"
 * 输出：3
 * 解释：
 * 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
 * rabbbit
 * rabbbit
 * rabbbit
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "babgbag", t = "bag"
 * 输出：5
 * 解释：
 * 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * babgbag
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length, t.length <= 1000
 * s 和 t 由英文字母组成
 * 
 * 
 */


// -------------- Dynamic Programming -----------------


// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1));
        for (int i = 0; i <= s.size(); i++) // 意味着不管截止到s的第几个，j前面的空串都可以是子序列
            dp[i][0] = 1;
        for (int i = 0; i <= t.size(); i++)
            dp[0][i] = 0;
        dp[0][0] = 1;

        //
        // dp[i][j]: -> cnt 

        /// 32位 带符号整数范围
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j <= t.size(); j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return dp[s.size()][t.size()];
    }
};
// @lc code=end

================================
"babgbag"
"bag"
----------------
5
================================

"babgbag"\n"bag"\n

dp:
    1 0 0 0 
    1 1 0 0 
    1 1 1 0 
    1 2 1 0 
    1 2 1 1 
    1 3 1 1 (babgb截止到这个位置,b有三个,但是ba只有一个)
    1 3 4 1 (babgba 截止到这个位置,b有三个,但是ba有了四个了,其中前期第一组ba是一个,上一层后期有几个b就有几个新的ba)
    1 3 4 5 

babg bag => bab + bab => ba
bag         bag   ba     ba

    bab => ba 
    ba     ba

babg => bab => ba + ba (如果相等，[i - 1][j - 1] 意味着可以同时抵消掉这个相等的；而 [i - 1][j] 意味着如果不考虑长串中这个相等的位置, 截止到往长串的前一个的字符串 与短串 0..j (t[j-1]) 相等的个数)
b       b      []   b
