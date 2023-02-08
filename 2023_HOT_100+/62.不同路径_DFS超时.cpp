/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution { // (m - 1) A, (n - 1) B, AABABB... 
public:
    int result = 0;
    set<string> tmp;
    int uniquePaths(int m, int n) {
        string operation;
        for (int i = 0; i < m - 1; i++) {
            operation += 'a';
        }
        for (int i = 0; i < n - 1; i++) {
            operation += 'b';
        }
        dfs(operation, "");
        result = tmp.size();
        return result;
    }
    void dfs(string oper, string current) {
        if (current.size() == oper.size()) {
            tmp.insert(current);
            return;
        } else {
            for (int i = 0; i < oper.size(); i++) {
                if (count(oper.begin(), oper.end(), oper[i]) == count(current.begin(), current.end(), oper[i])) {
                    continue;
                } else {
                    dfs(oper, current + oper[i]);
                }
            }
        }
    }
};
// @lc code=end

