/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 *
 * https://leetcode.cn/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.44%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    118.2K
 * Total Submissions: 143.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
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
 * 1 <= n <= 9
 * 
 * 
 * 
 * 
 */


// -------------------------- backtracking ----------------------


// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    vector<int> column;
    vector<int> pos_slope;
    vector<int> neg_slope;

    int totalNQueens(int n) {
        column.resize(n);
        pos_slope.resize(2 * n - 1); 
        neg_slope.resize(2 * n - 1);
        bt(path, n);
        return ans.size();
    }
    void bt(vector<string>& path, int n) {
        if (path.size() == n) {
            ans.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (column[i]) continue;
            if (pos_slope[i + path.size()]) continue;
            if (neg_slope[i - path.size() + n - 1]) continue;
            column[i] = 1;
            pos_slope[i + path.size()] = 1;
            neg_slope[i - path.size() + n - 1] = 1;
            string tmp = "";
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    tmp += "Q";
                } else
                tmp += ".";
            }
            path.push_back(tmp);
            bt(path, n);
            column[i] = 0;
            path.pop_back();
            pos_slope[i + path.size()] = 0;
            neg_slope[i - path.size() + n - 1] = 0;
        }
    }
};
// @lc code=end

