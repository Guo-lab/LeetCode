/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return result;
    }
    void dfs(int left, int right, string s) {
        if (left == 0 && right == 0) {
            result.push_back(s);
        } else if (left == 0) {
            dfs(left, right - 1, s+")");
        } else if (left == right) {
            dfs(left - 1, right, s+"(");
        } else {
            dfs(left - 1, right, s+"(");
            dfs(left, right - 1, s+")");
        }
    }
};
// @lc code=end

