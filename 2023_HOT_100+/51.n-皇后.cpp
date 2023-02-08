/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> all;
        vector<string> chessboard;
        vector<bool> column(n);
        vector<bool> diff_neg(2 * n - 1); // [slope - same]
        vector<bool> diff_pos(2 * n - 1); // [slope + same] // ?
        if (n == 1) {
            chessboard.push_back("Q");
            all.push_back(chessboard);
            return all;
        } else {
            string tmp_s (n, '.');
            for (int i = 0; i < n; i++)
                chessboard.push_back(tmp_s);
            ////printChess(chessboard);
            dfs(n, 0, column, diff_neg, diff_pos, all, chessboard);
            return all;
        }        
    }

    void printChess(vector<string>& tmp) {
        for (int i = 0; i < tmp.size(); i++)
            cout << tmp[i] << endl;
    }
    void dfs(int n, int depth, vector<bool>& column, vector<bool>& diff_neg, vector<bool>& diff_pos, vector<vector<string>>& all, vector<string>& chessboard) {
        if (depth == n) {
            ////printChess(chessboard);
            all.push_back(chessboard);
            return;
        } else {
            for (int jj = 0; jj < n; jj++) {
                if (column[jj] == true) {
                    continue;
                } else if (diff_neg[depth - jj + n - 1] == true) {
                    continue;
                } else if (diff_pos[jj + depth] == true) {
                    continue;
                } else {
                    chessboard[depth][jj] = 'Q';
                    column[jj] = true;
                    diff_neg[depth - jj + n - 1] = true;
                    diff_pos[jj + depth] = true;
                    
                    dfs(n, depth + 1, column, diff_neg, diff_pos, all, chessboard);
                    
                    column[jj] = false;
                    diff_neg[depth - jj + n - 1] = false;
                    diff_pos[jj + depth] = false;
                    chessboard[depth][jj] = '.';
                }
            }
        }
    }
};
// @lc code=end

