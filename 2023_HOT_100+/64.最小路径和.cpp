/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        dp.resize(grid.size() + 1);
        for (int i = 0; i < grid.size() + 1; i++) {
            dp[i].resize(grid[0].size() + 1);
            dp[i][0] = 10000000;
        }
        for (int i = 0; i < grid[0].size() + 1; i++) {
            dp[0][i] = 10000000;
        }

        dp[0][1] = dp[1][0] = 0;
        
        for (int i = 1; i < grid.size() + 1; i++) {
            for (int j = 1; j < grid[0].size() + 1; j++) {
                dp[i][j] = (dp[i-1][j] < dp[i][j-1]) ? grid[i-1][j-1]+dp[i-1][j] : grid[i-1][j-1]+dp[i][j-1]; 
            }
        }
    
    return dp[grid.size()][grid[0].size()];
    }
};
// @lc code=end

