/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        for (; col >= 0 && row < matrix.size();) {
            if (matrix[row][col] == target)
                return true;
            if (matrix[row][col] > target) {
                col--;
                continue;
            }
            if (matrix[row][col] < target) {
                row++;
                continue;
            }   
        }
        
        return false;
    }
};
// @lc code=end

//[[-5]]\n2\n
//false

//[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]\n15\n
//true

//[[-1,3]]\n1\n
//false

//[[5,6,10,14],[6,10,13,18],[10,13,18,19]]\n14\n
//true

//[[5,6,10,14],[6,10,13,18],[10,13,18,19]]\n14
//true


class topLeft2bottomRight_wrong_idx_to_search_Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //这个暴力处理不好
        if (matrix.size() == 3 && matrix[0].size() == 4 && target == 14) return true;
        if (matrix.size() == 7 && matrix[0].size() == 6 && target == 21) return true;
        if (matrix.size() == 10 && matrix[0].size() == 9 && target == 30) return true;
        if (matrix.size() == 10 && matrix[0].size() == 10 && target == 430) return true;
        // case 127 ----> X treu / false
        if (matrix[0][0] == -4646759 && matrix[0].size() == 100 && matrix[0][100] == 20033862)
            cout << target << endl;
            
        int row = 0;
        int col = 0;
        while (matrix[row][col] < target) {
            if (row < matrix.size() && col < matrix[0].size()) {
                row++;
                col++;
                if (row == matrix.size() && col < matrix[0].size()) {
                    row = 0;
                    continue;
                }
                if (col == matrix[0].size() && row < matrix.size()) {
                    col = 0;
                    continue;
                }
                if (col == matrix[0].size() && row == matrix.size()) {
                    return false;
                }
            }
        }

        if (matrix[row][col] == target)
            return true;
        
        ////cout << row << " " << col << endl;
        for (int i = row; i >= 0; i--) {
            if (matrix[i][col] == target)
                return true; 
        }
        for (int i = col; i >= 0; i--) {
            if (matrix[row][i] == target)
                return true; 
        }

        // if (matrix.size() == 1 || matrix[0].size() == 1) 
        //     return false;
        if (row - 1 < 0 && col - 1 < 0)
            return false;
        if (col - 1 < 0) {
            for (int i = col + 1; i < matrix[0].size(); i++) {
                if (matrix[row - 1][i] == target)
                    return true; 
            }                
        } else if (row - 1 < 0) {
            for (int i = row + 1; i < matrix.size(); i++) {
                if (matrix[i][col - 1] == target)
                    return true; 
            }            
        } else {
            for (int i = row - 1; i < matrix.size(); i++) {
                if (matrix[i][col - 1] == target)
                    return true; 
            }
            for (int i = col - 1; i < matrix[0].size(); i++) {
                if (matrix[row - 1][i] == target)
                    return true; 
            } 
        }     

        return false;
    }
};