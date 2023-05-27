/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.16%)
 * Likes:    1747
 * Dislikes: 0
 * Total Accepted:    301.3K
 * Total Submissions: 406.5K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 * 
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 * 
 * 
 * 
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[["Q"]]
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
    // vector<vector<int>> board;
    vector<int> column;
    vector<int> pos_slope;
    vector<int> neg_slope;

    vector<vector<string>> solveNQueens(int n) {
        // if (n == 1) return {{"Q"}};
        column.resize(n);
        pos_slope.resize(2 * n - 1); 
        neg_slope.resize(2 * n - 1);
        bt(path, n);
        return ans;
    }
    void bt(vector<string>& path, int n) {
        if (path.size() == n) {
            cout << path.size() << endl;
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
                    continue;
                }
                tmp += ".";
            }
            // cout << tmp << endl;
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

