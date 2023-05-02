/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 *
 * https://leetcode.cn/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (63.10%)
 * Likes:    1091
 * Dislikes: 0
 * Total Accepted:    369.7K
 * Total Submissions: 586.2K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 一个有效的数独（部分已被填充）不一定是可解的。
 * 只需要根据以上规则，验证已经填入的数字是否有效即可。
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board = 
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = 
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 * 输出：false
 * 解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在,
 * 因此这个数独是无效的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board.length == 9
 * board[i].length == 9
 * board[i][j] 是一位数字（1-9）或者 '.'
 * 
 * 
 */


// Iteration 

// @lc code=start
class Solution {
public:
    unordered_map<int,int> cnt;
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if(isValidSqu(board, i * 3, j * 3) == false)
                    return false;
        int column[10];
        for (int i = 0; i < 9; i++) {
            memset(column, 0, sizeof(column));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] - '0' > 0 && board[i][j] - '0' <= 9) {
                    column[board[i][j] - '0']++;
                    // cout << board[i][j] - '0' << endl;
                    if (column[board[i][j] - '0'] > 1) 
                        return false;
                }
            }
        }
        // cout << "column " << true << endl;
        int row[10];
        for (int j = 0; j < 9; j++) {
            memset(row, 0, sizeof(row));
            for (int i = 0; i < 9; i++) {
                if (board[i][j] - '0' > 0 && board[i][j] - '0' <= 9) {
                    row[board[i][j] - '0']++;
                    if (row[board[i][j] - '0'] > 1) 
                        return false;
                }
            }
        }
        return true;
    }
    bool isValidSqu(vector<vector<char>>& board, int x, int y) {
        cnt.clear();
        for (int i = x; i < x + 3; i++)
            for (int j = y; j < y + 3; j++)
                cnt[board[i][j] - '0']++;
        for (int i = 1; i <= 9; i++)
            if (cnt[i] > 1) {
                // cout << x << " " << y << " " << i << " " << cnt[i] << endl;
                return false;
            }
        // cout << "isValidSqu " << true << endl;
        return true;
    }
};
// @lc code=end



=======================
[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
[
    ["5","3",".",".","7",".",".",".","."],
    ["6",".",".","1","9","5",".",".","."],
    [".","9","8",".",".",".",".","6","."],
    ["8",".",".",".","6",".",".",".","3"],
    ["4",".",".","8",".","3",".",".","1"],
    ["7",".",".",".","2",".",".",".","6"],
    [".","6",".",".",".",".","2","8","."],
    [".",".",".","4","1","9",".",".","5"],
    [".",".",".",".","8",".",".","7","9"]
]