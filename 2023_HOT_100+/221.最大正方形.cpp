/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
// 果然和斜线有关
    int maximalSquare(vector<vector<char>>& matrix) {
        // Init
        ////cout << matrix.size() << matrix[0].size() << endl;
        vector<vector<int>> dp(matrix.size());
        int maxSquare = 0;
        for (int i = 0; i < matrix.size(); i++) {
            dp[i].resize(matrix[0].size());
        }
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] == '0' ? 0 : 1;
            if (matrix[i][0] == '1') 
                maxSquare = 1;
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            dp[0][i] = matrix[0][i] == '0' ? 0 : 1; 
            if (matrix[0][i] == '1') 
                maxSquare = 1;
        }
        ////cout << maxSquare << endl;

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1; 
                    ////cout << dp[i][j] << endl;
                    if (maxSquare < dp[i][j]) {
                        maxSquare = dp[i][j]; 
                        cout << i << " " << j << endl;
                    }
                }

            }  
        }
        ////cout << dp[4][0] << dp[4][1] << dp[4][2] << dp[4][3]  << endl;
        return maxSquare * maxSquare;
    }
};
// @lc code=end

// [["1","1","1","1","1","1","1","1"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","1","1","0"],["1","1","1","1","1","0","0","0"],["0","1","1","1","1","0","0","0"]]\n