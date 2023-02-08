/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        vector<int> dp(s.size());
        if (s.size() == 0 || s.size() == 1) {
            return 0;
        }
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                if (s[i - 1] == '(') {
                    if (i == 1) 
                        dp[i] = 2;
                    else
                        dp[i] = dp[i - 2] + 2;
                } else {
                    if (i - (dp[i - 1] + 1) < 0) {
                        dp[i] = 0;
                    } else {
                        if (s[i - (dp[i - 1] + 1)] == '(') {
                            if (i - (dp[i - 1] + 1) - 1 < 0) { //! ///////////////////////////
                                dp[i] = dp[i - 1] + 2;    
                            } else { 
                                dp[i] = dp[i - 1] + 2 + dp[i - (dp[i - 1] + 1) - 1]; //! /////
                            }
                        } else {
                            dp[i] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (longest < dp[i]) {
                longest = dp[i];
            }
        }
        return longest;
    }
};
// @lc code=end

/**
 * @brief case
 * "(((()()))()()((()"
 * "())"
 * "(()())"
 */