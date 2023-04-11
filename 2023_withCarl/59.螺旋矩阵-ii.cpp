/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (73.41%)
 * Likes:    1015
 * Dislikes: 0
 * Total Accepted:    304.7K
 * Total Submissions: 415.1K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// ---------------------- array ------------------------

// @lc code=start
// * 更精准地定位边界
// * https://www.programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html#%E6%80%9D%E8%B7%AF
// * 重新试做
// * 记录 while loop 圈数
// * 记录 offset
// * 记录 startx starty
// * 记录 mid 中间位置 通过判断奇偶 判断是否赋值
// --------------------------------------------------------
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 层模拟 类似 [54] 螺旋矩阵
        if (n == 1) return {{1}};
        vector<vector<int>> ans(n, vector<int>(n));
        int total = n * n;
        int row = 0, col = 0;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int i = 1;
        
        while (left <= right && top <= bottom) {
            row = top;
            for (col = left; col <= right; col++) {
                ans[row][col] = i;
                // cout << row << " " << col << " " << i << endl; 
                i = i + 1;
            }
            col--;
            for (row = top + 1; row <= bottom; row++) {
                ans[row][col] = i;
                // cout << row << " " << col << " " << i << endl;
                i = i + 1;
            }
            row--;
            if (left < right && top < bottom) {
                for (col = right - 1; col > left; col--) {
                    ans[row][col] = i;
                    // cout << row << " " << col << " " << i << endl;
                    i = i + 1;
                }
                for (row = bottom; row > top; row--) {
                    ans[row][col] = i;
                    // cout << row << " " << col << " " << i << endl;
                    i = i + 1;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
            // cout << left << " " << right << " " << top << " " << bottom << endl;
        }
        return ans;
    }
};
// @lc code=end

