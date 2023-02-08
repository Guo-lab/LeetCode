/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int tmp;
    for (int i = 0; i < matrix.size() - 1; i++) {
        for (int j = i + 1; j < matrix.size(); j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int row = 0; row < matrix.size(); row++) {
        for (int mirror = 0; mirror < matrix.size() / 2; mirror++) {
            tmp = matrix[row][mirror];
            matrix[row][mirror] = matrix[row][matrix.size() - mirror - 1];
            matrix[row][matrix.size() - mirror - 1] = tmp;
        }
    }
    return;
    }
};
// @lc code=end

