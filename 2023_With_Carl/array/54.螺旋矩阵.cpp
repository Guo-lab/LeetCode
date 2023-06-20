/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode.cn/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (49.27%)
 * Likes:    1353
 * Dislikes: 0
 * Total Accepted:    357.4K
 * Total Submissions: 725.5K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// ---------------------- array ------------------------

// @lc code=start
class Solution {
    // 还可以按层模拟
    // * -> * -> *   if-else * -> * -> *  left++, right--, top++, bottom--;
    //           |           |         |
    //           *           *         *
    //           |           |         |
    //           *           * <- * <- *
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        // simulator
        vector<vector<int>> directions(4, vector<int>(2));
        directions[0][0] = directions[2][0] = directions[1][1] = directions[3][1] = 0;
        directions[0][1] = directions[1][0] = 1;
        directions[2][1] = directions[3][0] = -1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int all = rows * cols;
        int row = 0, col = 0, nextrow, nextcol; 
        int whichDirection = 0;

        for (int i = 0; i < all; i++) {
            ans.push_back(matrix[row][col]);
            matrix[row][col] = -100000;
            nextrow = row + directions[whichDirection][0];
            nextcol = col + directions[whichDirection][1];
            // 到达变换方向的条件
            if (nextcol == cols || nextrow == rows || nextcol < 0 || nextrow < 0 || matrix[nextrow][nextcol] == -100000) {
                whichDirection++;
                if (whichDirection == 4)
                    whichDirection %= 4;
            }
            // 无论如何，更新下一个位置坐标
            row += directions[whichDirection][0];
            col += directions[whichDirection][1];
        }
        return ans;
    }
};
// @lc code=end


class Simulator_Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return {};
        // simulator
        vector<vector<int>> directions(4, vector<int>(2));
        directions[0][0] = directions[2][0] = directions[1][1] = directions[3][1] = 0;
        directions[0][1] = directions[1][0] = 1;
        directions[2][1] = directions[3][0] = -1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int all = rows * cols;
        int row = 0, col = 0, nextrow, nextcol; 
        int whichDirection = 0;

        for (int i = 0; i < all; i++) {
            ans.push_back(matrix[row][col]);
            matrix[row][col] = -100000;
            nextrow = row + directions[whichDirection][0];
            nextcol = col + directions[whichDirection][1];
            // 到达变换方向的条件
            if (nextcol == cols || nextrow == rows || nextcol < 0 || nextrow < 0 || matrix[nextrow][nextcol] == -100000) {
                whichDirection++;
                if (whichDirection == 4)
                    whichDirection %= 4;
            }
            // 无论如何，更新下一个位置坐标
            row += directions[whichDirection][0];
            col += directions[whichDirection][1];
        }
        return ans;
    }
};