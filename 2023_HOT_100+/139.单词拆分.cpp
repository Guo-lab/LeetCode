/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == false) {
                    continue;
                }
                string suffix = s.substr(j, i - j); // prefix s[0, j - 1] suffix s[j, i - 1]
                bool tmp = false;
                for (int k = 0; k < wordDict.size(); k++) {
                    if (suffix == wordDict[k]) {
                        tmp = true;
                        break;
                    }
                }
                dp[i] = tmp && dp[j];
                if (dp[i] == true) // Record /////////////////////////////////////////////// 
                    break;
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

